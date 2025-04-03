#include <iostream>

using namespace std;

struct PhongThi {
    int soPhong;
    char nha;
    int sucChua;
};

// Hàm nhập danh sách phòng thi
void nhapDanhSach(PhongThi ds[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Nhập số phòng, nhà và sức chứa: ";
        cin >> ds[i].soPhong >> ds[i].nha >> ds[i].sucChua;
    }
}

// Hàm hiển thị danh sách phòng thi
void hienThiDanhSach(PhongThi ds[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Phòng: " << ds[i].soPhong << " - Nhà: " << ds[i].nha << " - Sức chứa: " << ds[i].sucChua << endl;
    }
    cout << "-----------------------\n";
}

// Sắp xếp theo sức chứa giảm dần
void sapXepSucChuaGiam(PhongThi ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].sucChua < ds[j].sucChua) {
                PhongThi temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

// Sắp xếp theo Nhà tăng dần, nếu cùng Nhà thì theo số phòng tăng dần
void sapXepNhaPhongTang(PhongThi ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].nha > ds[j].nha || (ds[i].nha == ds[j].nha && ds[i].soPhong > ds[j].soPhong)) {
                PhongThi temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

// Sắp xếp theo Nhà tăng dần, nếu cùng Nhà thì theo sức chứa giảm dần
void sapXepNhaSucChuaGiam(PhongThi ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].nha > ds[j].nha || (ds[i].nha == ds[j].nha && ds[i].sucChua < ds[j].sucChua)) {
                PhongThi temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Nhập số lượng phòng thi: ";
    cin >> n;

    PhongThi danhSach[200];
    nhapDanhSach(danhSach, n);

    // Sắp xếp và hiển thị theo sức chứa giảm dần
    sapXepSucChuaGiam(danhSach, n);
    cout << "Danh sách phòng theo sức chứa giảm dần:\n";
    hienThiDanhSach(danhSach, n);

    // Sắp xếp và hiển thị theo Nhà tăng dần, số phòng tăng dần
    sapXepNhaPhongTang(danhSach, n);
    cout << "Danh sách phòng theo Nhà tăng dần, số phòng tăng dần:\n";
    hienThiDanhSach(danhSach, n);

    // Sắp xếp và hiển thị theo Nhà tăng dần, sức chứa giảm dần
    sapXepNhaSucChuaGiam(danhSach, n);
    cout << "Danh sách phòng theo Nhà tăng dần, sức chứa giảm dần:\n";
    hienThiDanhSach(danhSach, n);

    return 0;
}