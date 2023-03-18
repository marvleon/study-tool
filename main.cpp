// Marvin Leon Program 5

// Client implementation to test graph ADT and course topic ADT.
// The user may select options to create a graph, insert vertices,
// insert connections, create topics/vertices, and display them.

#include "topic.h"
#include "graph.h"

void load_prompt(graph &study_guide);
int menu();
void connect_topics(graph &study_guide);
void add_topic(graph &study_guide);
void show_adjacent(graph &study_guide);

int main()
{
	graph study_guide;
	int user_choice{0};

	cout << "\n******** Welcome to client testing ********";
	load_prompt(study_guide);

	do
	{
		user_choice = menu();

		switch (user_choice)
		{
		case 1:
			add_topic(study_guide);
			break;
		case 2:
			connect_topics(study_guide);
			break;
		case 3:
			cout << endl;
			study_guide.display_all();
			break;
		case 4:
			study_guide.display_list();
			break;
		case 5:
			show_adjacent(study_guide);
			break;
		case 0:
			cout << "\nGoodbye.\n";
			break;
		default:
			cout << "\nOops thats not an option.\n";
			break;
		}

	} while (user_choice != 0);
}

// Prompt to load from external file
void load_prompt(graph &study_guide)
{
	char file_name[20];
	char response = 'a';

	cout << "\nNOTE: If any modifications are made to the included data files,\nplease make";
	cout << " sure that the delimiter ':' is used and newlines :).\n";

	cout << "\nWould you like to load in a file? (y or n): ";
	cin >> response;
	cin.ignore(100, '\n');

	if (response == 'y')
	{
		cout << "\nPlease type in a file name below (ex: test.txt)";
		cout << "\nEnter here: ";
		cin.get(file_name, 20, '\n');
		cin.ignore(100, '\n');
		cout << study_guide.load_file(file_name) << " items loaded in.\n";
	}
}

// Menu options for the user
int menu()
{
	int user_choice{0};

	cout << "\nPlease select an option from the menu below:";
	cout << "\n(1) Add a new topic";
	cout << "\n(2) Connect two vertices (one direction)";
	cout << "\n(3) Display all vertices";
	cout << "\n(4) Display all vertices with respective connections";
	cout << "\n(5) Display adjacent vertices for a given vertex";
	cout << "\n(0) QUIT";
	cout << "\nEnter here: ";

	cin >> user_choice;
	cin.ignore(100, '\n');

	while (user_choice > 6)
	{
		cout << "\nOops, thats not an option, please enter a value between 1-5 or 0 to quit";
		cout << "\nEnter here: ";
		cin >> user_choice;
		cin.ignore(100, '\n');
	}

	return user_choice;
}

void connect_topics(graph &study_guide)
{
	char current_vertex[50];
	char to_attach[50];
	char response{'a'};

	do
	{
		cout << "\nEnter a topic for connection.";
		cout << "\nEnter here: ";
		cin.get(current_vertex, 50, '\n');
		cin.ignore(100, '\n');

		cout << "\nEnter a topic to be attached to " << current_vertex;
		cout << "\nEnter here: ";
		cin.get(to_attach, 50, '\n');
		cin.ignore(100, '\n');

		if (study_guide.insert_edge(current_vertex, to_attach))
			cout << "\nOops, that topic couldn't be found";

		cout << "\nAgain? y or n: ";
		cin >> response;
		cin.ignore(100, '\n');
		response = tolower(response);
	} while (response == 'y');
}

void add_topic(graph &study_guide)
{
	course_topic a_topic;
	char name[50];
	char notes[300];

	cout << "Please enter the topic's information, hit enter after each.\n";

	cout << "\tEnter topic name: ";
	cin.get(name, 50, '\n');
	cin.ignore(100, '\n');

	cout << "\tNotes: ";
	cin.get(notes, 300, '\n');
	cin.ignore(100, '\n');

	if (!a_topic.create_topic(name, notes))
		cout << "\nUh Oh something went wrong creating your topic\n";
	if (!study_guide.insert_vertex(a_topic))
		cout << "\nUh Oh something went wrong adding your topic\n";
	else
		cout << endl
			 << name << " was added to the graph.\n";
}

void show_adjacent(graph &study_guide)
{
	char current_vertex[50];
	char response{'a'};

	do
	{
		cout << "\nEnter a topic to show it's connections.";
		cout << "\nEnter here: ";
		cin.get(current_vertex, 50, '\n');
		cin.ignore(100, '\n');

		if (!study_guide.display_adjacent(current_vertex))
			cout << "\nOops, that topic couldn't be found";

		cout << "\nAgain? y or n: ";
		cin >> response;
		cin.ignore(100, '\n');
		response = tolower(response);
	} while (response == 'y');
}
