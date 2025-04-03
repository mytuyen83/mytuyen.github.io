#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void NLR(Node* root) {
    if (!root) return;
    stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
        Node* hientai = s.top();
        s.pop();
        cout << hientai->data << " ";
        if (hientai->right) s.push(hientai->right); // Push right trước
        if (hientai->left) s.push(hientai->left);   // Push left sau để đảm bảo thứ tự NLR
    }
}

void theomuc(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* hientai = q.front();
        q.pop();
        cout << hientai->data << " ";
        if (hientai->left) q.push(hientai->left);
        if (hientai->right) q.push(hientai->right);
    }
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    cout << "Duyet NLR khong dung de quy: ";
    NLR(root);
    cout << endl;

    cout << "Duyet theo muc khong dung de quy: ";
    theomuc(root);
    cout << endl;

    return 0;
}
