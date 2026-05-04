
#include <iostream>
#include<vector>
using namespace std;

int main()
{
   
	int arr[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int* p = arr;
	cout << "Phan tu: " << endl;
	for ( int i = 0; i < n, i++) {
		cout << *(p + i) << " " << endl;
	}

	cout << "Phan tu: " << endl;
	for (int i = 0; i < n; i++) {
		cout << p[i] << " " << endl;
	}


}

