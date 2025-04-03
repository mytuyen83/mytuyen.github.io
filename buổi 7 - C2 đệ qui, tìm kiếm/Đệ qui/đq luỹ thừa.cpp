#include <iostream>
using namespace std;

// gọi lt(a,n) = a mũ n
// lt(a,n) = { 1 khi n=0
//             a * lt(a,n-1) khi n<0 }

int luythua(int a, int n)
{
	if (n == 0) return 1;
	return luythua(a, n - 1) * a;
}

// gọi lt(a,n) = a mũ n
// lt(a,n) = { 1 khi n=0
//             lt(a,n/2) mũ 2 khi n%2==0
//             a*lt(a,n/2) mũ 2 khi n%2!=0 }

int chiadetri(int a, int n)
{
	int kq, t;
	if (n == 0) kq = 1;
	else {
		t = chiadetri(a, n / 2);
		if (n % 2 == 0) kq = t * t;
		else kq = a * t * t;
	}
	return kq;
}

int main()
{
	/*cout << luythua(2,11);*/
	cout << chiadetri(2, 11);
	return 0;
}