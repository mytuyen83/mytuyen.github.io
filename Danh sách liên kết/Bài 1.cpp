#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class ListInt { //danh sách liên kết đơn
private: //phạm vi truy cập riêng tư, không thể thay đổi trực tiếp
    Node* head; //con trỏ trỏ đến phần tử đầu tiên
public: //phạm vi truy cập công khai, có thể gọi hàm từ bên ngoài
    ListInt() : head(NULL) {} //Khởi tạo danh sách rỗng
    ~ListInt(); //Giải phóng bộ nhớ của danh sách liên kết khi ListInt bị hủy.
    void them(int gtri); //hàm thêm một số nguyên vào cuối danh sách
    void xoa(int gtri); //hàm xoá một phần tử
    void themds(const ListInt& dskhac); // hàm thêm các phần tử của danh sách khác vào cuối danh sách hiện tại
    void in() const; //In danh sách ra màn hình
    bool isEmpty() const { return head == NULL; } //hàm kiểm tra danh sách rỗng
};

ListInt::~ListInt() { //Hàm giải phóng bộ nhớ để tránh rò rỉ
    Node* hientai = head; //khai báo con trỏ hiện tại đến đầu danh sách
    while (hientai) {
        Node* temp = hientai;
        hientai = hientai->next;
        delete temp; //Giải phóng bộ nhớ
    }
}

void ListInt::them(int gtri) {
    Node* moi = new Node{ gtri, NULL };
    if (!head) {
        head = moi;
    }
    else { //nếu head không phải danh sách rỗng
        Node* temp = head; 
        while (temp->next) { //tạo temp duyệt đến cuối danh sách rồi thêm phần tử mới vào
            temp = temp->next;
        }
        temp->next = moi;
    }
}

void ListInt::xoa(int gtri) {
    Node* hientai = head;
    Node* truoc = NULL;
    while (hientai && hientai->data != gtri) { //tìm phần tử cần xoá
        truoc = hientai;
        hientai = hientai->next;
    }
    if (!hientai) return; //nếu xoá một phần tử không có trong danh sách thì không làm gì cả
    if (!truoc) { //nếu xoá phần tử là đầu danh sách
        head = hientai->next; //cập nhật head là phần tử tiếp theo
    }
    else {
        truoc->next = hientai->next; //bỏ qua phần tử mà hientai đang trỏ đến
    }
    delete hientai;
}

void ListInt::themds(const ListInt& dskhac) {
    if (!dskhac.head) return; //Kiểm tra danh sách rỗng
    if (!head) { //Nếu danh sách hiện tại rỗng, sao chép toàn bộ
        Node* temp = dskhac.head;
        while (temp) {
            them(temp->data);
            temp = temp->next;
        }
        return;
    }

    Node* cuoi = head; //Tìm phần tử cuối của danh sách hiện tại
    while (cuoi->next) {
        cuoi = cuoi->next;
    }
    
    Node* temp = dskhac.head; //Thêm danh sách mới vào cuối
    while (temp) {
        cuoi->next = new Node{ temp->data, NULL };
        cuoi = cuoi->next;
        temp = temp->next;
    }
}

void ListInt::in() const {
    if (isEmpty()) {
        cout << "Danh sach rong\n";
        return;
    }
    cout << "Danh sach: ";
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    ListInt danhsach1; //khởi tạo danh sách 1
    cout << "Nhap 10 so nguyen cho danh sach 1: ";
    for (int i = 0; i < 10; ++i) {
        int n;
        cin >> n;
        danhsach1.them(n); //thêm vào danh sách 1
    }
    danhsach1.in(); //in danh sách 1

    int k;
    cout << "Nhap so nguyen can xoa: ";
    cin >> k;
    danhsach1.xoa(k); //xoá số nguyên k trong danh sách 1
    danhsach1.in(); //cập nhật lại danh sách 1

    ListInt danhsach2; //khởi tạo danh sách 2
    cout << "Nhap 5 so nguyen cho danh sach 2: ";
    for (int i = 0; i < 5; ++i) {
        int m;
        cin >> m;
        danhsach2.them(m); //thêm vào danh sách 2
    }

    danhsach1.themds(danhsach2); //gộp danh sách 2 vào danh sách 1
    danhsach1.in(); //cập nhật danh sách 1

    return 0;
}
