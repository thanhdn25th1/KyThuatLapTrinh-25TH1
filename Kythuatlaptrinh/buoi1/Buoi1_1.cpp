#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Person {
	int id;
	string name;
	int age;
	string address;
};
void ViewPersonList(vector<Person> p) {
	if (p.size() == 0)
		cout << "An empty list " << endl;
	else {
		for (int i = 0;i < p.size();i++) {
			cout << "Preson" << (i + 1) << endl;
			cout << "\t+ Id: " << p[i].id << endl;
			cout << "\t+ Name: " << p[i].name << endl;
			cout << "\t+ Age: " << p[i].age << endl;
			cout << "\t+ Address: " << p[i].address << endl;
		}
	}
}

void AddPerson(vector<Person>& p) {
	Person a;
	cout << "+ Id: ";
	cin >> a.id;
	cout << "+ Name: ";
	cin.ignore();
	getline(cin, a.name);
	cout << "+ Age: ";
	cin >> a.age;
	cout << "+ Address: ";
	cin.ignore();
	getline(cin, a.address);
	p.push_back(a);
	cout << " ADD a person successfully" << endl;
}

void RemovePerson(vector<Person>& p, int id) {
	for (auto i = p.begin();i!= p.end();i ++ ) {
		if (i->id == id) {
			p.erase(i);
			cout << " Remove a person successfully" << endl;
			return;
		}
	}
	cout << "Not found person with id: " << id << endl;
}
bool FindPerson(vector<Person>p, string name) {
	for (Person i : p) {
		if (i.name == name) {
			return true;
		}
	}
	return false;
}

void ExportToFile(vector<Person>p, string flieName) {
	ofstream file(filename, ios::binary);
	if (!file) {
		cout << "Can't open this file" << endl;
		return;
	}
	for (Person i : p) {
		file.write(reinterpret_cast<const char*>(&i.id), sizeof(i.id));

		size_t namelength = i.name.size();
		file.write(reinterpret_cast<const char*>(&namelength), sizeof(namelength));
		file.write(i.name.c_str(), namelength);
		file.write(reinterpret_cast<const char*>(&i.age), sizeof(i.age));

		size_t addresslength = i.address.size();
		file.write(reinterpret_cast<const char*>(&addresslength), sizeof(addresslength));
		file.write(i.address.c_str(), addresslength);
	}
}

	void ReadFromFile(vector<Person>p, string flieName) {
		ifstream file(filename, ios::binary);
		if (!file) {
			cout << "Can't open this file" << endl;
			return;
		}
		/*while (p.size() > 0)
		{
			p.pop_back();
		}*/
		
		Person i;
		while(file.peek()!=EOF){

			file.read(reinterpret_cast<const char*>(&i.id), sizeof(i.id));

			size_t namelength;
			file.read(reinterpret_cast<const char*>(&namelength), sizeof(namelength));
			i.name.resize(namelength);
			file.read(&i.name[0], namelength);

			file.read(reinterpret_cast<const char*>(&i.age), sizeof(i.age));

			size_t addresslength = i.address.size();
			file.read(reinterpret_cast<const char*>(&addresslength), sizeof(addresslength));
			i.address.resize(addresslength);
			file.read(&i.address[0], addresslength);

			RemovePerson(p, i.id);
			p.push_back(i);
		}



int main() {

	vector<Person> list;
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
			ViewPersonList (list);
			break;
		}
		case 2: {
			AddPerson(list);
			break;
		}
		case 3: {
			int id;
			cout << "Input ID to remove: ";
			cin >> id;
			RemovePerson(list, id);
			break;
		}
		case 4: {
			string name;
			cout << "Input name to find: ";
			cin.ignore();
			getline(cin, name);
			bool res = FindPerson(list, name);
			if (res) {
				cout << "Found person with name" << name << endl;
			}
			else
				cout << "Person isn't existed" << endl;
			break;
		}
		case 5: {
			ExportToFile(list, "25TH1.dla");
			cout << " Export successfully" << endl;
			break;
		}
		case 6: {
			ReadFromFile(list, "25TH1.dla");
			cout << "Import successfully" << endl;
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