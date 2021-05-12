#ifndef STUDENT_H
#define STUDENT_H

#include "Book.h"
#include <vector>

class Student
{
	int student_id;
	string student_name;
	int no_books;
	list<int> book_ids;
	
	public:
		Student(int,string);
		void display();
		bool issue(int);
		void submit(int);
};

#endif
