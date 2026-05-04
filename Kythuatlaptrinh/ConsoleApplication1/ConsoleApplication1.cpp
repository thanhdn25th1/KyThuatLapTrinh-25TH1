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

using namespace std;

struct Username {
    int id;
    string name;
    friend istream& operator>>(istream& in, Username& a) {
        cout << "Username information:" << endl;
        cout << "\t+ Id: ";
        in >> a.id;
        cout << "\t+ Name: ";
        in.ignore();
        getline(in, a.name);
        return in;
    }
};

struct Vehicle {
    int id;
    char type [30];
    string branch;
    double price;
    Username username;
    friend ostream& operator<<(ostream& os, const Vehicle& b) {
        os << "Vehicle information:" << endl;
        os << "\t+ Id: " << b.id << endl;
        os << "\+t Type: " << b.type << endl;
        os << "\+t Branch: " << b.branch << endl;
        os << "\+t Price: " << b.price << endl;
        os << "\+t Username: " << b.username.name << endl;
        return os;
    }
    friend istream& operator>>(istream& in, Vehicle& b) {
        cout << "Vehicle information:" << endl;
        cout << "\t+ Id: ";
        in >> b.id;
        cout << "\t+ Type: ";
        in >> b.type;
        cout << "\t+ Branch: ";
        in.ignore();
        getline(in, b.branch);
        cout << "\t+ Price: ";
        in >> b.price;
        in >> b.username;
        return in;
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
    void Find(string branchName);
    bool Remove(int id);
    void Export(string fileName);
    void Import(string fileName);
    bool Update(int id);
    void Statistics();
};

template<typename T>
void LinkedList<T>::Show() {
    if (!head ) {
        cout << "No vehicle available" << endl;
        return;
    }
    Node<T>* item = head;
    while (item ) {
        cout << item->data;
        item = item->next;
    }
}

template<typename T>
void LinkedList <T>::Add(T item) {
    Node<T>* newNode = new Node<T>;
    newNode->data = item;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node<T>* item = head;
        while (item->next != nullptr) {
            item = item->next;
        }
        item->next = newNode;
    }
}

template<typename T>
void LinkedList <T>::Find(string branchName) {
    if (!head) {
        cout << "No vehicle available" << endl;
        return;
    }
    Node<T>* item = head;
    while (item ) {
        if (item->data.branch == branchName) {
            cout << item->data;
            return;
        }
        item = item->next;
    }
    cout << "No vehicle found " << endl;
}

template<typename T>
bool LinkedList <T>::Remove(int removeId) {
    if (!head) {
        cout << " No vehicle available " << endl;
        return false;
    }
    Node<T>* item = head;
    if (item->data.id == removeId ) {
        head = item->next;
        delete item;
        return true;
    }
    while (item->next != nullptr) {
        if (item->next->data.id == removeId ) {
            Node<T>* temp = item->next;
            item->next = item->next->next;
            delete temp;
            return true;
        } 
        item = item->next;
    }
    return false;
}

template<typename T>
void LinkedList <T>::Export(string fileName) {
    ofstream outFile(fileName, ios::binary);
    if (!outFile) {
        cout << "Error opening file for writing " << endl;
        return;
    }
    Node<T>* item = head;
    while (item ) {
        outFile.write(reinterpret_cast<char*>(&item->data), sizeof(T));
        item = item->next;
    }
    outFile.close();
}

template<typename T>
void LinkedList <T>::Import(string fileName) {
    ifstream inFile(fileName, ios::binary);
    if (!inFile) {
        cout << "Error opening file for reading " << endl;
        return;
    }
    Node<T>* item = head;
    while (item != NULL) {
        Node<T>* temp = item;
        item = item->next;
        delete temp;
    }
    T item1;
    while (inFile.read(reinterpret_cast<char*>(&item1), sizeof(T))) {
        Add(item1);
    }
    inFile.close();
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
    if (!head) {
        cout << "The list is empty! " << endl;
        return ;
    }
   
       cout << "  Statistics by brand: " << endl;
    
    Node<T>* item = head;
    while (item ) {
      
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
            Node<T>* temp = head;
            while (temp ) {
                if (temp->data.branch == item->data.branch) {
                    count++;
                }
                temp = temp->next;
            }
            cout << "Branch: " << item->data.branch << endl;
            cout << "Quantity: " << count << endl;
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
		cout << "4.Remove a car" << endl;
		cout << "5.Export file" << endl;
		cout << "6.Import file" << endl;
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
            Vehicle b;
            cin >> b;          
            vehicle.Add(b);
			break;
		}

		case 3: {
            string name;
            cout << "Enter vehicle name: ";
            cin.ignore();
            getline(cin, name);
            vehicle.Find(name);
			break;
		}

		case 4: {
            int removeId;
            cout << "Enter vehicle to remove: ";
            cin >> removeId;
            bool res = vehicle.Remove(removeId);
            if (res)
                cout << " Remove vehicle successfully " << removeId << endl;
            else
                cout << "Not found vehicle id " << removeId << endl;
			break;
		}

		case 5: {
            vehicle.Export("25TH1.dla");
            cout << "Exported successfully: " << endl;
			break;
		}

		case 6: {
           vehicle.Import("25TH1.dla");
            cout << "Imported successfully: " << endl;
			break;
		}

		case 7: {
            int updateId;
            cout << " Enter vehicle to update: ";
            cin >> updateId;
            bool res = vehicle.Update(updateId);
            if (res)
                cout << " Update vehicle successfully " << updateId << endl;
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


