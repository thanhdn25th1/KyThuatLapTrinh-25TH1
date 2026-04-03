

#include <iostream>
using namespace std;
struct Author {
	int id;
	string name;
};

struct Book {
	int id;
	string name;
	Author author;
};

struct Node {
	Book data;
	Node* next;
};

struct LinkedList {
	Node* head;
};

int main()
{
	LinkedList books = { NULL };

}

