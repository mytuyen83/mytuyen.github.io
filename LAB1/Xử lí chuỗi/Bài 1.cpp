#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    string s;
    cout << "Nhap chuoi s: ";
    cin >> s;
    sort(s.begin(), s.end());  // Sắp xếp chuỗi theo thứ tự tăng dần
    cout << "Chuỗi sau khi sắp xếp: " << s << endl;
    return 0;
}
