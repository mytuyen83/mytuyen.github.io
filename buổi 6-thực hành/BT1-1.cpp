#include <iostream>
#include <fstream>
using namespace std;

#define MAX 10000
#define FI "HUYENTHU.INP"

//dữ liệu nhập
int n;
int a[MAX];

void docmang(int a[], int &n,const string& file)
{
	ifstream fi(file);
	if (!fi) {
		cout << "Khong the mo file!\n";
		return;
	}
	fi >> n;
	for (int i = 0;i < n;i++) {
		int x;
		fi >> x;
	}
	fi.close();
}

void nhapmang(int a[], int& n)
{
	cout << "Nhap so luong phan tu cua mang: "; cin >> n;
	for (int i = 0;i < n;i++) {
		cout << "Nhap phan tu thu " << i << ": ";
		cin >> a[i];
	}
}

void xuatmang(int a[], int n)
{
	cout << "Mang vua nhap la: \n"; 
	for (int i = 0;i < n;i++) {
		cout << a[i]<<" ";
	}
	cout << endl;
}

void daycondainhat(int a[], int n)
{
	int max = 1, hientai = 1;
	for (int i = 1;i < n;i++) {
		if (a[i] > a[i - 1]) {
			hientai++;
		}
		else {
			hientai = 1;
		}
		if (hientai > max) {
			max = hientai;
		}
	}
	cout << "Day co do dai dai nhat la: " << max << endl;
}

int main() 
{
	int a[100], n;
	//freopen(FI, "rt", stdin);
	//docmang(a, n, "HUYENTHU.INP");
	//for (int i = 0;i < n;i++) {
	//	cout << a[i] << " ";
	//}
	nhapmang(a, n);
	xuatmang(a, n);
	daycondainhat(a, n);
	return 0;
}