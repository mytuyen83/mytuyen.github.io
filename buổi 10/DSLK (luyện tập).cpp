#include <iostream>
using namespace std;

struct Nut {
    int duLieu;
    Nut* keTiep;
};

class DanhSachLienKet {
private:
    Nut* dau;
public:
    DanhSachLienKet() { dau = nullptr; }
    ~DanhSachLienKet() { xoaTatCa(); }

    void them(int giaTri) {
        Nut* nutMoi = new Nut{ giaTri, nullptr };
        if (!dau) {
            dau = nutMoi;
        }
        else {
            Nut* tam = dau;
            while (tam->keTiep) tam = tam->keTiep;
            tam->keTiep = nutMoi;
        }
    }

    void xoa(int giaTri) {
        if (!dau) return;
        while (dau && dau->duLieu == giaTri) {
            Nut* tam = dau;
            dau = dau->keTiep;
            delete tam;
        }
        Nut* tam = dau;
        while (tam && tam->keTiep) {
            if (tam->keTiep->duLieu == giaTri) {
                Nut* canXoa = tam->keTiep;
                tam->keTiep = tam->keTiep->keTiep;
                delete canXoa;
            }
            else {
                tam = tam->keTiep;
            }
        }
    }

    void gop(DanhSachLienKet& dsKhac) {
        if (!dsKhac.dau) return;
        if (!dau) {
            dau = dsKhac.dau;
        }
        else {
            Nut* tam = dau;
            while (tam->keTiep) tam = tam->keTiep;
            tam->keTiep = dsKhac.dau;
        }
        dsKhac.dau = nullptr;
    }

    void hienThi() {
        Nut* tam = dau;
        while (tam) {
            cout << tam->duLieu << " ";
            tam = tam->keTiep;
        }
        cout << endl;
    }

    void xoaTatCa() {
        while (dau) {
            Nut* tam = dau;
            dau = dau->keTiep;
            delete tam;
        }
    }
};

int main() {
    DanhSachLienKet ds1;
    cout << "Nhập 10 số nguyên: ";
    for (int i = 0; i < 10; i++) {
        int so;
        cin >> so;
        ds1.them(so);
    }

    cout << "Danh sách 1: ";
    ds1.hienThi();

    int k;
    cout << "Nhập số cần xóa: ";
    cin >> k;
    ds1.xoa(k);

    cout << "Danh sách sau khi xóa: ";
    ds1.hienThi();

    DanhSachLienKet ds2;
    cout << "Nhập 5 số nguyên vào danh sách thứ hai: ";
    for (int i = 0; i < 5; i++) {
        int so;
        cin >> so;
        ds2.them(so);
    }

    ds1.gop(ds2);
    cout << "Danh sách sau khi gộp: ";
    ds1.hienThi();

    return 0;
}
