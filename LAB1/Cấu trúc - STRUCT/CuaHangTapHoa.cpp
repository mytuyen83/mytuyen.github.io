#include <iostream>
#include <string>
using namespace std;

struct MatHang
{
	string MSMH;
	string TenMH;
	int SoLuong;
	double DonGia;
};

MatHang ds[100]; // Danh sách tối đa 100 mặt hàng
int n = 0; // Số lượng mặt hàng hiện tại

void nhap()
{
	cout << "Nhap so luong mat hang: "; cin >> n;
	cin.ignore();
	for (int i = 0;i < n;i++) {
		cout << "Nhap thong tin mat hang thu " << i << endl;
		cout << "Ma so mat hang: "; getline(cin, ds[i].MSMH);
		cout << "Ten mat hang: "; getline(cin, ds[i].TenMH);
		cout << "So luong: "; cin >> ds[i].SoLuong;
		cout << "Don gia: "; cin >> ds[i].DonGia;
		cin.ignore();
	}
}

void in()
{
	string ten;
	cout << "Nhap ten mat hang can tim: "; 
	cin.ignore();
	getline(cin, ten);
	for (int i = 0;i < n;i++) {
		if (ds[i].TenMH == ten) {
			cout << "Thong tin mat hang:\n";
			cout << "MSMH: " << ds[i].MSMH << endl;
			cout << "Ten: " << ds[i].TenMH << endl;
			cout << "So luong: " << ds[i].SoLuong << endl;
			cout << "Don gia: " << ds[i].DonGia << endl;
			return;
		}
	}
	cout << "Khong co mat hang dang tim\n";
}

void tong()
{
	int s = 0;
	for (int i = 0;i < n;i++) {
		s += ds[i].SoLuong;
	}
	cout << "Tong so luong cac mat hang la: " << s << endl;
}

int main()
{
	nhap();
	in();
	tong();
	return 0;
}