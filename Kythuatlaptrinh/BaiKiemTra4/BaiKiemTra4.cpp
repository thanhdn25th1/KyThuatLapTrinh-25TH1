

#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
    int maso;
    char hoten[50];
    float diemhocphan;
    float diemchuyencan, diemgiuaky, diemcuoiky;
    friend istream& operator>>(istream& in, SinhVien& b) {
        cout << "Thong Tin Sinh Vien: " << endl;
        cout << "\t+ Ma So: ";
        in >> b.maso;
        cout << "\t+ Ho Ten: ";
        in.ignore();
        in.getline(b.hoten, 50);
        cout << "\t+ Diem Hoc Phan: ";
        in >> b.diemhocphan;
        cout << "\t+ Diem Chuyen Can: ";
        in >> b.diemchuyencan;
        cout << "\t+ Diem Giua Ky: ";
        in >> b.diemgiuaky;
        cout << "\t+ Diem Cuoi Ky: ";
        in >> b.diemcuoiky;
        return in;
    }
    friend ostream& operator<<(ostream& out, SinhVien& b) {
        out << "\t+ Ma So: " << b.maso << endl;
        out << "\t+ Ho Ten: " << b.hoten << endl;
       
        out << "\t+ Diem Chuyen Can: " << b.diemchuyencan << endl;
        out << "\t+ Diem Giua Ky: " << b.diemgiuaky << endl;
        out << "\t+ Diem Cuoi Ky: " << b.diemcuoiky << endl;

        float diemhocphan =b.diemchuyencan * 0.1 
                         + b.diemgiuaky * 0.3 
                         + b.diemcuoiky * 0.6;
        out << "\t+ Diem Hoc Phan: " << b.diemhocphan << endl;

        return out;
    }
};

#define MAX 100
int nSinhVien = 0;
SinhVien sinhvien[MAX];

void ThemSinhVien(SinhVien b) {
    if (nSinhVien >= MAX) {
        cout << "Het Cho Luu Tru" << endl;
        return;
    }
    sinhvien[nSinhVien++] = b;
}
void DanhSach() {
    for (int i = 0; i < nSinhVien; i++) {
        cout << sinhvien[i];
    }
}

float DiemHocPhan(SinhVien b) {
    return
        b.diemchuyencan * 0.1 +
        b.diemgiuaky * 0.3 +
        b.diemcuoiky * 0.6;
}

void SapXepDS() {
    for (int i = 0; i < nSinhVien - 1; i++) {
        for (int j = i + 1;j < nSinhVien;j++) {
            if (DiemHocPhan(sinhvien[i]) < DiemHocPhan(sinhvien[j])) {
                SinhVien temp = sinhvien[i];
                sinhvien[i] = sinhvien[j];
               sinhvien[j] = temp;
            }
        }
    }
}


void TimSinhVien(int maSoSinhVien) {
    int left = 0, right = nSinhVien - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sinhvien[mid].maso == maSoSinhVien) {
            cout << sinhvien[mid];
            return;
        }
        if (sinhvien[mid].maso > maSoSinhVien) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << "Mat Hieu Luc " << endl;
}



    int main()
    {
        bool SapXep = false;
        
        do {
            system("cls");
            cout << "-------DANH SACH SINH VIEN----------" << endl;
            cout << "1.Them Sinh Vien" << endl;
            cout << "2.Danh Sach Sinh Vien" << endl;
            cout << "3.Sap Xep Danh Sach" << endl;
            cout << "4.Tim Sinh Vien" << endl;
            cout << "0.Thoat" << endl;
            cout << "--------------------------------" << endl;
            cout << "Chon:  ";
            int chon;
            cin >> chon;
            switch (chon) {
            case 1: {
                SinhVien b;
                cin >> b;
                ThemSinhVien(b);
                SapXep = false;
                break;
            }
            case 2: {
                DanhSach();
                break;
            }
            case 3: {
                SapXepDS();
                SapXep = true;
                break;
            }
            case 4: {
                if (!SapXep)
                {
                    cout << "Danh Sach Khong Duoc Sap Xep" << endl;
                }
                else {
                    int maSoSinhVien;
                    cout << "Nhap Ma So De Tim: ";
                    cin >> maSoSinhVien;
                    TimSinhVien(maSoSinhVien);
                }
                break;
            }
            case 0:
                return 0;

            default: {
                cout << "LENH KHONG HOP LE!!" << endl;
                break;
            }
            }
            system("pause");
            cout << "Nhan Enter De Tiep Tuc..." << endl;
        } while (true);

    }

