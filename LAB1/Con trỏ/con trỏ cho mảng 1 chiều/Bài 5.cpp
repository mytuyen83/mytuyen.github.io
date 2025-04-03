#include <iostream>
using namespace std;

//Hàm nhập mảng
void nhapmang(int* a, int& n)
{
    cout << "Nhập số lượng phần tử của mảng a: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Nhập phần tử " << i << ": ";
        cin >> *(a + i);
    }
}

//Hàm tách số chẵn và lẻ
void tachmang(int* a, int n, int* b, int &m, int* c, int &k)
{
    int* troa = a, * trob = b, * troc = c;
    m = k = 0; //Số lượng phần tử của b và c
    while (troa < a + n) {
        if (*troa % 2 == 0) { //Tách số chẵn cho vào mảng b
            *trob = *troa;
            trob++;
            m++;
        }
        else { //Tách số lẻ cho vào mảng c
            *troc = *troa;
            troc++;
            k++;
        }
        troa++;
    }
}

// Hàm xuất mảng
void xuatmang(int* a, int n)
{
    for (int i = 0; i < n; i++) {
        cout << *(a + i) << " ";
    }
    cout << endl;
}

int main()
{
    int a[100], b[100], c[100];
    int n, k, m;
    nhapmang(a, n);
    tachmang(a, n, b, m, c, k);
    cout << "Mảng b: ";
    xuatmang(b, m);
    cout << "Mảng c: ";
    xuatmang(c, k);
    return 0;
}