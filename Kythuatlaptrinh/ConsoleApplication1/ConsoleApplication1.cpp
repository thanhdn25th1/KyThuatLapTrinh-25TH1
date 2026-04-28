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

struct Vehicle {
    int id;
    char name [30];
    char type[30]; //kieu xe : sirius, wave 50
    char branch [50]; //chinh nhanh: Toyota, Yamaha
    double price ; // gia xe 
    

    friend ostream& operator<<(ostream& os, Vehicle& v) {
        os << "\t+ Id: " << v.id << endl;
        os << "\t+ Name: " << v.name << endl;
        os << "\t+ Type: " << v.type << endl;
        os << "\t+ Price: " << v.price << endl;
        return os;
    }

    friend istream& operator>>(istream& in, Vehicle& v) {
        cout << "\t + Id: ";
        in >> v.id;
        cout << "\t + Name: ";
        in.ignore();
        in.getline(v.name, 30);
        cout << "\t+ Type: ";
        in.ignore();
        in.getline(v.type, 30);
        cout << "\t+ Branch:";
        in.ignore();
        in.getline(v.branch, 50);
        cout << "\t+ Price: ";
        in >> v.price;
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
    void Find(string userName);
    bool Remove(int id);
    void Export(string fileName);
    void Import(string fileName);
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
void LinkedList <T>::Add(T item) {
    Node<T>* newNode = new Node<T>;
    newNode->data = item;
    newNode->next = nullptr;
    if (head == nullptr) {
        head == newNode;
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
void LinkedList <T>::Find(string userName) {
    if (!head) {
        cout << " No vehicle avaiable" << endl;
        return;
    }
    Node<T>* item = head;
    while (item != NULL) {
        if (item->data.usr == userName) {
            cout << item->data;
            return;
        }
        item = item->next;
    }
    cout << "No vehicle found" << endl;
}

template<typename T>
bool LinkedList <T>::Remove(int removeId) {
    if (!head) {
        cout << " No vehicle avaiable" << endl;
        return false;
    }
    Node<T>* item = head;
    if (item->data.id == id) {
        head = item->next;
        delete item;
        return true;
    }
    while (item->next != nullptr) {
        if (item->next->data.id == id) {
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
        cout << "Error opening file for writing" << endl;
        return;
    }
    Node<T>* item = head;
    while (item != NULL) {
        outFile.write(reinterpret_cast<char*>(&item->data), sizeof(T));
        item = item->next;
    }
    outFile.close();
}
template<typename T>
void LinkedList <T>::Import(string fileName) {
    ifstream inFile(fileName, ios::binary);
    if (!inFile) {
        cout << "Error opening file for reading" << endl;
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
           Vehicle a;
            cin >> a;
            vehicle.Add(a);
			break;
		}

		case 3: {
            string userName;
            cout << "Enter account name: ";
            cin.ignore();
            getline(cin, userName);
            vehicle.Find(userName);
			break;
		}

		case 4: {
            int removeId;
            cout << "Enter vehicle to remove ";
            cin >> removeId;
            bool res = vehicle.Remove(removeId);
            if (res)
                cout << " Remove vehicle successfully" << removeId << endl;
            else
                cout << "Not found vehicle id" << removeId << endl;
			break;
		}

		case 5: {
            vehicle.Export("25TH1.dla");
            cout << "Exported successfully:" << endl;
			break;
		}

		case 6: {
           vehicle.Import("25TH1.dla");
            cout << "Imported successfully" << endl;
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


