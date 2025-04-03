#include <iostream>
using namespace std;

void DiChuyen(int n, int a, int b, int c)
{
	if (n == 1)
		cout << a << " -> " << c << endl;
	else
	{
		DiChuyen(n - 1, a, c, b);
		DiChuyen(1, a, b, c);
		DiChuyen(n - 1, b, a, c);
	}
}

int main()
{
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	DiChuyen(n, a, b, c);
	return 0;
}