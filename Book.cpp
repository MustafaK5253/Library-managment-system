#include "Book.h"

Book::Book(int b_id, int s_id, int a_id, string b_name, string s_name, string a_name, int copies)
{
	book_id = b_id;		book_name = b_name;
	sub_id = s_id;		sub_name = s_name;
	author_id = a_id;	author_name = a_name;
	this->copies = copies;
	copies_issued = 0;
}

void Book::display()
{
	cout<<"\n\n"<<book_name<<"\t\t"<<"BOOK ID -- "<<book_id<<"\n\n";
	cout<<"SUB  --\t\t"<<sub_name<<'\n';
	cout<<"AUTHOR --\t"<<author_name<<"\n\n";
	if(copies == copies_issued)		cout<<"OUT OF STOCK !!\n\n\n";
	else 	cout<<"IN STOCK\n\n\n";
	for(int i=0; i<12; i++) cout<<"----------";
	cout<<'\n';
}

bool Book::issue(int stud_id)
{
	if(copies == copies_issued)	return false;
	student_ids.push_back(stud_id);
	copies_issued++;
	return true;
}

void Book::submit(int stud_id)
{
	student_ids.remove(stud_id);
	copies_issued--;
}
