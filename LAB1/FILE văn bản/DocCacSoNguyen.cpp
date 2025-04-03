#include <iostream>
#include <fstream>
using namespace std;

#define FI "DaySoNguyen.inp"

void NhapDuLieu() // Hàm nhập dữ liệu và ghi vào file
{
    ofstream fo(FI); // Mở file để ghi
    if (!fo) {
        cout << "Khong the mo file de ghi!" << endl;
        return;
    }
    int n;
    cout << "Nhap so phan tu: "; cin >> n;
    fo << n << endl; // Ghi số phần tử vào file
    cout << "Nhap " << n << " so nguyen: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        fo << x << " "; // Ghi từng số vào file
    }
    fo << endl;
    fo.close(); // Đóng file
    cout << "Da ghi du lieu vao file " << FI << endl;
}

void DocDuLieu(int a[], int& n)
{
    ifstream fi(FI); // Mở file để đọc
    if (!fi) {
        cout << "Khong the doc file!" << endl;
        return;
    }
    fi >> n; // Đọc số phần tử của mảng
    for (int i = 0; i < n; i++) { // Đọc n số nguyên vào mảng a
        fi >> a[i];
    }
    fi.close(); // Đóng file
}

int main()
{
    int n, a[100];
    NhapDuLieu();
    DocDuLieu(a, n);
    cout << "Day so nguyen: ";
    for (int i = 0; i < n; ++i) { // In kết quả đọc được ra màn hình
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}