#include <iostream>
using namespace std;

// Cài đặt hàng đợi bằng mảng động
class QueueInt {
private:
    int* a;
    int dau, cuoi, succhua;
public:
    QueueInt(int size) {
        succhua = size;
        a = new int[succhua];
        dau = cuoi = -1;
    }
    ~QueueInt() { delete[] a; }
    bool IsEmpty() { return dau == -1; }
    bool IsFull() { return cuoi == succhua - 1; }
    void PushStack(int x) {
        if (IsFull()) return;
        if (IsEmpty()) dau = 0;
        a[++cuoi] = x;
    }
    int PopStack() {
        if (IsEmpty()) return -1;
        int x = a[dau];
        if (dau == cuoi) dau = cuoi = -1;
        else dau++;
        return x;
    }
    void Clear() { dau = cuoi = -1; }
};

// Cài đặt hàng đợi bằng danh sách liên kết
struct Node {
    int data;
    Node* next;
};
class LinkedQueueInt {
private:
    Node* dau, * cuoi;
public:
    LinkedQueueInt() { dau = cuoi = NULL; }
    ~LinkedQueueInt() {
        while (!IsEmpty()) PopStack();
    }
    bool IsEmpty() { return dau == NULL; }
    void PushStack(int x) {
        Node* newNode = new Node{ x, NULL };
        if (cuoi) cuoi->next = newNode;
        cuoi = newNode;
        if (!dau) dau = cuoi;
    }
    int PopStack() {
        if (IsEmpty()) return -1;
        int x = dau->data;
        Node* temp = dau;
        dau = dau->next;
        if (!dau) cuoi = NULL;
        delete temp;
        return x;
    }
    void Clear() {
        while (!IsEmpty()) PopStack();
    }
};

void Xeplichcap(QueueInt& nam, QueueInt& nu) 
{
    while (!nam.IsEmpty() && !nu.IsEmpty()) {
        cout << "Cap: " << nam.PopStack() << " - " << nu.PopStack() << endl;
    }
}

void RadixSort(int a[], int n) 
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max) max = a[i];
    for (int vitri = 1; max / vitri > 0; vitri *= 10) {
        QueueInt* hangdoi[10];
        for (int i = 0; i < 10; i++)
            hangdoi[i] = new QueueInt(n);

        for (int i = 0; i < n; i++)
            hangdoi[(a[i] / vitri) % 10]->PushStack(a[i]);
        int t = 0;
        for (int i = 0; i < 10; i++) {
            while (!hangdoi[i]->IsEmpty())
                a[t++] = hangdoi[i]->PopStack();
            delete hangdoi[i]; // Giải phóng bộ nhớ
        }
    }
}

int main() 
{
    QueueInt nam(5), nu(5);
    nam.PushStack(1); nam.PushStack(2); nam.PushStack(3);
    nu.PushStack(4); nu.PushStack(5); nu.PushStack(6);
    cout << "Lich cap mua:\n";
    Xeplichcap(nam, nu);

    int a[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = sizeof(a) / sizeof(a[0]);
    RadixSort(a, n);
    cout << "Mang sau khi sap xep:\n";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
