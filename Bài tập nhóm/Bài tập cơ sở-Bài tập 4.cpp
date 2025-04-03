#include <iostream>
#include <fstream>

using namespace std;

#define MAX 30000

void doi(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void docFile(int a[], int& n) {
    ifstream file("data.txt");
    file >> n;
    for (int i = 0; i < n; i++) {
        file >> a[i];
    }
    file.close();
}

void ghiFile(int a[], int n, string tenFile) {
    ofstream file(tenFile);
    for (int i = 0; i < n; i++) {
        file << a[i] << " ";
    }
    file.close();
}

void interchangeSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                doi(a[i], a[j]);
            }
        }
    }
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        doi(a[i], a[minIndex]);
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                doi(a[j], a[j + 1]);
            }
        }
    }
}

void thucHienSapXep(void (*sapXep)(int[], int), int a[], int n, string tenFile) {
    int temp[MAX];
    for (int i = 0; i < n; i++) temp[i] = a[i];

    sapXep(temp, n);
    ghiFile(temp, n, tenFile);
}

int main() {
    int a[MAX], n;
    docFile(a, n);

    thucHienSapXep(interchangeSort, a, n, "InterchangeSort.txt");
    thucHienSapXep(selectionSort, a, n, "SelectionSort.txt");
    thucHienSapXep(insertionSort, a, n, "InsertionSort.txt");
    thucHienSapXep(bubbleSort, a, n, "BubbleSort.txt");

    cout << "Kết quả đã được lưu vào file!\n";
    return 0;
}