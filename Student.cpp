#include "Student.h"

extern vector<Book> books;

Student::Student(int id, string name)
{
	student_id = id;
	student_name = name;
	no_books = 0;
}

void Student::display()
{
	for(list<int>::iterator i = book_ids.begin(); i != book_ids.end(); i++)
	{
		books[*i].display();
	}
}

bool Student::issue(int b_id)
{
	if(no_books == 3) return false;
	if(books[b_id].issue(student_id))
	{
		book_ids.push_back(b_id);
		no_books++;
		return true;
	}
	else return false;
}

void Student::submit(int b_id)
{
	book_ids.remove(b_id);
	books[b_id].submit(student_id);
}
