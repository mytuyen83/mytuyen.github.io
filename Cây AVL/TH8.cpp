#include <iostream>
using namespace std;

struct Node {
    int giatri;
    Node* left;
    Node* right;
    int chieucao;
};

int chieucao(Node* n) 
{
    if (n != NULL)
        return n->chieucao;
    else
        return 0;
}

int canbang(Node* n) 
{
    if (n)
        return chieucao(n->left) - chieucao(n->right);
    else
        return 0;
}

Node* CreateNode(int giatri) 
{
    Node* moi = new Node{ giatri, NULL, NULL, 1 };
    return moi;
}

Node* XoayPhai(Node* y) 
{
    Node* x = y->left;
    Node* temp = x->right;

    x->right = y;
    y->left = temp;

    y->chieucao = max(chieucao(y->left), chieucao(y->right)) + 1;
    x->chieucao = max(chieucao(x->left), chieucao(x->right)) + 1;

    return x;
}

Node* XoayTrai(Node* x) 
{
    Node* y = x->right;
    Node* temp = y->left;

    y->left = x;
    x->right = temp;

    x->chieucao = max(chieucao(x->left), chieucao(x->right)) + 1;
    y->chieucao = max(chieucao(y->left), chieucao(y->right)) + 1;

    return y;
}

Node* them(Node* root, int giatri) 
{
    if (!root) return CreateNode(giatri);

    if (giatri < root->giatri)
        root->left = them(root->left, giatri);
    else if (giatri > root->giatri)
        root->right = them(root->right, giatri);
    else
        return root;

    root->chieucao = 1 + max(chieucao(root->left), chieucao(root->right));

    int cb = canbang(root);

    if (cb > 1 && giatri < root->left->giatri)
        return XoayPhai(root);
    if (cb < -1 && giatri > root->right->giatri)
        return XoayTrai(root);
    if (cb > 1 && giatri > root->left->giatri) {
        root->left = XoayTrai(root->left);
        return XoayPhai(root);
    }
    if (cb < -1 && giatri < root->right->giatri) {
        root->right = XoayPhai(root->right);
        return XoayTrai(root);
    }

    return root;
}

Node* nhonhat(Node* node) 
{
    Node* hientai = node;
    while (hientai->left)
        hientai = hientai->left;
    return hientai;
}

Node* xoa(Node* root, int giatri) 
{
    if (!root) return root;

    if (giatri < root->giatri)
        root->left = xoa(root->left, giatri);
    else if (giatri > root->giatri)
        root->right = xoa(root->right, giatri);
    else {
        if (!root->left || !root->right) {
            Node* tam = root->left ? root->left : root->right;
            delete root;
            return tam;
        }
        Node* temp = nhonhat(root->right);
        root->giatri = temp->giatri;
        root->right = xoa(root->right, temp->giatri);
    }

    root->chieucao = 1 + max(chieucao(root->left), chieucao(root->right));

    int cb = canbang(root);

    if (cb > 1 && canbang(root->left) >= 0)
        return XoayPhai(root);
    if (cb > 1 && canbang(root->left) < 0) {
        root->left = XoayTrai(root->left);
        return XoayPhai(root);
    }
    if (cb < -1 && canbang(root->right) <= 0)
        return XoayTrai(root);
    if (cb < -1 && canbang(root->right) > 0) {
        root->right = XoayPhai(root->right);
        return XoayTrai(root);
    }

    return root;
}

void in(Node* root) 
{
    if (root) {
        in(root->left);
        cout << root->giatri << " ";
        in(root->right);
    }
}

void test() 
{
    Node* root = NULL;
    root = them(root, 10);
    root = them(root, 20);
    root = them(root, 30);
    root = them(root, 40);
    root = them(root, 50);
    root = them(root, 25);

    cout << "Cay AVL sau khi them: ";
    in(root);
    cout << endl;

    root = xoa(root, 30);
    cout << "Cay AVL sau khi xoa 30: ";
    in(root);
    cout << endl;
}

int main() 
{
    test();
    return 0;
}
