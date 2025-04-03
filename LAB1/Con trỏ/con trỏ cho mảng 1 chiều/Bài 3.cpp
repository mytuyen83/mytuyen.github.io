#include <iostream>
using namespace std;

//Hàm kiểm tra ký tự có phải nguyên âm không
bool ktnguyenam(char c) 
{
    c = tolower(c); //Chuyển ký tự về chữ thường
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

//Hàm nhập mảng
void nhapmang(char* a, int &n) 
{
    cout << "Nhập dãy a: ";
    for (int i = 0; i < n; i++) {
        cin >> *(a + i); 
    }
    *(a + n) = '\0'; 
}

int main() 
{
    int n;
    cout << "Nhập số lượng phần tử của dãy a: ";
    cin >> n;
    // Cấp phát động mảng
    char* a = new char[n + 1];
    char* b = new char[n + 1];
    nhapmang(a, n); 
    char* tro_a = a; 
    char* tro_b = b;
    //Duyệt qua từng ký tự của mảng a
    while (*tro_a != '\0'){
        if (ktnguyenam(*tro_a)){ //kiểm tra ký tự có phải là nguyên âm hay không
            *tro_b = *tro_a; //thêm vào b
            tro_b++; 
        }
        tro_a++;
    }
    *tro_b = '\0';
    cout << "Dãy b chứa các nguyên âm: " << b << endl;
    // Giải phóng bộ nhớ
    delete[] a;
    delete[] b;
    return 0;
}
