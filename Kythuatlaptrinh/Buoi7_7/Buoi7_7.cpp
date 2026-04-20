#include <string>
#include <iostream>
#include "Account.h"
#include"Linkedlist.h"
using namespace std;

int main()
{
	LinkedList<Account> account = { NULL };

	do {
		system("cls");
		cout << " ------- ACCOUNT MANAGEMENT ------" << endl;
		cout << "1.Show all account" << endl;
		cout << "2.Add a account" << endl;
		cout << "3.Dele a account" << endl;
		cout << "4.Update a account" << endl;
		cout << "5.Find account" << endl;
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
			account.Show();
			break;
		}

		case 2: {
		    Account a;
			cin >> a;
			account.Add(a);
			break;
		}

		case 3: {
			int removeId;
			cout << "Enter account to remove "; 
			cin >> removeId;
			bool res = account.Remove(removeId);
			if (res)
				cout << " Remove account successfully" << removeId<< endl;
			else
				cout << "Not found account id" <<removeId<< endl;
			break;
		}

		case 4: {
			int updateId;
			cout << " Enter account to update";
			cin >> updateId;
			bool res = account.Update(updateId);
			if (res)
				cout << " Update account successfully" << updateId << endl;
			else
				cout << "Not found account id " << updateId << endl;
			break;
		}

		case 5: {
			string userName;
			cout << "Enter account name: ";
			cin.ignore();
			getline(cin, userName);
			account.Find(userName);
			break;
		}

		case 6: {
			/*books.Export("25TH1.dla");
			cout << "Exported successfully" << endl;*/
			break;
		}

		case 7: {
			/*books.Import("25TH1.dla");
			cout << "Imported successfully" << endl;*/
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


