
#include <string>
#include <iostream>
#include<fstream>

using namespace std;

struct Author {
	int id;
	string name;
	friend istream& operator>>(istream& in, Author& a) {
		cout << "Author information:" << endl;
		cout << "\t+ Id: ";
		in >> a.id;
		cout << "\t+ Name: ";
		in.ignore();
		getline(in, a.name);
		return in;
	}
};

struct Book {
	int id;
	string name;
	Author author;
	friend ostream& operator<<(ostream& os, const Book& b) {
		os << "Book information:" << endl;
		os << "\t+ Id: " << b.id << endl;
		os << "\+t Name: " << b.name << endl;
		os << "\+t Author name: " << b.author.name << endl;
		return os;
	}
	friend istream& operator>>(istream& in, Book& b) {
		cout << "Book information:" << endl;
		cout<<"\t + Id: ";
		in >> b.id;
		cout << "\t+ Name: ";
		in.ignore();
		getline(in, b.name);
		in >> b.author;
		return in;
	}


};

struct Node {
	Book data;
	Node* next;
	void Create(Book b) {
		data = b;
		next = nullptr;
	}


};

struct LinkedList {
	Node* head;
	void Show() {
		if (head == NULL) {
			cout << "No book available" << endl;
			return;
		}
		Node* item = head;
		while (item != NULL) {
			cout << item->data;
			item = item->next;
		}
	}
	void AddFirst(Node* p) {
		p->next = head;
		head = p;
	}
	bool Remove(int removeId) {
		if (head == NULL) {
			cout << "No book available" << endl;
			return true;
		}
		Node* item = head;
		if (item->data.id == removeId) { // xoa dau danh sach
			head = item->next;
			delete item;
			return true;
		}
		while (item->next != NULL) {
			if (item->next->data.id == removeId) {
				Node* temp = item->next;
				item->next = item->next->next;
				delete temp;
				return true;
			}
			item = item->next;
		}
		return false;
	}
	bool Update(int updateId) {
		if (head == NULL) {
			cout << "No book available" << endl;
			return false;
		}
		Node* item = head;
		while (item != NULL) {
			if (item->data.id == updateId) {
				cin >> item->data;
				return true;
			}
			item = item->next;
		}
		return false;
	}
	Book* Find(string bookName) {
		if (head == NULL) {
			cout << "No book available" << endl;
			return NULL;
		}
		Node* item = head;
		while (item != NULL) {
			if (item-> data.name.find(bookName) != std::string::npos) {
				return &(item->data);
			}
			item = item->next;
		}
		return NULL;
	}
	void Export(string filename) {
		ofstream out(filename, ios::binary);
		if (!out.is_open()) {
			cout << "Cannot open file" << endl;
			return;
		}
		Node* item = head;
		while (item!=NULL){
			out.write(reinterpret_cast<const char*>(&item->data.id), sizeof(item->data.id));

			size_t namelength = item->data.name.size();
			out.write(reinterpret_cast<const char*>(&namelength), sizeof(namelength));
			out.write(item->data.name.c_str(), namelength);

			out.write(reinterpret_cast<const char*>(&item->data.author.id), sizeof(item->data.author.id));

			size_t authornamelength = item->data.author.name.size();
			out.write(reinterpret_cast<const char*>(&authornamelength), sizeof(authornamelength));
			out.write(item->data.author.name.c_str(), authornamelength);
			item = item->next;
		}
		out.close();
	}

};


int main()
{
	LinkedList books = { NULL };

	do {
		system("cls");
		cout << " ------- BOOK MANAGEMENT ------" << endl;
		cout << "1.Show all book" << endl;
		cout << "2.Add a book" << endl;
		cout << "3.Dele a book" << endl;
		cout << "4.Update a book" << endl;
		cout << "5.Find book" << endl;
		cout << "6.Export to file" << endl;
		cout << "7.Import from file" << endl;
		cout << "0.Exit" << endl;
		cout << "----------------------------------------" << endl;
		cout << "Enter your choice: " << endl;
		int choice;
		cin >> choice;
		
		switch (choice)
		{
		case 1: {
			books.Show();
			break;
		}
		case 2: {
			Book b;
			cin >> b;
			Node* newNode = new Node;
			newNode->Create(b);
			books.AddFirst(newNode);
			break;
		}
		case 3: {
			int removeId;
			cout << "Enter book's id to remove: ";
			cin >> removeId;
			bool res = books.Remove(removeId);
			if (res)
				cout << " Removebook successfully" << endl;
			else
				cout << "Invailid bookid" << endl;

			break;
		}
		case 4: {
			int updateId;
			cout << " Enter book's id to update: ";
			cin >> updateId;
			bool res = books.Update(updateId);
			if (res)
				cout << " Update book successfully" << endl;
			else
				cout << " Invalid book id " << endl;
			break;
		}
		case 5: {
			string bookName;
			cout << "Enter book's name to find: ";
			cin.ignore();
			getline(cin, bookName);
			Book* res = books.Find(bookName);
			if (res != NULL) {
				cout << *res;
			}
			else {
				cout << "No book with name: " << bookName << endl;
			}
			break;
		}
		case 6: {
			books.Export("25TH1.dla");
			cout << "Exported successfully" << endl;
			break;
		}
		case 7: {
			break;
		}
		case 0: {
			return 0;
		}
		default: 
			cout << " Invalid choice , try again" << endl;
			break;
		}
		system("pause");
		cout << "Press any key to continue...";

	} while (true);

}

