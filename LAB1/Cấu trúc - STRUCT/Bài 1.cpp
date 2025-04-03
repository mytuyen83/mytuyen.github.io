#include <iostream>
using namespace std;

struct NhanVien
{
	char MaSo[11], Ho[11], Ten[51];
	int Phai, ThamNien;
};

#define MAX 100

struct PhongBan
{
	NhanVien aNhanVien[MAX];
	int SoLuong;
};

void NhapPhongBan(PhongBan& pb)
{
	cout << "Nhap so luong phong ban: "; cin >> pb.SoLuong;
	while (pb.SoLuong <= 0 || pb.SoLuong > MAX) {
		cout << "Nhap sai! Nhap lai: ";
		cin >> pb.SoLuong;
	}
	cin.ignore();
	for (int i = 0;i < pb.SoLuong;i++) {
		cout << "Nhap thong tin nhan vien" << i+1 << ":\n";
		cout << "+ Ma so: "; cin.getline(pb.aNhanVien[i].MaSo,11);
		cout << "+ Ho: "; cin.getline(pb.aNhanVien[i].Ho, 11);
		cout << "+ Ten: "; cin.getline(pb.aNhanVien[i].Ten,51);
		cout << "+ Phai (0 - Nu, 1 - Nam): "; cin >> pb.aNhanVien[i].Phai;
		while (pb.aNhanVien[i].Phai != 0 && pb.aNhanVien[i].Phai !=1) {
			cout << "Nhap sai! Nhap lai: ";
			cin >> pb.aNhanVien[i].Phai;
		}
		cout << "+ Tham nien: "; cin >> pb.aNhanVien[i].ThamNien;
		while (pb.aNhanVien[i].ThamNien < 0) {
			cout << "Nhap sai! Nhap lai: ";
			cin >> pb.aNhanVien[i].ThamNien;
		}
		cin.ignore();
	}
}

void XuatPhongBan(PhongBan pb)
{
	cout << "STT\tMa so\tHo\tTen\tPhai\tTham nien\n";
	for (int i = 0;i < pb.SoLuong;i++) {
		cout << i + 1 << "\t" << pb.aNhanVien[i].MaSo << "\t" << pb.aNhanVien[i].Ho << "\t" << pb.aNhanVien[i].Ten << "\t";
		cout << (pb.aNhanVien[i].Phai == 1 ? "Nam" : "Nu") << "\t" << pb.aNhanVien[i].ThamNien << "\n";
	}
}

void DemSiSo(PhongBan ds, int& sonam, int& sonu)
{
	sonam = sonu = 0;
	for (int i = 0;i < ds.SoLuong;i++) {
		if (ds.aNhanVien[i].Phai == 1)
			sonam++;
		else 
			sonu++;
	}
}

void SapXepTangTheoThamNien(PhongBan& pb)
{
	for (int i = 0;i < pb.SoLuong-1;i++) {
		for (int j = i + 1;j < pb.SoLuong;j++) {
			if (pb.aNhanVien[i].ThamNien > pb.aNhanVien[j].ThamNien) {
				swap(pb.aNhanVien[i], pb.aNhanVien[j]);
			}
		}
	}
}

int main()
{
	PhongBan pb;
	int sonam, sonu;
	NhapPhongBan(pb);
	DemSiSo(pb, sonam, sonu);
	cout << "Phong ban co " << pb.SoLuong << " nhan vien, trong do co " << sonam << " nam va " << sonu << " nu.\n";
	cout << "Danh sach nhan vien tang dan theo tham nien:\n";
	SapXepTangTheoThamNien(pb);
	XuatPhongBan(pb);
	return 0;
}