// Marvin Leon Program

// This file contains the class interface for a course topic ADT.
// A course topic object contains private data types that represent
// the topics name and notes about the topic. The public functions
// include creating, copying, comparing, retrieving topic(s).

#ifndef TOPIC
#define TOPIC

#include <cstring>
#include <cctype>
#include <iostream>
#include <fstream>
using namespace std;

class course_topic
{
public:
	course_topic(void);
	~course_topic(void);
	int create_topic(char *name_src, char *notes_src);
	int copy_topic(course_topic &topic_src);
	int retrieve(char *name, course_topic &found);
	int compare(char *compared_name);
	int display(void);
	int display_name(void);

private:
	char *name;
	char *notes;
};
#endif
