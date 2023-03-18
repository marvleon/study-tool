// Marvin Leon Program

// This file contains the implementation for the topic class ADT.
// Functions include creating a course topic, allocating memory
// decallocating memory (constructor/destructor), displaying
// topic information, and copying topics.

#include "topic.h"

// Constructor
course_topic::course_topic(void)
{
	name = nullptr;
	notes = nullptr;
}

// Destructor
course_topic::~course_topic(void)
{
	if (name)
	{
		delete[] name;
		name = nullptr;
	}

	if (notes)
	{
		delete[] notes;
		notes = nullptr;
	}
}

// This function creates a new topic object by copying in the information
// passed in as char arrays to the current topic object.
// This function deletes any existing information of the current topic object.
int course_topic::create_topic(char *name_src, char *notes_src)
{
	if (name)
	{
		delete[] name;
		name = nullptr;
	}

	if (notes)
	{
		delete[] notes;
		notes = nullptr;
	}

	name = new char[strlen(name_src) + 1];
	strcpy(name, name_src);

	notes = new char[strlen(notes_src) + 1];
	strcpy(notes, notes_src);

	return 1;
}

// Copies topic information from a passed in topic object as the source (src).
// Deletes any existing information of the current topic before being copied.
int course_topic::copy_topic(course_topic &topic_src)
{
	if (name)
	{
		delete[] name;
		name = nullptr;
	}

	if (notes)
	{
		delete[] notes;
		notes = nullptr;
	}

	name = new char[strlen(topic_src.name) + 1];
	strcpy(name, topic_src.name);

	notes = new char[strlen(topic_src.notes) + 1];
	strcpy(notes, topic_src.notes);

	return 1;
}

// Compares the passed in name to the name of the current topic.
// Returns the result of the string compare.
int course_topic::compare(char *compared_name)
{
	return strcmp(name, compared_name);
}

// Displays the name of the current topic.
int course_topic::display_name(void)
{
	if (name)
	{
		cout << "[" << name << "] ";
		return 1;
	}
	return 0;
}

// Displays the name and notes of the current topic.
int course_topic::display(void)
{
	if (name && notes)
	{
		cout << name << endl;
		cout << "\t" << notes << endl;
		return 1;
	}

	return 0;
}
