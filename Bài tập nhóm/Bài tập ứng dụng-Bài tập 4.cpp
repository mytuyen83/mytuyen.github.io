#include <iostream>

using namespace std;

#define MAX 100 // Giới hạn kích thước ma trận

// Hàm kiểm tra số nguyên tố, trả về 1 nếu là số nguyên tố, 0 nếu không
int la_so_nguyen_to(int so) {
    if (so < 2) return 0;
    for (int i = 2; i * i <= so; i++) {
        if (so % i == 0) return 0;
    }
    return 1;
}

// Hàm nhập ma trận
void nhap_ma_tran(int a[MAX][MAX], int& dong, int& cot) {
    cout << "Nhập số dòng và số cột: ";
    cin >> dong >> cot;
    cout << "Nhập các phần tử của ma trận:\n";
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            cin >> a[i][j];
        }
    }
}

// Hàm tìm số nguyên tố lớn nhất trong ma trận
int tim_so_nguyen_to_lon_nhat(int a[MAX][MAX], int dong, int cot) {
    int so_nguyen_to_max = -1;
    for (int i = 0; i < dong; i++) {
        for (int j = 0; j < cot; j++) {
            if (la_so_nguyen_to(a[i][j]) && a[i][j] > so_nguyen_to_max) {
                so_nguyen_to_max = a[i][j];
            }
        }
    }
    return so_nguyen_to_max;
}

// Hàm tìm các dòng có chứa số nguyên tố
void tim_dong_co_so_nguyen_to(int a[MAX][MAX], int dong, int cot) {
    cout << "Các dòng có chứa số nguyên tố: ";
    for (int i = 0; i < dong; i++) {
        int co_so_nguyen_to = 0;
        for (int j = 0; j < cot; j++) {
            if (la_so_nguyen_to(a[i][j])) {
                co_so_nguyen_to = 1;
                break;
            }
        }
        if (co_so_nguyen_to) cout << i + 1 << " ";
    }
    cout << endl;
}

// Hàm tìm các dòng chỉ chứa số nguyên tố
void tim_dong_chi_chua_so_nguyen_to(int a[MAX][MAX], int dong, int cot) {
    cout << "Các dòng chỉ chứa số nguyên tố: ";
    for (int i = 0; i < dong; i++) {
        int toan_so_nguyen_to = 1;
        for (int j = 0; j < cot; j++) {
            if (!la_so_nguyen_to(a[i][j])) {
                toan_so_nguyen_to = 0;
                break;
            }
        }
        if (toan_so_nguyen_to) cout << i + 1 << " ";
    }
    cout << endl;
}

int main() {
    int a[MAX][MAX], dong, cot;

    nhap_ma_tran(a, dong, cot);

    int so_nguyen_to_max = tim_so_nguyen_to_lon_nhat(a, dong, cot);
    if (so_nguyen_to_max != -1) {
        cout << "Số nguyên tố lớn nhất trong ma trận: " << so_nguyen_to_max << endl;
    }
    else {
        cout << "Không có số nguyên tố trong ma trận." << endl;
    }

    tim_dong_co_so_nguyen_to(a, dong, cot);
    tim_dong_chi_chua_so_nguyen_to(a, dong, cot);

    return 0;
}