#include <iostream>
#include <string>
using namespace std;

struct Dienthoai 
{
    string madt;
    string nhanhieu;
    int gia;
};

Dienthoai danhsach[100]; // Danh sách tối đa 100 điện thoại
int soluong = 0;         // Số lượng điện thoại hiện tại

int kiemtra(const string& madt) // Kiểm tra xem mã điện thoại đã tồn tại chưa (trả về 1 nếu có, 0 nếu không)
{
    for (int i = 0; i < soluong; i++) {
        if (danhsach[i].madt == madt) {
            return 1;
        }
    }
    return 0;
}

void themdt() // Thêm điện thoại vào danh sách
{
    if (soluong >= 100) {
        cout << "Danh sach da day, khong the them moi." << endl;
        return;
    }
    string madt;
    cout << "Nhap ma dien thoai: "; cin >> madt;
    if (kiemtra(madt)) {
        cout << "Dien thoai da ton tai trong danh sach!" << endl;
        return;
    }
    Dienthoai them;
    them.madt = madt;
    cout << "Nhap nhan hieu: ";
    cin.ignore();  // Xóa bộ nhớ đệm trước khi nhập chuỗi
    getline(cin, them.nhanhieu);
    cout << "Nhap gia: ";
    cin >> them.gia;
    danhsach[soluong++] = them;
    cout << "Dien thoai da duoc them vao danh sach!" << endl;
}

void timdt() // Tìm và in thông tin điện thoại theo mã 
{
    string madt;
    cout << "Nhap ma dien thoai can tim: ";
    cin >> madt;
    for (int i = 0; i < soluong; i++) {
        if (danhsach[i].madt == madt) {
            cout << "Nhan hieu: " << danhsach[i].nhanhieu << ", gia: " << danhsach[i].gia << endl;
            return;
        }
    }
    cout << "Khong tim thay dien thoai voi ma " << madt << endl;
}

void capnhatgia() // Cập nhật giá điện thoại theo mã
{
    string madt;
    cout << "Nhap ma dien thoai can cap nhat gia: ";
    cin >> madt;
    for (int i = 0; i < soluong; i++) {
        if (danhsach[i].madt == madt) {
            cout << "Nhap gia moi: ";
            cin >> danhsach[i].gia;
            cout << "Gia da duoc cap nhat!" << endl;
            return;
        }
    }
    cout << "Khong tim thay dien thoai voi ma " << madt << endl;
}

void xoadt() // Xóa điện thoại theo mã
{
    string madt;
    cout << "Nhap ma dien thoai can xoa: ";
    cin >> madt;
    for (int i = 0; i < soluong; i++) {
        if (danhsach[i].madt == madt) {
            for (int j = i; j < soluong - 1; j++) {
                danhsach[j] = danhsach[j + 1];
            }
            soluong--;
            cout << "Dien thoai da duoc xoa!" << endl;
            return;
        }
    }
    cout << "Khong tim thay dien thoai voi ma " << madt << endl;
}

void xuatdanhsach() // Xuất danh sách điện thoại
{
    if (soluong == 0) {
        cout << "Danh sach dien thoai rong!" << endl;
        return;
    }
    cout << "Danh sach dien thoai:" << endl;
    for (int i = 0; i < soluong; i++) {
        cout << "Ma dien thoai: " << danhsach[i].madt << ", nhan hieu: " << danhsach[i].nhanhieu << ", gia: " << danhsach[i].gia << endl;
    }
}

void menu() 
{
    int luachon;
    do {
        cout << "\n***** QUAN LY DIEN THOAI *****\n";
        cout << "1. Them dien thoai\n";
        cout << "2. Tim dien thoai\n";
        cout << "3. Cap nhat gia dien thoai\n";
        cout << "4. Xoa dien thoai\n";
        cout << "5. Xuat danh sach dien thoai\n";
        cout << "6. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luachon;

        switch (luachon) {
        case 1:
            themdt();
            break;
        case 2:
            timdt();
            break;
        case 3:
            capnhatgia();
            break;
        case 4:
            xoadt();
            break;
        case 5:
            xuatdanhsach();
            break;
        case 6:
            cout << "Thoat chuong trinh!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
        }
    } while (luachon != 6);
}

int main() 
{
    menu();
    return 0;
}