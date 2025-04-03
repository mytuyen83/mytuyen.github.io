#include <iostream>
using namespace std;

int gt(int n)
{
	if (n == 0) return 1;
	if (n == 1) return 1;
	return n * gt(n - 1);
}

int main()
{
	int n;
	cout << "Nhap n: "; cin >> n;
	cout << "Ket qua: " << gt(n) << endl;
	return 0;
}