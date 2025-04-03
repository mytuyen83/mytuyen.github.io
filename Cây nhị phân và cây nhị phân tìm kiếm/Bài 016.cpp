#include <iostream>
using namespace std;

struct BST_NODE {
    int Key; // Khóa của nút
    int So_lan; // Số lần xuất hiện
    BST_NODE* Left, * Right;
};

struct BST_TREE {
    BST_NODE* pRoot; // Nút gốc của cây
};

void CreateTree(BST_TREE& t) {
    t.pRoot = NULL;
}

BST_NODE* CreateNode(int x) {
    BST_NODE* p = new BST_NODE;
    p->Key = x;
    p->So_lan = 1;
    p->Left = p->Right = NULL;
    return p;
}

void InsertNode(BST_TREE& t, int x) {
    BST_NODE* p = t.pRoot, * prev = NULL;
    while (p != NULL) {
        if (p->Key == x) {
            p->So_lan++;
            return;
        }
        prev = p;
        if (x < p->Key)
            p = p->Left;
        else
            p = p->Right;
    }
    BST_NODE* newNode = CreateNode(x);
    if (prev == NULL)
        t.pRoot = newNode;
    else if (x < prev->Key)
        prev->Left = newNode;
    else
        prev->Right = newNode;
}

int DeleteNode(BST_NODE* Root, int x) {
    if (Root == NULL)
        return 0;
    if (Root->Key == x) {
        if (Root->So_lan > 0) {
            Root->So_lan--;
            return 1;
        }
        return 0;
    }
    if (x < Root->Key)
        return DeleteNode(Root->Left, x);
    return DeleteNode(Root->Right, x);
}

void XoaGiaTri(BST_TREE t, int X) {
    int kq = DeleteNode(t.pRoot, X);
    if (kq == 0)
        cout << "Khong ton tai X.\n";
    else
        cout << "Xoa thanh cong.\n";
}

void NLR(BST_NODE* Root) {
    if (Root == NULL)
        return;
    if (Root->So_lan > 0)
        cout << " " << Root->Key;
    NLR(Root->Left);
    NLR(Root->Right);
}

void LietKe(BST_TREE t) {
    NLR(t.pRoot);
}

void Test() {
    BST_TREE t;
    CreateTree(t);

    InsertNode(t, 50);
    InsertNode(t, 30);
    InsertNode(t, 70);
    InsertNode(t, 20);
    InsertNode(t, 40);
    InsertNode(t, 60);
    InsertNode(t, 80);
    InsertNode(t, 30);

    cout << "Cay sau khi chen: ";
    LietKe(t);
    cout << endl;

    XoaGiaTri(t, 30);
    XoaGiaTri(t, 50);
    XoaGiaTri(t, 90); // Giá trị không tồn tại

    cout << "Cay sau khi xoa: ";
    LietKe(t);
}

int main() 
{
    Test();
    return 0;
}