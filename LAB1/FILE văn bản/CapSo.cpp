#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

#define Dulieuvao "CapSo.INP"
#define Ketqua "CapSo.OUT"

void nhapfile(vector<int>& a, int& k, const string& tenfile)
{
    ofstream fo(tenfile);
    if (!fo) {
        cout << "Không thể tạo file " << tenfile << "!" << endl;
        return;
    }
    int n;
    cout << "Nhap so phan tu n: "; cin >> n;
    cout << "Nhap so k: "; cin >> k;
    a.clear(); // Xoá dữ liệu cũ trong vector
    fo << n << " " << k << endl; // Ghi n và k vào file
    cout << "Nhap " << n << " so nguyen:\n";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
        fo << x << endl; // Ghi số vào file
    }
    fo.close();
    cout << "Da ghi du lieu vao file " << tenfile << "!" << endl;
}

void docfile(vector<int>& a, int& k, const string& tenfile)
{
    ifstream fi(tenfile);
    if (!fi) {
        cout << "Không thể mở file " << tenfile << "!" << endl;
        return;
    }
    int n;
    fi >> n >> k; // Đọc số phần tử n và số k
    a.clear(); // Xóa dữ liệu cũ
    for (int i = 0; i < n; i++) {
        int x;
        fi >> x;
        a.push_back(x); // Thêm từng phần tử vào vector
    }
    fi.close();
}

void timCapSo(const vector<int>& a, int k, const string& tenfileout) // Hàm tìm cặp số có tổng bằng k
{
    ofstream fo(tenfileout);
    if (!fo) {
        cout << "Không thể mở file " << tenfileout << "!" << endl;
        return;
    }
    int dem = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            if (a[i] + a[j] == k) {
                fo << a[i] << " " << a[j] << endl; // Ghi vào file
                cout << a[i] << " " << a[j] << endl; // Xuất ra màn hình
                dem++;
            }
        }
    }
    if (dem == 0) { // Nếu không có cặp nào, in 0
        cout << "0" << endl;
    }
    fo.close();
}

int main() 
{
    vector<int> a;
    int k;
    nhapfile(a, k, Dulieuvao);
    docfile(a, k, Dulieuvao);
    timCapSo(a, k, Ketqua);
    cout << "Đa ghi ket qua vao file " << Ketqua << "!" << endl;
    return 0;
}