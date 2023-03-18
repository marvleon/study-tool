// Marvin Leon Program 5

// This file contains the class interface for the graph ADT implemented using an adjacency list.
// The graph ADT contains the following private data types: dynamic array of vertices
// representing the adjacency list, and an integer for the size of the list.
// Vertices contain a pointer to a course topic object and a node head pointer to the
// edge list. The edge list node contains a pointer to a vertex (topic object) and
// a next pointer.

#include "topic.h"

// Contains a course topic object pointer, edge, and flag array
struct vertex
{
	course_topic *topic;
	struct node *head;
	// int * flag;
};

// Connects vertices
struct node
{
	// pointer to a vertex
	vertex *adjacent;
	node *next;
};

class graph
{
public:
	graph(int size = 15);									// Constructor
	~graph(void);											// Destructor
	int insert_vertex(course_topic &to_add);				// Inserts the vertex passed in
	int load_file(char *file_name);							// Fills the adjacency list from ext file
	int insert_edge(char *current_vertex, char *to_attach); // Attaches a vertex to another - one direction!
	int display_adjacent(char *key);						// Finds and displays the information of a vertex
	int display_all();										// Test function to display all vertices
	int display_list();										// Traverses through the edge list for each vertex
private:
	void remove_edge(node *&head);
	int find_index(char *key);

	vertex *adj_list;
	int list_size;
	int *flag;
};
