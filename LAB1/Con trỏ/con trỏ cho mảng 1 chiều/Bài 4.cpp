#include <iostream>
using namespace std;

//Hàm nhập mảng
void nhapmang(float* a, int &n) 
{
    cout << "Nhập số lượng phần tử: ";
    cin >> n;
    cout << "Nhập các phần tử tăng dần: ";
    for (int i = 0; i < n; i++){
        cin >> *(a + i);
    }
}

//Hàm trộn hai dãy a và b thành dãy c tăng dần
void tronmang(float* a, int n, float* b, int m, float* c, int &k) 
{
    float* troa = a, * trob = b, * troc = c;
    k = 0; //Số lượng phần tử của dãy c
    while (troa < a + n && trob < b + m){ //Duyệt cả hai dãy a và b
        if (*troa < *trob) {
            *troc = *troa;
            troa++;
        }
        else {
            *troc = *trob;
            trob++;
        }
        troc++;
        k++;
    }
    while (troa < a + n) { //Chèn phần còn lại của dãy a vào c (nếu còn)
        *troc = *troa;
        troa++;
        troc++;
        k++;
    }
    while (trob < b + m) { //Chèn phần còn lại của dãy b vào c (nếu còn)
        *troc = *trob;
        trob++;
        troc++;
        k++;
    }
}

// Hàm xuất mảng
void xuatmang(float* a, int n) 
{
    for (int i = 0; i < n; i++){
        cout << *(a + i) << " ";
    }
    cout << endl;
}

int main() {
    int n, m, k;
    float a[100], b[100], c[200];
    cout << "Nhập dãy a:\n";
    nhapmang(a, n);
    cout << "Nhập dãy b:\n";
    nhapmang(b, m);
    tronmang(a, n, b, m, c, k);
    cout << "Dãy c là: ";
    xuatmang(c, k);
    return 0;
}
