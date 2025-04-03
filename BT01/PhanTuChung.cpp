#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_VAL = 10001;  // Giới hạn giá trị phần tử theo đề bài

int main() {
    int nx, ny, nz;
    int s[MAX_VAL] = { 0 };  // Mảng trạng thái

    cin >> nx;
    for (int i = 0; i < nx; ++i) {
        int x;
        cin >> x;
        s[x] = 1;  // Đánh dấu xuất hiện trong dãy x
    }

    cin >> ny;
    for (int i = 0; i < ny; ++i) {
        int y;
        cin >> y;
        if (s[y] == 1) s[y] = 2;  // Đánh dấu xuất hiện trong cả dãy y
    }

    cin >> nz;
    for (int i = 0; i < nz; ++i) {
        int z;
        cin >> z;
        if (s[z] == 2) s[z] = 3;  // Đánh dấu xuất hiện trong cả dãy z
    }

    int count = 0;
    for (int i = 0; i < MAX_VAL; ++i) {
        if (s[i] == 3) ++count;  // Đếm các phần tử chung
    }

    cout << count << endl;
    for (int i = 0; i < MAX_VAL; ++i) {
        if (s[i] == 3) cout << i << " ";
    }
    cout << endl;

    return 0;
}
