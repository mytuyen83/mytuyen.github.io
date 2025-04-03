#include <iostream>

using namespace std;

#define MAX 10  // Số phần tử của mảng

// Hàm in mảng tại mỗi bước
void inMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


void sapXepNhanh(int a[], int trai, int phai) {
    if (trai >= phai) return;

    int chot = a[phai]; // Chọn phần tử chốt
    int i = trai - 1;

    for (int j = trai; j < phai; j++) {
        if (a[j] < chot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[phai]); // Đưa chốt về đúng vị trí

    inMang(a, MAX); // In từng bước

    sapXepNhanh(a, trai, i);
    sapXepNhanh(a, i + 2, phai);
}


void tronMang(int a[], int trai, int giua, int phai) {
    int n1 = giua - trai + 1, n2 = phai - giua;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = a[trai + i];
    for (int i = 0; i < n2; i++) R[i] = a[giua + 1 + i];

    int i = 0, j = 0, k = trai;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) a[k++] = L[i++];
        else a[k++] = R[j++];
    }

    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    inMang(a, MAX); // In từng bước
}

void sapXepTron(int a[], int trai, int phai) {
    if (trai >= phai) return;

    int giua = (trai + phai) / 2;
    sapXepTron(a, trai, giua);
    sapXepTron(a, giua + 1, phai);
    tronMang(a, trai, giua, phai);
}


void dieuChinhHeap(int a[], int n, int i) {
    int lonNhat = i;
    int trai = 2 * i + 1;
    int phai = 2 * i + 2;

    if (trai < n && a[trai] > a[lonNhat]) lonNhat = trai;
    if (phai < n && a[phai] > a[lonNhat]) lonNhat = phai;

    if (lonNhat != i) {
        swap(a[i], a[lonNhat]);
        dieuChinhHeap(a, n, lonNhat);
    }
}

void sapXepHeap(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) dieuChinhHeap(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        dieuChinhHeap(a, i, 0);
        inMang(a, MAX); // In từng bước
    }
}


int main() {
    int mang[MAX] = { 8, 5, 1, 3, 6, 9, 12, 4, 7, 10 };

    cout << "Mảng ban đầu: ";
    inMang(mang, MAX);

    // Sắp xếp nhanh
    int mangNhanh[MAX] = { 8, 5, 1, 3, 6, 9, 12, 4, 7, 10 };
    cout << "\n Sắp xếp nhanh:\n";
    sapXepNhanh(mangNhanh, 0, MAX - 1);
    cout << "Kết quả cuối cùng: ";
    inMang(mangNhanh, MAX);

    // Sắp xếp trộn
    int mangTron[MAX] = { 8, 5, 1, 3, 6, 9, 12, 4, 7, 10 };
    cout << "\n Sắp xếp trộn:\n";
    sapXepTron(mangTron, 0, MAX - 1);
    cout << "Kết quả cuối cùng: ";
    inMang(mangTron, MAX);

    // Sắp xếp cây
    int mangHeap[MAX] = { 8, 5, 1, 3, 6, 9, 12, 4, 7, 10 };
    cout << "\n Sắp xếp cây:\n";
    sapXepHeap(mangHeap, MAX);
    cout << "Kết quả cuối cùng: ";
    inMang(mangHeap, MAX);

    return 0;
}