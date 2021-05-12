#include <iostream>
#include <vector>
#include <map>
#include "Book.h"
#include "Category.h"
#include "Student.h"
using namespace std;

vector<Book> books;
vector<Category> subjects;
vector<Category> authors;
vector<Student> students;

map<string,int> resolve;

void banner(string s)
{
	system("cls");
	cout<<"\n\n\n\t"<<s<<"\n\n\n";
	for(int i=0; i<12; i++) cout<<"----------";
	cout<<"\n\n";
}

int main()
{
	int book_id, sub_id, author_id, student_id, input1, input2, temp;
	string book_name, sub_name, author_name, student_name, tempIn;
	bool flag1, flag2;
	
	flag1 = true;
	while(flag1)
	{
		banner("Library Management Database");
		cout<<"To go in admin mode Enter 1\nTo go in Student mode Enter 2\nTo exit Enter 3\n\n\n";
		cout<<"Type your coice -- ";
		cin>>input1;
		
		switch(input1)
		{
			case 1:
				flag2 = true;
				while(flag2)
				{
					banner("Admin mode");
					cout<<"To add a subject enter 1\nTo add an author enter 2\nTo add a student enter 3\nTo add a book enter 4\nTo Go back enter 5\n\n";
					cout<<"Type your choice -- ";
					cin>>input2;
					
					switch(input2)
					{
						case 1:
							cout<<"\nEnter the name of subject -- ";
							cin.ignore(); getline(cin,sub_name);
							sub_id = subjects.size();
							resolve.insert({sub_name,sub_id});
							
							subjects.push_back(Category(sub_id,sub_name));
							cout<<"\nSubject entered successfully..\n\nTo continue enter any key -- ";
							cin>>tempIn;
							break;
							
						case 2:
							cout<<"\nEnter the name of author -- ";
							cin.ignore(); getline(cin,author_name);
							author_id = authors.size();
							resolve.insert({author_name,author_id});
							
							authors.push_back(Category(author_id,author_name));
							cout<<"\nAuthor entered successfully..\n\nTo continue enter any key -- ";
							cin>>tempIn;							
							break;
							
						case 3:
							cout<<"\nEnter the name of student -- ";
							cin.ignore(); getline(cin,student_name);
							student_id = students.size();
							resolve.insert({student_name,student_id});
							
							students.push_back(Student(student_id,student_name));
							cout<<"\nStudent entered successfully..\n\nTo continue enter any key -- ";
							cin>>tempIn;							
							break;	
							
						case 4:
							cout<<"\nEnter the name of the book -- ";
							cin.ignore(); getline(cin,book_name);
							cout<<"\nEnter the subject of the book -- ";
							getline(cin,sub_name);
							cout<<"\nEnter the author of the book -- ";
							getline(cin,author_name);
							cout<<"\nHow many copies have been bought -- ";
							cin>>temp;
							book_id = books.size();
							sub_id = resolve[sub_name];
							author_id = resolve[author_name];
							books.push_back(Book(book_id,sub_id,author_id,book_name,sub_name,author_name,temp));
							subjects[sub_id].add(book_id);
							authors[author_id].add(book_id);
							cout<<"\nBook entered successfully..\n\nTo continue enter any key -- ";
							cin>>tempIn;	
							break;
						
						default:
							flag2 = false;																			
					}
					if(!flag2) break;
				}break;
			
			case 2:

				cout<<"\nEnter your name -- ";
				cin.ignore(); getline(cin,student_name);
				student_id = resolve[student_name];
				
				flag2 = true;
				while(flag2)
				{					
					banner("User mode");
					cout<<"To search books by subject enter 1\nTo search books by author enter 2\nTo submit a book enter 3\nTo go back enter 4\n\n";
					cout<<"Type your choice -- ";
					cin>>input2;
					
					switch(input2)
					{
						case 1:
							cout<<"\nEnter subject name -- ";
							cin.ignore(); getline(cin,sub_name);
							sub_id = resolve[sub_name];
							banner("Showing matching results...");	
							subjects[sub_id].display();
							
							cout<<"\nTo borrow any book type its Book id -- ";
							cin>>book_id;
							if(students[student_id].issue(book_id)) cout<<"\nBook issued successfully.. \n\n";
							else cout<<"\nBook can't be issued.. \n\n";
							cout<<"To conitnue enter any key -- ";
							cin>>tempIn;
							break;
							
						case 2:
							cout<<"\nEnter authors name -- ";
							cin.ignore(); getline(cin,author_name);
							author_id = resolve[author_name];
							banner("Showing matching results...");
							authors[author_id].display();
							
							cout<<"\nTo borrow any book type its Book id -- ";
							cin>>book_id;
							if(students[student_id].issue(book_id)) cout<<"\nBook issued successfully.. \n\n";
							else cout<<"\nBook can't be issued.. \n\n";
							cout<<"To conitnue enter any key -- ";
							cin>>tempIn;
							break;
						
						case 3:
							banner("Books you have borrowed...");
							students[student_id].display();
							cout<<"\nTo sumbit any book type its Book id -- ";
							cin>>book_id;
							students[student_id].submit(book_id);
							cout<<"\nbook submitted successfully..\n\nTo continue enter any key -- ";
							cin>>tempIn;
							break;
							
						default:
							flag2 = false;							
					}
					if(!flag2) break;
				}break;
				
				
			default:
				flag1 = false;
				
		}
		if(!flag1) break;
	}
	return 0;
}
