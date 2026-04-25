
#include <iostream>


using namespace std;




struct Vehicle{
	int id;
	char type[30]; //Sirus, Wave 50
	string branch; //Toyota, Yamaha
	double price;
}

	/*1. Xem danh sach;
	2. Them 1 chiec xe;
	3. Tim kiem xe;
	4. Xoa 1 chiec xe;
	5. Luu tap tin;
	6. Doc tap tin;
	7. Cap nhat thong tin xe;
	8. Thong ke xe theo nhan hieu : Toyota: 3, Yamaha : 2;*/









int main()
{
	/*LinkedList<Account> account = { NULL };*/

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
			
			break;
		}

		case 2: {
			
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


