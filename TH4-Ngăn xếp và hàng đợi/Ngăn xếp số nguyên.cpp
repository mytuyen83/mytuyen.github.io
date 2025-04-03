#include <iostream>
#include <string>
using namespace std;

//sử dụng mảng
class StackInt {
private:
    static const int MAX_SIZE = 100;
    int a[MAX_SIZE];
    int top;
public:
    StackInt() { top = -1; } //khởi tạo ngăn xếp
    void InitStack() { top = -1; } //khởi tạo đẻ gọi lại nhiều lần
    bool IsEmpty() { return top == -1; } //kiểm tra rỗng
    bool IsFull() { return top == MAX_SIZE - 1; } //kiểm tra dầy
    bool PushStack(int x) { //thêm vào ngăn xếp
        if (IsFull()) return false; 
        a[++top] = x;
        return true;
    }
    bool PopStack(int& x) { //lấy ra khỏi ngăn xếp
        if (IsEmpty()) return false;
        x = a[top--];
        return true;
    }
    bool PeekStack(int& x) { //lấy phần tử trên cùng, không xoá khỏi ngăn xếp
        if (IsEmpty()) return false;
        x = a[top];
        return true;
    }
    void Clear() { top = -1; } //xoá ngăn xếp
};

//sử dụng danh sách liên kết
struct Node 
{
    int data;
    Node* next;
};

class LinkedStackInt {
private:
    Node* top;
public:
    LinkedStackInt() { top = NULL; } //khởi tạo danh sách
    void InitStack() { top = NULL; } //hàm khởi tạo để gọi lại nhiều lần 
    bool IsEmpty() { return top == NULL; } //kiểm tra danh sách rỗng
    bool PushStack(int x) { //thêm vào danh sách
        Node* moi = new Node{ x, top };
        top = moi;
        return true;
    }
    bool PopStack(int& x) { //lấy ra khỏi danh sách
        if (IsEmpty()) return false;
        Node* temp = top;
        x = temp->data;
        top = top->next;
        delete temp;
        return true;
    }
    bool PeekStack(int& x) { //lấy phần tử trên cùng, không xoá khỏi danh sách
        if (IsEmpty()) return false;
        x = top->data;
        return true;
    }
    void Clear() { //xoá danh sách
        while (!IsEmpty()) {
            int temp;
            PopStack(temp);
        }
    }
};

void daoso(int n) 
{
    StackInt stack;
    string s = to_string(n); //chuyển số nguyên thành chuỗi để dễ truy xuất chữ số
    for (char c : s) { //duyệt từng ký tự trong chuỗi
        stack.PushStack(c - '0'); //chuyển ký tự số thành số nguyên rồi đưa vào ngăn xếp
    }
    string d = ""; //tạo chuỗi rỗng để lưu kết quả
    int m;
    while (stack.PopStack(m)) {
        d += to_string(m); 
    }
    cout << "So dao nguoc: " << d << endl;
}

void doixung(string s) 
{
    StackInt stack;
    int n = s.length();
    for (int i = 0; i < n / 2; i++) { //duyệt nửa đầu 
        stack.PushStack(s[i]);
    }
    for (int i = (n + 1) / 2; i < n; i++) { //duyệt nửa sau, trường hợp xâu lẻ nên bắt đầu từ (n+1)/2
        int kytudau;
        stack.PopStack(kytudau);
        if (kytudau != s[i]) {
            cout << "Xau khong doi xung.\n";
            return;
        }
    }
    cout << "Xau doi xung.\n";
}

void chuyendoi(int n) 
{
    StackInt stack;
    while (n > 0) {
        stack.PushStack(n % 2);
        n /= 2;
    }
    cout << "Nhi phan: ";
    int bit;
    while (stack.PopStack(bit)) {
        cout << bit;
    }
    cout << endl;
}

int Uutien(char toantu) 
{
    if (toantu == '+' || toantu == '-') return 1;
    if (toantu == '*' || toantu == '/') return 2;
    return 0;
}

void chuyenhauto(string bieuthuc, string& hau) {
    StackInt toantu;
    hau = "";
    for (char kytu : bieuthuc) {
        if (kytu >= '0' && kytu <= '9') {
            hau += kytu;
        }
        else if (kytu == '(') {
            toantu.PushStack(kytu);
        }
        else if (kytu == ')') {
            int temp;
            while (!toantu.IsEmpty() && toantu.PeekStack(temp) && temp != '(') {
                hau += char(temp);
                toantu.PopStack(temp);
            }
            toantu.PopStack(temp); // Bỏ dấu '('
        }
        else {
            int temp;
            while (!toantu.IsEmpty() && toantu.PeekStack(temp) && Uutien(temp) >= Uutien(kytu)) {
                hau += char(temp);
                toantu.PopStack(temp);
            }
            toantu.PushStack(kytu);
        }
    }
    int temp;
    while (!toantu.IsEmpty()) {
        toantu.PopStack(temp);
        hau += char(temp);
    }
}

void tinhhauto(string hau, int& result) {
    StackInt giatri;
    for (char kytu : hau) {
        if (kytu >= '0' && kytu <= '9') {
            giatri.PushStack(kytu - '0');
        }
        else {
            int b; giatri.PopStack(b);
            int a; giatri.PopStack(a);
            switch (kytu) {
            case '+': giatri.PushStack(a + b); break;
            case '-': giatri.PushStack(a - b); break;
            case '*': giatri.PushStack(a * b); break;
            case '/': giatri.PushStack(a / b); break;
            }
        }
    }
    giatri.PeekStack(result);
}

int main() 
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    daoso(n);
    string s;
    cout << "Nhap xau can kiem tra doi xung: ";
    cin >> s;
    doixung(s);
    int t;
    cout << "Nhap so muon chuyen doi sang nhi phan: ";
    cin >> t;
    chuyendoi(t);
    string bieuthuc;
    cout << "Nhap bieu thuc trung to: ";
    cin >> bieuthuc;
    string hau;
    chuyenhauto(bieuthuc, hau);
    cout << "Bieu thuc hau to: " << hau << endl;
    int kq;
    tinhhauto(hau, kq);
    cout << "Ket qua: " << kq << endl;
    return 0;
}
