#include <iostream>
using namespace std;

struct node
{
	int info;
	struct node* pLeft;
	struct node* pRight;
};

typedef struct node NODE;
typedef NODE* TREE;

void InsertNode(TREE& Root, int x)
{
	if (Root == NULL)
	{
		Root = new NODE;
		Root->info = x;
		Root->pLeft = NULL;
		Root->pRight = NULL;
	}
	else if (x < Root->info)
		InsertNode(Root->pLeft, x);
	else
		InsertNode(Root->pRight, x);
}

TREE CreateTree(int arr[], int n)
{
	TREE Root = NULL;
	for (int i = 0; i < n; i++)
	{
		InsertNode(Root, arr[i]);
	}
	return Root;
}

// Trung bình cộng các nút trong cây
int DemNode(TREE Root)
{
	if (Root == NULL)
		return 0;
	int a = DemNode(Root->pLeft);
	int b = DemNode(Root->pRight);
	return (a + b + 1);
}

int TongNode(TREE Root)
{
	if (Root == NULL)
		return 0;
	int a = TongNode(Root->pLeft);
	int b = TongNode(Root->pRight);
	return (a + b + Root->info);
}

float TrungBinhCong(TREE Root)
{
	int s = TongNode(Root);
	int dem = DemNode(Root);
	if (dem == 0)
		return 0;
	return (float)s / dem;
}

// Trung bình cộng các nút dương trong cây
int DemDuong(TREE Root)
{
	if (Root == NULL)
		return 0;
	int a = DemDuong(Root->pLeft);
	int b = DemDuong(Root->pRight);
	if (Root->info > 0)
		return (a + b + 1);
	return (a + b);
}

int TongDuong(TREE Root)
{
	if (Root == NULL)
		return 0;
	int a = TongDuong(Root->pLeft);
	int b = TongDuong(Root->pRight);
	if (Root->info > 0)
		return (a + b + Root->info);
	return (a + b + (Root->info < 0 ? Root->info : 0));
}

float TrungBinhDuong(TREE Root)
{
	int s = TongDuong(Root);
	int dem = DemDuong(Root);
	if (dem == 0)
		return 0;
	return (float)s / dem;
}

// Trung bình cộng các nút âm
int DemAm(TREE Root)
{
	if (Root == NULL)
		return 0;
	int a = DemAm(Root->pLeft);
	int b = DemAm(Root->pRight);
	if (Root->info < 0)
		return (a + b + 1);
	return (a + b + (Root->info < 0 ? Root->info : 0));
}

int TongAm(TREE Root)
{
	if (Root == NULL)
		return 0;
	int a = TongAm(Root->pLeft);
	int b = TongAm(Root->pRight);
	if (Root->info < 0)
		return (a + b + Root->info);
	return (a + b);
}

float TrungBinhAm(TREE Root)
{
	int s = TongAm(Root);
	int dem = DemAm(Root);
	if (dem == 0)
		return 0;
	return (float)s / dem;
}

// Tỉ số R=a/b
float TinhTySo(TREE Root)
{
	int a = TongDuong(Root);
	int b = TongAm(Root);
	if (b == 0)
		return 0;
	return (float)a / b;
}

void Test()
{
	int a[] = { 3, -2, 5, 7, -8, 10, -4 };
	int n = sizeof(a) / sizeof(a[0]);
	TREE Root = CreateTree(a, n);

	cout << "Trung binh cong toan bo nut: " << TrungBinhCong(Root) << endl;
	cout << "Trung binh cong cac nut duong: " << TrungBinhDuong(Root) << endl;
	cout << "Trung binh cong cac nut am: " << TrungBinhAm(Root) << endl;
	cout << "Ti so tong duong / tong am: " << TinhTySo(Root) << endl;
}

int main()
{
	Test();
	return 0;
}