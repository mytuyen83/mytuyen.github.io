#include <iostream>
# define MAX 100
using namespace std;

//hàm nhập mảng
void nhapmang(int* a, int& n)
{
	cout << "Nhập số lượng phẩn tử của mảng: "; cin >> n;
	if (n <= 0 || n > MAX) { //kiểm tra n có hợp lệ hay không
		cout << "Giá trị n không hợp lệ!\n";
		exit(1); //dừng chương trình ngay lập tức nếu n không hợp lệ
	}
	for (int i = 0;i < n;i++) {
		cout << "Phần tử thứ " << i << ": ";
		cin >> *(a + i);
	}
}

//kiểm tra tính chẵn lẻ
void ktchanle(int* a, int n)
{
	for (int i = 1; i < n; i++) {
		if ((*(a + i) % 2) == (*(a + i - 1) % 2)) { //so sánh số thứ i và số liền trước có cùng chẵn hoặc cùng lẻ
			cout << "Dãy không có tính chẵn lẻ.\n";
			return;
		}
	}
	cout << "Dãy có tính chẵn lẻ.\n";
}

//kiểm tra tính toàn chẵn
void kttoanchan(int* a, int n)
{
	for (int i = 0;i < n;i++) {
		if (*(a + i) % 2 != 0) { //tìm số lẻ trong mảng
			cout << "Dãy không có tính toàn chẵn.\n";
			return; //thoát vòng lặp và quay về hàm main
		}
	}
	cout << "Dãy có tính toàn chẵn.\n";
}
int main()
{
	int a[MAX], n;
	nhapmang(a, n);
	ktchanle(a, n);
	kttoanchan(a, n);
	return 0;
}