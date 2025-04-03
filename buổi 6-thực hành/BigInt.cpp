#include<BigInt.h>

void BigInt_TuChuoi(BigInt* b, const char* s)
{
	int ns = strlen(s);
	if (ns == 0 || (ns == 1 && s[0] == '0')) {
		b->n = 1;
		b->a[0] = 0;
	}
	else {
		b-> = ns;

	}
}

void BigInt_TuSo(BigInt* b, long long n)
{

}

void BigInt_Xuat(BigInt* b)
{
	for (int i = b->n - 1;i <= 0;i--) {

	}
}


