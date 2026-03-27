

#include <iostream>
#include <string>
using namespace std;

struct Person {
	int id;
	string name;
	friend ostream& operator << (ostream& os, const Person& p) {
		os << "\t+ Id: " << p.id << endl;
		os << "\t+ Name: " << p.name << endl;
		return os;
	}
	friend istream& operator << (istream& in, Person& p) {
	 cout << "Input person information: " << endl;
	        cout << "\t+ Id: "
			in >> p.id;
		cout << "\t+ name: ";
		in.ignore();
		getline(in, p.name);
		return in;
	}
};

struct Node {
	Person data;
	Node* next;
	Node(Person x) : data(x), next(nullptr) {}

};

struct LinkedList {
	Node* head;
	void Show() {
		if (head == NULL) {
			cout << "Empty list" << endl;
			return;
		}
		Node* item = head;
		while (item != NULL) {
			cout << "Id: " << item->data.id << endl;
			cout << "Name: " << item->data.name <<endl;
			item = item->next;
		}
	}
	void Add(Person x) {
		Node* newNode = new Node(x);
		newNode->next = head;
		head = newNode;
	}
};



int main()
{
	LinkedList list = { NULL };

	do {
		system("cls");
		cout << "--- HUMAN RESOURCE---" << endl;
		cout << "1. View person list " << endl;
		cout << "2.Add a person " << endl;
		cout << "3. Remove a person " << endl;
		cout << "4. Find a person by name " << endl;
		cout << "5. Export to file " << endl;
		cout << "6. Exit " << endl;
		cout << "___________________________ " << endl;
		cout << " Your command: ";


		int cmd;
		cin >> cmd;

		switch (cmd)
		{
		case 1: {
			list.Show();
			break;
		}
		case 2: {
			Person a;
			cin >> a;
			list.Add(a);
			cout << "Add a person successfully!" << endl;
			break;
		}
		case 3: {
			int id;
			cout << "Input ID to remove: ";
			cin >> id;
			
			break;
		}
		case 4: {
			string name;
			cout << "Input name to find: ";
			cin.ignore();
			getline(cin, name);
			bool res = false;
			if (res) {
				cout << "Found person with name" << name << endl;
			}
			else
				cout << "Person isn't existed" << endl;
			break;
		}
		case 5: {
			cout << " Export successfully" << endl;
			break;
		}
		case 6: {
			cout << " Import successfully" << endl;
			break;
		}
		case 0: {
			return 0;
		}

		default:
			cout << "Your command isn't found. Try again..." << endl;
			break;
		}
		cout << "Prese Enter to continue...";
		cin.ignore();
		cin.get();
	} while (true);
	return 0;
}
