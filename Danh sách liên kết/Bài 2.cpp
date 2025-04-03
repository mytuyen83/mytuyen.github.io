#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
	string hoten;
	string diachi;
	string lop;
	int khoa;
	SinhVien* next;
};

void nhap(SinhVien& sv)
{
	cout << "Nhap ho ten: "; getline(cin, sv.hoten);
	cout << "Nhap dia chi: "; getline(cin, sv.diachi);
	cout << "Nhap lop: "; getline(cin, sv.lop);
	cout << "Nhap khoa: "; cin >> sv.khoa; 
	cin.ignore();
}

void xuat(const SinhVien& sv) 
{
	cout << "Ho ten: " << sv.hoten << ", Dia chi: " << sv.diachi << ", Lop: " << sv.lop << ", Khoa: " << sv.khoa << endl;
}

bool sshoten(const SinhVien& a, const SinhVien& b) 
{
	return a.hoten < b.hoten;
}

bool ssdiachi(const SinhVien& a, const SinhVien& b)
{
	return a.diachi < b.diachi;
}

bool sslop(const SinhVien& a, const SinhVien& b)
{
	return a.lop < b.lop;
}

bool sskhoa(const SinhVien& a, const SinhVien& b)
{
	return a.khoa < b.khoa;
}

typedef	bool(*SoSanh)(const SinhVien&, const SinhVien&);

class dssinhvien {
private:
	SinhVien* head;
public:
	dssinhvien() : head(NULL) {}
	~dssinhvien();
	void them(const SinhVien& sv);
	void xoa(const string& gtri, bool t);
	void themds(const dssinhvien& dskhac);
	void xuatds() const;
	void sapxep(SoSanh cmp);
};

dssinhvien::~dssinhvien() {
	SinhVien* hientai = head;
	while (hientai) {
		SinhVien* temp = hientai;
		hientai = hientai->next;
		delete temp;
	}
}

void dssinhvien::them(const SinhVien& sv)
{
	if (!head) {
		head = new SinhVien{ sv.hoten, sv.diachi, sv.lop, sv.khoa, NULL };
		return;
	}

	SinhVien* temp = head;
	while (temp) {
		if (temp->hoten == sv.hoten) { // Kiểm tra trùng tên
			cout << "Sinh vien da ton tai trong danh sach!\n";
			return;
		}
		temp = temp->next;
	}

	SinhVien* moi = new SinhVien{ sv.hoten, sv.diachi, sv.lop, sv.khoa, NULL };
	if (!head) {
		head = moi;
	}
	else {
		temp = head;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = moi;
	}
}

void dssinhvien::xoa(const string& gtri, bool t)
{
	if (!head) return; // Nếu danh sách rỗng thì thoát ngay

	SinhVien* hientai = head;
	SinhVien* truoc = NULL;
	while (hientai) {
		if ((t && hientai->hoten == gtri) || (!t && hientai->diachi == gtri)) {
			if (!truoc) {
				head = hientai->next;
			}
			else {
				truoc->next = hientai->next;
			}
			delete hientai;
			cout << "Da xoa sinh vien!\n";
			return;
		}
		truoc = hientai;
		hientai = hientai->next;
	}
	cout << "Khong tim thay sinh vien!\n";
}

void dssinhvien::themds(const dssinhvien& dskhac)
{
	SinhVien* temp = dskhac.head;
	while (temp) {
		them(*temp);
		temp = temp->next;
	}
}

void dssinhvien::xuatds() const
{
	SinhVien* temp = head;
	while (temp) {
		xuat(*temp);
		temp = temp->next;
	}
}

void dssinhvien::sapxep(SoSanh cmp) 
{
	for (SinhVien* i = head; i && i->next; i = i->next) {
		SinhVien* min = i;
		for (SinhVien* j = i->next; j; j = j->next) {
			if (cmp(*j, *min)) {
				min = j;
			}
		}
		if (min != i) {
			swap(i->hoten, min->hoten);
			swap(i->diachi, min->diachi);
			swap(i->lop, min->lop);
			swap(i->khoa, min->khoa);
		}
	}
}

int main() 
{
	dssinhvien danhsach;
	for (int i = 0; i < 10; ++i) {
		SinhVien sv;
		nhap(sv);
		danhsach.them(sv);
	}
	danhsach.xuatds();

	danhsach.xoa("Nguyen Van Teo", true); // Xóa theo tên
	danhsach.xoa("Nguyen Van Cu", false); // Xóa theo địa chỉ
	danhsach.xuatds();

	SinhVien svmoi{ "Tran Thi Mo", "25 Hong Bang", "TT0901", 2009, NULL };
	danhsach.them(svmoi);

	danhsach.sapxep(sshoten);
	danhsach.xuatds();

	return 0;
}
