// Marvin Leon Program 5

// This file contains the implementation of the graph ADT. The graph ADT
// is implemented using an adjacency list composed of vertices with a pointer
// to a topic object and a node head pointer to an edge list. The edge list
// nodes contain a pointer to a vertex and a next pointer. Public functions
// include a constructor to allocate all verticies and edge list pointers,
// a destructor to deallocate the edge list, load from an external file,
// insert a vertex, insert a one-way connection, display all verticies,
// display all vertices with connections, display the connections of a
// given vertex.

#include "graph.h"

// Constructor
graph::graph(int size)
{
	list_size = size;
	adj_list = new vertex[size];
	flag = new int[size];
	// adj_list[i] is a vertex object
	// every vertext object has a topic and
	// a head pointer to a edge list

	for (int i = 0; i < size; ++i)
	{
		adj_list[i].head = nullptr;
		adj_list[i].topic = nullptr;
		flag[i] = 0;
	}
}

// Destructor
graph::~graph(void)
{
	for (int i = 0; i < list_size; ++i)
	{
		if (adj_list[i].head)
		{
			remove_edge(adj_list[i].head);
		}
		if (adj_list[i].topic)
		{
			delete adj_list[i].topic;
			adj_list[i].topic = nullptr;
		}
	}
	delete[] adj_list;
	delete[] flag;
	list_size = 0;
}

// Private function that recursivey deallocates the edge list.
void graph::remove_edge(node *&head)
{
	if (!head)
		return;
	remove_edge(head->next);
	delete head;
}

// Loads topic data from an external file taken as an argument.
// Inserts the topic into the adjacency list as a vertex.
int graph::load_file(char *file_name)
{
	course_topic a_topic;
	int count = 0;
	char name[50];
	char notes[300];

	ifstream file_in;

	file_in.open(file_name);

	if (file_in)
	{
		file_in.get(name, 50, ':');
		file_in.ignore(100, ':');

		while (file_in && !file_in.eof())
		{
			file_in.get(notes, 300, '\n');
			file_in.ignore(100, '\n');

			a_topic.create_topic(name, notes);
			insert_vertex(a_topic);
			++count;

			file_in.get(name, 50, ':');
			file_in.ignore(100, ':');
		}
		file_in.close();
	}

	return count;
}

// Inserts a vertex (course topic) passed in as an argument, into the
// array of vertices. Before insertion, this function checks for an
// open space. Returns 0 when insertion is unsuccessful
int graph::insert_vertex(course_topic &to_add)
{
	int i = 0;

	while (adj_list[i].topic && i < list_size)
		++i;

	if (i < list_size)
	{
		adj_list[i].topic = new course_topic;
		adj_list[i].topic->copy_topic(to_add);
		return 1;
	}

	return 0;
}

// Inserts an edge node from the char current_vertex argument to char
// to_attach. The connection is one way.
int graph::insert_edge(char *current_vertex, char *to_attach)
{
	int index_current = find_index(current_vertex);
	int index_attach = find_index(to_attach);

	if (index_current < list_size && index_attach < list_size)
	{
		// No connections
		if (!adj_list[index_current].head)
		{
			adj_list[index_current].head = new node;
			adj_list[index_current].head->adjacent = &adj_list[index_attach];
			adj_list[index_current].head->next = nullptr;
		}
		// 1 or more connections (add to the beginning)
		else
		{
			node *temp = adj_list[index_current].head;
			adj_list[index_current].head = new node;
			adj_list[index_current].head->adjacent = &adj_list[index_attach];
			adj_list[index_current].head->next = temp;
		}
	}
	return 0;
}

// Searches the graph for the vertex that matches the given key (name)
// Returns the location (index) of the found vertex
int graph::find_index(char *key)
{
	int i = 0;

	while (i < list_size && adj_list[i].topic && adj_list[i].topic->compare(key))
		++i;

	if (i < list_size)
		return i;

	return 0;
}

// This function iteratively displays all vertices in the graph.
int graph::display_all()
{
	for (int i = 0; i < list_size; ++i)
	{
		if (adj_list[i].topic)
		{
			adj_list[i].topic->display();
		}
	}

	return 1;
}

// Test function to display the edge list for each vertex.
int graph::display_list()
{
	for (int i = 0; i < list_size; ++i)
	{
		if (adj_list[i].topic)
		{
			adj_list[i].topic->display();
			if (adj_list[i].head)
			{
				node *current = adj_list[i].head;
				cout << "\tConnected to: ";
				while (current)
				{
					current->adjacent->topic->display_name();
					current = current->next;
				}
				cout << endl;
			}
			else
			{
				cout << "\t--no connections--.\n";
			}
		}
	}
	return 0;
}

// Displays the adjacent connections for the passed in vertex.
int graph::display_adjacent(char *key)
{
	int i = find_index(key);

	if (adj_list[i].head)
	{
		node *current = adj_list[i].head;
		cout << "\nEdge list: ";
		while (current)
		{
			current->adjacent->topic->display_name();
			current = current->next;
		}
		return 1;
	}

	return 0;
}
