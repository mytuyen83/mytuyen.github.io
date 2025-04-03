#include <iostream>
using namespace std; 

typedef struct node
{
	int info;
	struct node* next;
} Node;

Node* pHead = NULL;

bool IsEmpty(Node* pHead)
{
	// kiểm tra danh sách rỗng
	return (pHead == NULL);
}

void Init(Node* &pHead)
{
	// khởi tạo danh sách liên kết
	pHead = NULL;
}

Node* CreateNode(int x)
{
	Node* p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}

void ShowList(Node* pHead)
{
	if (pHead == NULL)
		cout << "Danh sach rong\n";
	else
		for (Node* p = pHead;p != NULL;p = p->next)
			cout << p->info;
}

Node* Find(Node* pHead, int x)
{
	//x là nội dung cần tìm
	bool found = false;
	Node* p = pHead;
	while ((p != NULL) && (!found))
	{
		if (p->info == x)
			found = true;
		else
			p = p->next;
	}
	if (!found)
		p = NULL;
	return p;
}

Node* FindOrder(Node* pHead, int x)
{
	//Tìm x trong danh sách đã có thứ tự
	bool found = false;
	Node* p = pHead;
	while ((p != NULL) && (!found))
	{
		if (p->info == x)
			found = true;
		else if (p->info < x)
			p = p->next;
		else
			p = NULL;
	}
	if (!found)
		p = NULL;
	return p;
}

void InsertFirst(Node*& pHead, int x)
{
	Node* p = CreateNode(x);
	p->next = pHead;
	pHead = p;
}

void InsertAfter(Node* p, int x)
{
	if (p != NULL) {
		//Thêm vào ngay sau item
		Node* q = CreateNode(x);
		q->next = p->next;
		p->next = q;
	}
}

void InsertOrder(Node*& pHead, int x)
{
	//Thêm x vào danh sách có thứ tự tăng dần
	Node* tp;
	Node* p = pHead;
	bool cont = true;
	while ((p != NULL) && cont) {
		if (p->info < x) {
			tp = p;
			p->next;
		}
		else cont = false;
		//xen nút q vào giữa nút p và nút tp
	}
	if (p == pHead)
		InsertFirst(pHead, x);
	else
		InsertAfter(tp, x);
}

void DeleteFirst(Node*& pHead)
{
	if (IsEmpty(pHead))
		cout << "List is empty!";
	else {
		Node* p = pHead;
		pHead = pHead->next;
		delete p;
	}
}

void DeleteAfter(Node* p)
{
	//Thêm x vào danh sách có thứ tự tăng dần
	if (p == NULL || p->next == NULL)
		//kiểm tra nút sau p có tồn tại không
		cout << "Khong the xoa nut nay!";
	else {
		Node* q = p->next;
		p->next = q->next;
		delete q;
	}
}

Node* Remove(Node*& pHead, int x)
//Tìm và bỏ x trong danh sách first chưa có thứ tự
{
	Node* tp;
	Node* p = pHead;
	bool found = false;
	while ((p != NULL) && (!found)) {
		if (p->info != x) {
			tp = p;
			p = p->next;
		}
		else
			found = true;
	}
	if (found) {
		if (p == pHead) //Loại bỏ phần tử đầu tiên
			pHead = p->next;
		else
			tp->next = p->next;
		delete p;
	}
}

Node* RemoveOrder(Node*& pHead, int x)
//Tìm và bỏ x trong danh schs first đã có thứ tự
{
	Node* tp;
	Node* p = pHead;
	bool found = false;
	while ((p != NULL) && (!found)) {
		if (p->info < x) {
			tp = p;
			p = p->next;
		}
		else if (p->info == x) found = true;
		else p = NULL;
	}
	if (found) {
		if (p == pHead) //Loại bỏ phần tử đầu tiên
			pHead = p->next;
		else
			tp->next = p->next;
		delete p;
	}
}

void ClearList(Node*& pHead)
//Xoá toàn bộ danh sách
{
	Node* p;
	while (pHead != NULL) {
		p = pHead;
		pHead = p->next;
		delete p;
	} //hết while
} //hết ClearList

void SelectionSort(Node*& pHead)
//Sắp xếp danh sách tăng dần
{
	Node* p, * q, * pmin;
	int vmin;
	for (p = pHead;p->next != NULL;p = p->next) {
		vmin = p->info;
		pmin = p;
		for (q = p->next;q != NULL;q = q->next) {
			if (q->info < vmin) {
				vmin = q->info;
				pmin = q;
			} //hết if
		} //hết for q
		pmin->info = p->info;
		p->info = vmin;
	} //hết for p
} //hết sort

void Test() 
{
	cout << "\nTest 1: Kiem tra danh sach rong\n";
	Init(pHead);
	cout << "Danh sach rong? " << (IsEmpty(pHead) ? "Dung" : "Sai") << endl;

	cout << "\nTest 2: Them phan tu vao dau danh sach\n";
	InsertFirst(pHead, 10);
	InsertFirst(pHead, 20);
	InsertFirst(pHead, 30);
	cout << "Danh sach sau khi them: ";
	ShowList(pHead);

	cout << "\nTest 3: Kiem tra danh sach rong sau khi them\n";
	cout << "Danh sach rong? " << (IsEmpty(pHead) ? "Dung" : "Sai") << endl;
}

int main()
{
	Test();
	return 0;
}