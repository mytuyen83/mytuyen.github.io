#include <iostream>
#include <cstring>
using namespace std;

struct LoaiHoa 
{
    char Ten[100];
    int SoLuong;
    char DVT[20];
    float DonGia;
};

struct DanhSachLoaiHoa 
{
    LoaiHoa hoa[20]; // Tối đa 20 loại hoa
    int n;            // Số lượng loại hoa hiện tại
};

void NhapDanhSach(DanhSachLoaiHoa& ds) 
{
    cout << "Nhap so luong loai hoa: "; cin >> ds.n;
    cin.ignore();
    for (int i = 0; i < ds.n; i++) {
        cout << "Nhap thong tin cho loai hoa thu " << i + 1 << ":\n";
        cout << "Ten loai hoa: "; cin.getline(ds.hoa[i].Ten, 100);
        cout << "So luong: "; cin >> ds.hoa[i].SoLuong;
        cin.ignore();
        cout << "Don vi tinh: "; cin.getline(ds.hoa[i].DVT, 20);
        cout << "Don gia: "; cin >> ds.hoa[i].DonGia;
        cin.ignore();
    }
}

void XuatDanhSach(DanhSachLoaiHoa ds) 
{
    cout << "Danh sach loai hoa:\n";
    for (int i = 0; i < ds.n; i++) {
        cout << "Loai hoa: " << ds.hoa[i].Ten << "\n";
        cout << "So luong: " << ds.hoa[i].SoLuong << "\n";
        cout << "Don vi tinh: " << ds.hoa[i].DVT << "\n";
        cout << "Don gia: " << ds.hoa[i].DonGia << "\n";
    }
}

int TimLoaiHoa(DanhSachLoaiHoa ds, const char* tenloai) 
{
    for (int i = 0; i < ds.n; i++) {
        if (strcmp(ds.hoa[i].Ten, tenloai) == 0) {
            return i; // Trả về vị trí của loại hoa
        }
    }
    return -1; // Nếu không tìm thấy
}

void XuLyBanHoa(DanhSachLoaiHoa& ds, const char* tenloai, int soluong) 
{
    int viTri = TimLoaiHoa(ds, tenloai);
    if (viTri == -1) {
        cout << "Loai hoa khong ton tai.\n";
    }
    else {
        if (ds.hoa[viTri].SoLuong >= soluong) {
            float tongTien = soluong * ds.hoa[viTri].DonGia;
            ds.hoa[viTri].SoLuong -= soluong; // Giảm số lượng hoa
            cout << "Hoa ban thanh cong. Tong tien: " << tongTien << " VND\n";
        }
        else {
            cout << "Khong du so luong hoa. So luong hien tai: " << ds.hoa[viTri].SoLuong << "\n";
        }
    }
}

int main() 
{
    DanhSachLoaiHoa ds;
    ds.n = 0;
    NhapDanhSach(ds);
    XuatDanhSach(ds);
    char tenloai[100];
    int soluong;
    cout << "Nhap ten loai hoa can mua: ";
    cin.getline(tenloai, 100);
    cout << "Nhap so luong hoa can mua: ";
    cin >> soluong;
    XuLyBanHoa(ds, tenloai, soluong);
    return 0;
}
