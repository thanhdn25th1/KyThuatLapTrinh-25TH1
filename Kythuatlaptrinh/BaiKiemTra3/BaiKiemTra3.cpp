

#include <iostream>
#include <string>

using namespace std;
void bai1() {
    string full;
    cout << "1. Nhap ho va ten: ";
    getline(cin, full);

    size_t pos = full.find_last_of(' ');
    if (pos != string::npos) {
        cout << "   Ho lot: " << full.substr(0, pos) << endl;
        cout << "   Ten: " << full.substr(pos + 1) << endl;
    }
    else {
        cout << "   Chi co ten: " << full << endl;
    }
}


void bai2() {
    string s;
    char x;
    cout << "2. Nhap mot chuoi bat ky: ";
    getline(cin, s);
    cout << "   Nhap ky tu X muon xoa: ";
    cin >> x;
    cin.ignore();

    string result = "";
    for (char c : s) {
        if (c != x) result += c;
    }
    cout << "   Chuoi sau khi xoa '" << x << "': " << result << endl;
}


void bai3() {
    string s;
    cout << "3. Nhap chuoi de kiem tra doi xung: ";
    getline(cin, s);

    bool check = true;
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            check = false;
            break;
        }
    }

    if (check) cout << "   Ket qua: Day la chuoi doi xung." << endl;
    else cout << "   Ket qua: Khong phai chuoi doi xung." << endl;
}


void bai4() {
    string x;
    char y;
    cout << "4. Nhap chuoi X: ";
    getline(cin, x);
    cout << "   Nhap ky tu Y: ";
    cin >> y;
    cin.ignore();

    int pos = -1;
    for (int i = x.length() - 1; i >= 0; i--) {
        if (x[i] == y) {
            pos = i;
            break;
        }
    }

    if (pos != -1) cout << "   Vi tri xuat hien cuoi cung: " << pos << endl;
    else cout << "   Khong tim thay ky tu '" << y << "' trong chuoi." << endl;
}

int main() {
    
    cout << "--- THUC HIEN CAC BAI TAP CHUOI ---" << endl;

    bai1();
    bai2();
    bai3();
    bai4();

    cout << "\n--- HOAN THANH ---" << endl;
    return 0;
}
