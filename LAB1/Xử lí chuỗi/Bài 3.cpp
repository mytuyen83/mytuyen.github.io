#include <iostream>
using namespace std;

void chen(string& s, int k, char c)
{
	s.insert(k, 1, c); // Thêm 1 ký tự c vào vị trí k trong chuỗi
}
int main() 
{
	string s;
	int k;
	char c;
	cout << "Nhap chuoi s: "; cin >> s;
	cout << "Nhap vi tri can chen: "; cin >> k;
	cout << "Nhap ky tu can chen: "; cin >> c;
	chen(s, k, c);
	cout << "Chuoi sau khi them ky tu " << c << " vao vi tri " << k << ": " << s << endl;
	return 0;
}