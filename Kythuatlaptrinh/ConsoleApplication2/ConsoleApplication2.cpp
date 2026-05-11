

#include <iostream>
#include<string>
using namespace std;


struct Book {
    int id;
    char name[50];
    double price;
    friend istream& operator>>(istream& in, Book& b) {
        cout << "Book information: " << endl;

        cout << "\t+ Id: ";
        in >> b.id;

        cout << "\t+ Name: ";
        in.ignore();
        in.getline(b.name, 50);

        cout << "\t+ Price: ";
        in >> b.price;
        return in;
    }
    friend ostream& operator<<(ostream& out, Book& b) {
        out << "\t+ Id: "<< b.id << endl;
        out << "\t+ Name: " << b.name << endl;
        out << "\t+ Price: " << b.price << endl;
        return out;
    }
};

#define MAX 100
int nBook = 0;
Book books[MAX];

void AddBook(Book b) {
    if (nBook >= MAX) {
        cout << "Out of storeage" << endl;
        return;
    }
    books[nBook++] = b;
}
void Show() {
    for (int i = 0; i < nBook; i++) {
        cout << books[i];
    }
}
void Sort() {
    for (int i = 0; i < nBook - 1; i++) {
        for (int j = i + 1;j < nBook;j++) {
            if (books[j].id > books[i].id) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
}

void Find() {
     
}



int main()
{
    bool sorted = false;
    int nBook = 0;
    Book books[MAX];
    do {
        system("cls");
        cout << "-------BOOK MANAGEMENT----------" << endl;
        cout << "1.Add a book"  << endl;
        cout << "2.Show a book" << endl;
        cout << "3.Sort a book" << endl;
        cout << "4.Find a book" <<endl;
        cout << "0.Exit" << endl;
        cout << "--------------------------------" << endl;
        cout << "Chosse:  ";
        int chosse;
        cin >> chosse;
        switch (chosse) {
        case 1: {
            Book b;
            cin >> b;
            AddBook(b);
            sorted = false;
            break;
        }
        case 2: {
            Show();
            break;
        }  
        case 3: {
            Sort();
            sorted = true;
            break;
        } 
        case 4: {
            if (!sorted)
            {
                cout << "Books aren't sorted" << endl;
            }
            else {
                int bookId;
                cout << "Book Id to find: ";
                cin >> bookId;
                Find(bookId);
            }
            break;
        }
        case 0: 
            return 0;
        
        default: {
            cout << "Invalid command!!" << endl;
            break;
        }
        }
              system("pause");
              cout << "Press enter to continue..." << endl;
        } while (true);

}

