
#include <iostream>
#include<vector>
using namespace std;

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int* p = arr;
	cout << " Duyet mang: "<< endl;
	for (int i = 0; i < n; i++) {
		cout << *(p + i) << " " << endl;
	}
	cout << "Duyet mang: "<< endl; 
	for (int i = 0; i < n; i++) {
		cout << p[i] << " " << endl;
	}
	

	vector<int> v;
	int  temp;
	cout << "Nhap so luong phan tu: " << endl;
	cin >> n;
	for (int i = 0;i < n; i++) {
		cout << "Nhap phan tu thu" << i + 1 << ": " << endl;
		cin >> temp;
		v.push_back(temp);
	}

	cout << "Vector hien tai: " << endl;
	for (int x : v) cout << x << " " << endl;

	int a;
	cout << "Nhap gia tri can them vao cuoi: " << endl;
	cin >> a;
	v.push_back(a);
	cout << "Sau khi them: " << endl;
	for (int x : v) cout << x << " " << endl;

	if (!v.empty()) {
		v.pop_back();
		cout << "Sau khi xoa phan tu cuoi: ";
		for (int x : v) cout << x << " " << endl;
	}
}




