#include <iostream>
using namespace std;

int main()
{
	string s;
	int k;
	cout << "Nhap chuoi s: "; cin >> s;
	cout << "Nhap vi tri cua ky tu muon xoa: "; cin >> k;
	if (k >= 0 && k < s.length()) { // Kiểm tra điều kiện của k có hợp lệ không
		s.erase(k, 1); // Xoá ký tự tại vị trí k
	}
	cout << "Chuoi sau khi xoa ky tu tai vi tri " << k << ": " << s << endl;
	return 0;
}