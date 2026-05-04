

#include <iostream>
#include<string>
#include<fstream>
using namespace std;



struct student {
	int id;
	string name;
	int age;
	string addr;

	friend ostream& operator << (ostream& os, const student& p) {
		os << "\t+ Ma so: " << p.id << endl;
		os << "\t+ Ho ten: " << p.name << endl;
		os << "\t+ Tuoi: " << p.age<< endl;
		os << "\t+ Dia chi: " << p.addr << endl;
		return os;
	}
	friend istream& operator << (istream& in, student& p) {
		cout << "Input student information: " << endl;
		cout << "\t+ Ma so: ";
		in >> p.id;
		cout << "\t+ Ho ten: ";
		in.ignore();
		getline(in, p.name);
		cout << "\t+ Tuoi: ";
		in >> p.age;
		cout << "\t+ Dia chi: ";
		in.ignore();
		getline(in, p.addr);
		return in;
	}
};

struct Node {
	student data;
	Node* next;
	Node(student a) : data(a), next(nullptr) {}

};

struct LinkedList {
	Node* head;
	void Show() {
		if (!head ) {
			cout << "Empty list" << endl;
			return;
		}
		Node* item = head;
		while (item ) {
			cout << "Ma so: " << item->data.id << endl;
			cout << "Ho ten: " << item->data.name<< endl;
			cout << "Tuoi: " << item->data.age << endl;
			cout << "Dia chi: " << item->data.addr << endl;
			item = item->next;
		}
	}
	bool Add(student newItem) {
		Node* newNode = newNode;
		newNode->data = newItem;
		newNode->next = nullptr;
		if (head == nullptr) {
			head = newNode;
		}
		else {
			Node* item = head;
			while (item->next != nullptr) {
				item = item->next;
			}
			item->next = newNode;
		}
	}
	bool  Remove(int x) {
		if (head == NULL) {
			return false;
		}
		Node* item = head;
		if (item->data.id == x) {
			head = item->next;
			delete item;
			return true;
		}
		while (item->next != NULL) {
			if (item->next->data.id == x) {
				Node* temp = item->next;
				item->next = temp->next;
				delete temp;
				return true;
			}
			item = item->next;
		}
	}
	void Find(int id) {
		if (!head) {
			cout << "No student available" << endl;
			return;
		}
		Node* item = head;
		while (item) {
			if (item->data.id== id) {
				cout << item->data;
				return;
			}
			item = item->next;
		}
		cout << "No student found " << endl;
	}
	void Export(string fileName){
	ofstream outFile(fileName, ios::binary);
	if (!outFile) {
		cout << "Error opening file for writing " << endl;
		return;
	}
	Node* item = head;
	while (item) {
		outFile.write(reinterpret_cast<char*>(&item->data), sizeof(student));
		item = item->next;
	}
	outFile.close();
}
	void Import(string fileName) {
		ifstream inFile(fileName, ios::binary);
		if (!inFile) {
			cout << "Error opening file for reading " << endl;
			return;
		}
		Node* item = head;
		while (item != NULL) {
			Node* temp = item;
			item = item->next;
			delete temp;
		}
		student item1;
		while (inFile.read(reinterpret_cast<char*>(&item1), sizeof(student))) {
			Add(item1);
		}
		inFile.close();
	}
};





int main()
{
	LinkedList list = { NULL };

	do {
		system("cls");
		cout << "--- STUDENT RESOURCE---" << endl;
		cout << "1.View student list " << endl;
		cout << "2.Add a student " << endl;
		cout << "3.Remove a student " << endl;
		cout << "4.Find a student by code " << endl;
		cout << "5.Export to file " << endl;
		cout << "6.Exit " << endl;
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
			student a;
			cin >> a.;
			list.Add(a);
			cout << "Add a student successfully!" << endl;
			break;
		}
		case 3: {
			int id;
			cout << "Input ID to remove: ";
			cin >> id;
			bool res = list.Remove(id);
			if (res)
				cout << " Remove a student successfully" << endl;
			else
				cout << "Student isn't found" << endl;
			break;
		}
		case 4: {
			int id;
			cout << "Enter student name: ";
			cin >> id;
			list.Find( id);
			break;
		}
		case 5: {
			list.Export("25TH1.dla");
			cout << " Export successfully" << endl;
			break;
		}
		case 6: {
			list.Import("25TH1.dla");
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
