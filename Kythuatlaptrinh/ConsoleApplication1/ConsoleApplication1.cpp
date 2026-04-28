/*1. Xem danh sach;
	2. Them 1 chiec xe;
	3. Tim kiem xe;
	4. Xoa 1 chiec xe;
	5. Luu tap tin;
	6. Doc tap tin;
	7. Cap nhat thong tin xe;
	8. Thong ke xe theo nhan hieu : Toyota: 3, Yamaha : 2;*/



#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "ConsoleApplication1.h"
using namespace std;

struct Vehicle {
    int id;
    string name;
    string type[30]; //kieu xe : sirius, wave 50
    string branch; //chinh nhanh: Toyota, Yamaha
    double price; // gia xe 
    

    friend istream& operator>>(istream& in, Vehicle& v) {
        cout << "Enter ID: "; in >> v.id;
        cin.ignore();
        cout << "Enter name: "; getline(in, v.name);
        cout << "Enter type: "; getline(in, v.type[30]);
        cout << "Enter branch: "; getline(in, v.branch);
        cout << "Enter price: "; in >> v.price;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Vehicle& v) {
        out << "ID: " << v.id
            << "\t+ Name: " << v.name
            << "\t+ Type: " << v.type
            << "\t+ Branch: " << v.branch
            << "\t+ Price: " << v.price << endl;
        return out;
    }
};

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
struct LinkedList {
    Node<T>* head = nullptr;

    void Show();
    void Add(T item);
    void Find(string name);
    void Delete();
    void Save(string fileName);
    void Read(string fileName);
    bool Update(int id);
    void Statistics();
};

template<typename T>
void LinkedList<T>::Show() {
    if (!head) {
        cout << "No data available";
        return;
    }
    Node<T>* item = head;
    while (item) {
        cout << item->data;
        item = item->next;
    }
}

template<typename T>
void LinkedList<T>::Add(T item) {
    Node<T>* newNode = new Node<T>{ item, nullptr };

    if (!head) {
        head = newNode;
        return;
    }

    Node<T>* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

template<typename T>
void LinkedList<T>::Find(string name) {
    Node<T>* item = head;
    while (item) {
        if (item->data.name == name) {
            cout << item->data;
            return;
        }
        item = item->next;
    }
    cout << "Not found";
}

template<typename T>
void LinkedList<T>::Delete() {
    Node<T>* item = head;
    while (item) {
        Node<T>* temp = item;
        item = item->next;
        delete temp;
    }
    head = nullptr;
    cout << "All data deleted!";
}

template<typename T>
void LinkedList<T>::Save(string fileName) {
    ofstream out(fileName);
    if (!out) {
        cout << "Cannot open file!";
        return;
    }

    Node<T>* item = head;
    while (item) {
        out << item->data.id << ","
            << item->data.name << ","
            << item->data.type << ","
            << item->data.price << endl;
        item = item->next;
    }

    out.close();
    cout << "Saved successfully!";
}

template<typename T>
void LinkedList<T>::Read(string fileName) {
    ifstream in(fileName);
    if (!in) {
        cout << "Cannot open file!";
        return;
    }

    Delete();

    T v;
    while (in >> v.id) {
        in.ignore();
        getline(in, v.name, ',');
        getline(in, v.type, ',');
        in >> v.price;
        in.ignore();

        Add(v);
    }

    in.close();
    cout << "Readed successfully!";
}

template<typename T>
bool LinkedList<T>::Update(int id) {
    Node<T>* item = head;
    while (item) {
        if (item->data.id == id) {
            cin >> item->data;
            return true;
        }
        item = item->next;
    }
    return false;
}
template<typename T>
void LinkedList<T>::Statistics() {
    if (head == nullptr) {
        cout << "The list is empty!" << endl;
        return;
    }

    cout << "STATISTICS BY BRAND" << endl;

    Node<T>* item = head;
    while (item != nullptr) {
      
        bool alreadyCounted = false;
        Node<T>* check = head;
        while (check != item) {
            if (check->data.branch == item->data.branch) {
                alreadyCounted = true;
                break;
            }
            check = check->next;
        }

       
        if (!alreadyCounted) {
            int count = 0;
            Node<T>* temp = item;
            while (temp != nullptr) {
                if (temp->data.branch == item->data.branch) {
                    count++;
                }
                temp = temp->next;
            }
            cout << "Branch: " << item->data.branch << " |Quantity: " << count << endl;
        }

        item = item->next; 
    }
}



int main()
{
	LinkedList <Vehicle> vehicle = { NULL };

	do {
		system("cls");
		cout << " ------- VEHICLE MANAGEMENT ------" << endl;
		cout << "1.Show all list car " << endl;
		cout << "2.Add a car" << endl;
		cout << "3.Find a car" << endl;
		cout << "4.Delete a car" << endl;
		cout << "5.Save a car" << endl;
		cout << "6.Read file" << endl;
		cout << "7.Update information car" << endl;
		cout << "8.Statistics by brand" << endl;
		cout << "0.Exit" << endl;
		cout << "----------------------------------------" << endl;
		cout << "Enter your choice: " << endl;
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1: {
			vehicle.Show();
			break;
		}
        case 2:{
           Vehicle a;
            cin >> a;
            vehicle.Add(a);
			break;
		}

		case 3: {
			
			break;
		}

		case 4: {
			
			break;
		}

		case 5: {
			
			break;
		}

		case 6: {
			
			break;
		}

		case 7: {
            int updateId;
            cout << " Enter vehicle to update";
            cin >> updateId;
            bool res = vehicle.Update(updateId);
            if (res)
                cout << " Update vehicle successfully" << updateId << endl;
            else
                cout << "Not found vehicle id " << updateId << endl;
			break;
		}
		case 8: {
            vehicle.Statistics();
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


