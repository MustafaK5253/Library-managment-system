#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <list>
using namespace std;

class Book
{
	int book_id;	string book_name;
	int sub_id;		string sub_name;
	int author_id;	string author_name;
	list<int> student_ids;
	int copies;
	int copies_issued;
	
	public:
		Book(int, int, int, string, string, string, int);
		void display();
		bool issue(int);
		void submit(int);
};

#endif
