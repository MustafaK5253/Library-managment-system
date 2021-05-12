#include "Category.h"

extern vector<Book> books;

Category::Category(int a, string b)
{
	id = a;
	name = b;
}

void Category::display()
{
	for(vector<int>::iterator i = book_ids.begin(); i != book_ids.end(); i++)
	{
		books[*i].display();
	}
}

void Category::add(int b_id)
{
	book_ids.push_back(b_id);
}
