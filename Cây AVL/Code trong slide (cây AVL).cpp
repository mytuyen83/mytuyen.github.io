#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
    int height;
    int count;
};

// Tạo một node mới
Node* CreateNode(int theKey, Node* left = NULL, Node* right = NULL) {
    Node* p = new Node;
    p->info = theKey;
    p->height = 1;
    p->right = right;
    p->left = left;
    p->count = 1;
    return p;
}

// Lấy chiều cao của node
int GetHeight(Node* p) {
    return (p == NULL) ? 0 : p->height;
}

// Cập nhật chiều cao của node
void UpdateHeight(Node* p) {
    if (p) {
        p->height = 1 + max(GetHeight(p->left), GetHeight(p->right));
    }
}

// Quay phải
Node* RotateRight(Node* y) {
    Node* x = y->left;
    Node* T = x->right;

    x->right = y;
    y->left = T;

    UpdateHeight(y);
    UpdateHeight(x);

    return x;
}

// Quay trái
Node* RotateLeft(Node* x) {
    Node* y = x->right;
    Node* T = y->left;

    y->left = x;
    x->right = T;

    UpdateHeight(x);
    UpdateHeight(y);

    return y;
}

// Lấy hệ số cân bằng
int GetBalance(Node* p) {
    return (p == NULL) ? 0 : GetHeight(p->left) - GetHeight(p->right);
}

// Chèn node vào cây AVL
Node* Insert(Node* root, int key) {
    if (root == NULL) return CreateNode(key);

    if (key < root->info)
        root->left = Insert(root->left, key);
    else if (key > root->info)
        root->right = Insert(root->right, key);
    else {
        root->count++; // Nếu key đã tồn tại, tăng biến đếm
        return root;
    }

    UpdateHeight(root);
    int balance = GetBalance(root);

    // Xử lý mất cân bằng
    if (balance > 1 && key < root->left->info) return RotateRight(root);
    if (balance < -1 && key > root->right->info) return RotateLeft(root);
    if (balance > 1 && key > root->left->info) {
        root->left = RotateLeft(root->left);
        return RotateRight(root);
    }
    if (balance < -1 && key < root->right->info) {
        root->right = RotateRight(root->right);
        return RotateLeft(root);
    }

    return root;
}

// Tìm kiếm node trong cây AVL
Node* Find(Node* root, int key) {
    if (root == NULL || root->info == key)
        return root;
    if (key < root->info)
        return Find(root->left, key);
    return Find(root->right, key);
}

// Tìm node có giá trị nhỏ nhất
Node* FindMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Xóa node khỏi cây AVL
Node* Delete(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->info)
        root->left = Delete(root->left, key);
    else if (key > root->info)
        root->right = Delete(root->right, key);
    else {
        if (root->count > 1) {
            root->count--;
            return root;
        }

        if (root->left == NULL || root->right == NULL) {
            Node* temp = (root->left) ? root->left : root->right;
            delete root;
            return temp;
        }
        Node* temp = FindMin(root->right);
        root->info = temp->info;
        root->count = temp->count;
        temp->count = 1;
        root->right = Delete(root->right, temp->info);
    }

    if (root == NULL) return root;

    UpdateHeight(root);
    int balance = GetBalance(root);

    if (balance > 1 && GetBalance(root->left) >= 0) return RotateRight(root);
    if (balance > 1 && GetBalance(root->left) < 0) {
        root->left = RotateLeft(root->left);
        return RotateRight(root);
    }
    if (balance < -1 && GetBalance(root->right) <= 0) return RotateLeft(root);
    if (balance < -1 && GetBalance(root->right) > 0) {
        root->right = RotateRight(root->right);
        return RotateLeft(root);
    }
    return root;
}

// Hiển thị node
void DisplayNode(Node* p, int i) {
    if (p == NULL) return;
    for (int j = 1; j <= i; j++)
        cout << " ";
    cout << p->info << ":" << p->height << endl;
}

// Hàm kiểm tra cây AVL
void TestAVL() {
    Node* root = NULL;
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 30);
    root = Insert(root, 40);
    root = Insert(root, 50);
    root = Insert(root, 25);

    cout << "Duyệt cây theo thứ tự NLR:" << endl;
    PreOrder(root, 0);

    cout << "\nDuyệt cây theo thứ tự LNR:" << endl;
    InOrder(root, 0);

    cout << "\nDuyệt cây theo thứ tự LRN:" << endl;
    PostOrder(root, 0);
}

int main() {
    TestAVL();
    return 0;
}
