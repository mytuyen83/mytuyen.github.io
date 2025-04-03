#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct SinhVien {
    int maso;
    string hovadem;
    string ten;
    int ngay, thang, nam;
    string phai;
    float diemTB;
};

void Nhapdanhsach(SinhVien *&ds, int &n)
{
    cout << "Nhap so luong sinh vien: "; cin >> n;
    ds = new SinhVien[n]; //cấp phát mảng động cho danh sách sinh viên

    for (int i = 0;i < n;i++) {
        cout << "Nhap ma so sinh vien: ";
        cin >> ds[i].maso;
        cin.ignore(); //Bỏ qua ký tự '\n' khi nhấn enter, nếu không chuỗi ký tự phía sau nhập vào sẽ thành chuỗi rỗng
        cout << "Nhap ho va dem: ";
        getline(cin, ds[i].hovadem);
        cout << "Nhap ten: ";
        getline(cin, ds[i].ten);
        cout << "Nhap ngay, thang, nam sinh (dd mm yyyy): ";
        cin >> ds[i].ngay >> ds[i].thang >> ds[i].nam;
        cin.ignore();
        cout << "Nhap phai (Nam/Nữ): ";
        getline(cin, ds[i].phai);
        cout << "Nhap diem trung binh: ";
        cin >> ds[i].diemTB;
        cin.ignore();
    }
}

void ghivaofile(SinhVien* ds, int n) 
{
    ofstream file("SINHVIEN.DAT"); //mở file để ghi dưới dạng văn bản
    for (int i = 0;i < n;i++) {
        file << ds[i].maso << '\n';
        file << ds[i].hovadem << '\n';
        file << ds[i].ten << '\n';
        file << ds[i].ngay << ' ' << ds[i].thang << ' ' << ds[i].nam << '\n';
        file << ds[i].phai << '\n';
        file << ds[i].diemTB << '\n';
    }
    file.close();
}

void sapxepmaso(SinhVien* ds, int n) 
{
    //sử dụng bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ds[j].maso > ds[j + 1].maso) {
                SinhVien temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}

void in(SinhVien* ds, int n) 
{
    cout << "\nDanh sách sinh viên:\n";
    for (int i = 0; i < n; i++) {
        cout << "Ma so: " << ds[i].maso << "\n";
        cout << "Ho va dem: " << ds[i].hovadem << "\n";
        cout << "Ten: " << ds[i].ten << "\n";
        cout << "Ngay, thang, nam sinh: " << ds[i].ngay << "/" << ds[i].thang << "/" << ds[i].nam << "\n";
        cout << "Phai: " << ds[i].phai << "\n";
        cout << "Diem trung binh: " << ds[i].diemTB << "\n";
        cout << "\n-------------------------------\n";
    }
}

void chimucmaso(SinhVien* ds, int n) 
{
    ofstream file("SVMASO.IDX");
    for (int i = 0; i < n; i++) {
        file << ds[i].maso << '\n';
    }
    file.close();
}

void sapxepten(SinhVien* ds, int n)
{
    //sử dụng selection sort
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (ds[j].ten < ds[min].ten || (ds[j].ten == ds[min].ten && ds[j].hovadem < ds[min].hovadem)) {
                min = j;
            }
        }
        if (min != i) {
            SinhVien temp = ds[i];
            ds[i] = ds[min];
            ds[min] = temp;
        }
    }
}

void chimucten(SinhVien* ds, int n)
{
    ofstream file("SVTH.IDX");
    for (int i = 0; i < n; i++) {
        file << ds[i].ten << " " << ds[i].hovadem << '\n';
    }
    file.close();
}

void sapxepdiemtb(SinhVien* ds, int n)
{
    for (int i = 1; i < n; i++) {
        SinhVien temp = ds[i];
        int j = i - 1;
        while (j >= 0 && ds[j].diemTB < temp.diemTB) {
            ds[j + 1] = ds[j];
            j--;
        }
        ds[j + 1] = temp;
    }
}

void chimucdiemtb(SinhVien* ds, int n)
{
    ofstream file("SVDTB.IDX");
    for (int i = 0; i < n; i++) {
        file << ds[i].diemTB << '\n';
    }
    file.close();
}

void docfile(SinhVien*& ds, int& n) 
{
    ifstream file("SINHVIEN.DAT"); // mở file để đọc
    if (!file) {
        cout << "Khong the mo file SINHVIEN.DAT!\n";
        return;
    }

    file >> n; // đọc số lượng sinh viên trong danh sách
    file.ignore();
    ds = new SinhVien[n]; // cấp phát mảng động cho danh sách

    for (int i = 0; i < n; i++) {
        file >> ds[i].maso;
        file.ignore(); //bỏ qua ký tự '\n' khi enter
        getline(file, ds[i].hovadem);
        getline(file, ds[i].ten);
        file >> ds[i].ngay >> ds[i].thang >> ds[i].nam;
        file.ignore();
        getline(file, ds[i].phai);
        file >> ds[i].diemTB;
        file.ignore();
    }
    file.close();
}

void docchimucmaso(SinhVien* ds, int n) 
{
    ifstream file("SVMASO.IDX"); //mở file chỉ mục để đọc
    if (!file) {
        cout << "Khong the mo file SVMASO.IDX!\n";
        return;
    }

    cout << "\nDanh sach theo thu tu ma so:\n";
    int mso;
    while (file >> mso) {
        for (int i = 0; i < n; i++) {
            if (ds[i].maso == mso) {
                cout << ds[i].maso << " - " << ds[i].hovadem << " " << ds[i].ten << " - " << ds[i].diemTB << '\n';
                break;
            }
        }
    }
    file.close();
}

void docchimucten(SinhVien* ds, int n) {
    ifstream file("SVTH.IDX");
    if (!file) {
        cout << "Khong the mo file SVTH.IDX!\n";
        return;
    }

    cout << "\nDanh sach theo thu tu ten:\n";
    string hoten;
    while (getline(file, hoten)) {
        for (int i = 0; i < n; i++) {
            if (hoten == ds[i].ten + " " + ds[i].hovadem) {
                cout << ds[i].maso << " - " << ds[i].hovadem << " " << ds[i].ten << " - " << ds[i].diemTB << '\n';
                break;
            }
        }
    }
    file.close();
}

void docchimucdiemtb(SinhVien* ds, int n) {
    ifstream file("SVDTB.IDX");
    if (!file) {
        cout << "Khong the mo file SVDTB.IDX!\n";
        return;
    }

    cout << "\nDanh sach theo thu tu diem trung binh:\n";
    float dtb;
    int mso;
    while (file >> dtb >> mso) {
        for (int i = 0; i < n; i++) {
            if (ds[i].maso == mso) {
                cout << ds[i].maso << " - " << ds[i].hovadem << " " << ds[i].ten << " - " << ds[i].diemTB << '\n';
                break;
            }
        }
    }
    file.close();
}

int main()
{
    SinhVien* ds = NULL; //vì nó chưa trỏ đến vùng nhớ nào nên phải gán nó bằng null
    int n;
    //câu a
    Nhapdanhsach(ds, n);
    ghivaofile(ds, n);
    //câu b
    sapxepmaso(ds, n);
    in(ds, n);
    //câu c, d
    chimucmaso(ds, n);
    sapxepten(ds, n);
    chimucten(ds, n);
    sapxepdiemtb(ds, n);
    chimucdiemtb(ds, n);
    //câu e
    docfile(ds, n);
    docchimucmaso(ds, n);
    docchimucten(ds, n);
    docchimucdiemtb(ds, n);

	return 0;
}