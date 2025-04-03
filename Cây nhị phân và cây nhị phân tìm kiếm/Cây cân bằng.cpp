#include <iostream>
using namespace std;

struct node {
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

TREE CreateTree(int a[], int n)
{
    TREE Root = NULL;
    for (int i = 0; i < n; i++)
    {
        InsertNode(Root, a[i]);
    }
    return Root;
}

NODE * LonNhat(TREE t) {
    if (t == NULL)
        return NULL;
    NODE * lc = t;
    NODE * a = LonNhat(t->pLeft);
    if (a && a->info > lc->info)
        lc = a;
    NODE * b = LonNhat(t->pRight);
    if (b && b->info > lc->info)
        lc = b;
    return lc;
}

NODE * NhoNhat(TREE t)
{
    if (t == NULL)
        return NULL;
    NODE * lc = t;
    NODE * a = NhoNhat(t->pLeft);
    if (a && a->info < lc->info)
        lc = a;
    NODE * b = NhoNhat(t->pRight);
    if (b && b->info < lc->info)
        lc = b;
    return lc;
}

int ChieuCao(TREE t)
{
    if (t == NULL)
        return 0;
    int a = ChieuCao(t->pLeft);
    int b = ChieuCao(t->pRight);
    if (a > b)
        return a + 1;
    return b + 1;
}

int ktCanBang(TREE Root)
{
    if (Root == NULL)
        return 1;
    if (ktCanBang(Root->pLeft) == 0)
        return 0;
    if (ktCanBang(Root->pRight) == 0)
        return 0;
    NODE * a = LonNhat(Root->pLeft);
    if (a && a->info > Root->info)
        return 0;
    a = NhoNhat(Root->pRight);
    if (a && a->info < Root->info)
        return 0;
    int x = ChieuCao(Root->pLeft);
    int y = ChieuCao(Root->pRight);
    if (abs(x - y) > 1)
        return 0;
    return 1;
}

void test() 
{
    int a[] = { 50, 30, 70, 20, 40, 60, 80 };
    int n = sizeof(a) / sizeof(a[0]);

    TREE Root = CreateTree(a, n);

    cout << "Node lon nhat: " << LonNhat(Root)->info << endl;
    cout << "Node nho nhat: " << NhoNhat(Root)->info << endl;
    cout << "Chieu cao cay: " << ChieuCao(Root) << endl;

    if (ktCanBang(Root))
        cout << "Cay can bang." << endl;
    else
        cout << "Cay khong can bang." << endl;
}

int main() {
    test();
    return 0;
}