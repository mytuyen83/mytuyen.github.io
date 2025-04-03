#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

#define Dulieuvao "NT.INP"
#define Ketqua "NT.OUT"

int snt(int n)
{
	if (n < 2) return 0;
	for (int i = 2;i * i <= n;i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

void nhapfile(const string& tenfile) // Hàm nhập dữ liệu từ bàn phím và ghi vào file
{
    ofstream fo(tenfile);
    if (!fo) {
        cout << "Khong the tao file " << tenfile << "!" << endl;
        return;
    }
    int n;
    cout << "Nhap so luong phan tu n: "; cin >> n;
    fo << n << endl;
    cout << "Nhap " << n << " so nguyen:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        fo << x << " ";
    }
    fo << endl;
    fo.close();
}

void docfile(vector<int>& a, const string& tenfile) 
{
    ifstream fi(tenfile);
    if (!fi) {
        cout << "Khong tho mo file " << tenfile << "!" << endl;
        return;
    }
    int n, x;
    fi >> n;
    a.clear(); // Xóa dữ liệu cũ trong vector nếu có, để tạo mới vector
    for (int i = 0; i < n; i++) {
        fi >> x;
        a.push_back(x); // Thêm từng phần tử vào vector
    }
    fi.close();
}

void xuly(const string & tenfileIn, const string & tenfileOut) // Hàm xử lý tìm số nguyên tố
{
    ifstream fi(tenfileIn);
    ofstream fo(tenfileOut);
    if (!fi || !fo) {
        cout << "Khong the mo file!" << endl;
        return;
    }
    int n;
    fi >> n;
    vector<int> nguyento;
    for (int i = 0; i < n; i++) {
        int x;
        fi >> x;
        if (snt(x)) {
            nguyento.push_back(x); // Lưu số nguyên tố vào vector
        }
    }
    sort(nguyento.begin(), nguyento.end()); // Sắp xếp các số nguyên tố theo thứ tự tăng dần
    fo << nguyento.size() << endl; // Ghi số lượng phần tử vào file
    for (int num : nguyento) { // Lần lượt lấy từng giá trị trong vector
        fo << num << " "; // Ghi từng số vào file
    }
    fo << endl;
    // Xuất kết quả ra màn hình
    cout << "\nSo luong so nguyen to: " << nguyento.size() << endl;
    cout << "Cac so nguyen to: ";
    for (int num : nguyento) {
        cout << num << " ";
    }
    cout << endl;
    fi.close();
    fo.close();
}

int main() 
{
    vector<int> a;
    nhapfile(Dulieuvao);
    docfile(a, Dulieuvao);
    xuly(Dulieuvao,Ketqua);
    cout << "Da ghi ket qua vao file NT.OUT" << endl;
    return 0;
}