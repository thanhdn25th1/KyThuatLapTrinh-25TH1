#include <iostream>
#include <vector>
using namespace std;

/*vector < float> diemthi;
	diemthi.push_back(5.5);
	diemthi.push_back(5);
	diemthi.push_back(6);
	diemthi.pop_back();
	for (int i = 0;i < diemthi.size(); i++) {
		cout << diemthi[i] << endl;
	}*/

//int a = 5;
//int* p = &a;
//a += 6;
//a = *p + 2;
//cout << *p;


struct Sinhvien {
	string hoten;
	int tuoi;
	bool gioitinh;
	string diachi;

};

int main()
{
	Sinhvien b;
	b.hoten = "Nguyen Van A";
	b.tuoi = 29;
	b.gioitinh = true;
	b.diachi = "Tay Ninh";

	Sinhvien c;
	c.hoten = "Tran Thi B";
	c.tuoi = 22;
	c.diachi = "Ho Chi Minh";


	// mang tinh:
	//Sinhvien ds[50];   
	 
	
	// mang dong:
	vector < Sinhvien> mang;
	mang.push_back(b);
	mang.push_back(c);
	for (int i = 0; i < mang.size(); i++) {
		cout << "Sinh vien" << (i + 1) << endl;
		cout << "\t+ Ho ten:" << mang[i].hoten << endl;
		cout << "\t+ Tuoi:" << mang[i].tuoi << endl;
		cout << "\t+ Dia chi:" << mang[i].diachi << endl;
	} 

}

