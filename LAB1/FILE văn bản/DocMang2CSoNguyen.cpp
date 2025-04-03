#include <iostream>
#include <fstream>
using namespace std;

#define FI "MangSo.inp"

void NhapMang() // Hàm nhập mảng từ bàn phím và ghi vào file
{
    ofstream fo(FI); // Mở file để ghi
    if (!fo) {
        cout << "Khong the mo file de ghi!" << endl;
        return;
    }
    int n, m;
    cout << "Nhap lan luot so dong va so cot: "; cin >> n >> m;
    fo << n << " " << m << endl; // Ghi số dòng và số cột vào file
    cout << "Nhap cac phan tu cua mang:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            fo << x << " "; // Ghi từng số vào file
        }
        fo << endl;
    }
    fo.close(); // Đóng file
    cout << "Da ghi du lieu vao file " << FI << endl;
}

void DocMang(int a[][100], int& n, int& m) // Hàm đọc dữ liệu từ file vào mảng
{
    ifstream fi(FI); // Mở file để đọc
    if (!fi) {
        cout << "Khong the doc file!" << endl;
        return;
    }
    fi >> n >> m; // Đọc số dòng và số cột
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fi >> a[i][j]; // Đọc từng phần tử vào mảng
        }
    }
    fi.close(); // Đóng file
}

void XuatMang(int a[][100], int n, int m)
{
    cout << "Mang da doc duoc:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() 
{
    int n, m, a[100][100];
    NhapMang();
    DocMang(a, n, m); 
    XuatMang(a, n, m); 
    return 0;
}
