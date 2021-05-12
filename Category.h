#ifndef CATEGORY_H
#define CATEGORY_H

#include <vector>
#include "Book.h"
using namespace std;

class Category
{
	int id;
	string name;
	vector<int> book_ids;
	
	public:
		Category(int,string);
		void display();
		void add(int);
};

#endif
