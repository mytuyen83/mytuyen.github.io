#include <iostream>
#include <stack>
using namespace std;

struct ThapHaNoi {
    int sodia;
    char tu, den, trunggian;
};

// Hàm Fibonacci đệ qui
int FibonacciDeQui(int n)
{
    if (n <= 1) return n;
    return FibonacciDeQui(n - 1) + FibonacciDeQui(n - 2);
}

// Hàm Fibonacci khử đệ qui
int FibonacciKoDeQui(int n)
{
    stack<int> nganxep;
    int a = 0, b = 1, c;
    if (n == 0) return a;
    if (n == 1) return b;
    for (int i = 2; i <= n; i++) {
        nganxep.push(a);
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

// Hàm đảo ngược số đệ qui
int DaoSoDeQui(int n, int sodao = 0)
{
    if (n == 0) return sodao;
    return DaoSoDeQui(n / 10, sodao * 10 + n % 10);
}

// Hàm đảo ngược số khử đệ qui
int DaoSoKoDeQui(int n)
{
    stack<int> nganxep;
    while (n > 0) {
        nganxep.push(n % 10);
        n /= 10;
    }
    int sodao = 0, heso = 1;
    while (!nganxep.empty()) {
        sodao += nganxep.top() * heso;
        nganxep.pop();
        heso *= 10;
    }
    return sodao;
}

// Hàm tháp Hà Nội đệ qui
void ThapHaNoiDeQui(int n, char tu, char den, char trunggian)
{
    if (n == 1) {
        cout << "Di chuyen dia 1 tu " << tu << " den " << den << endl;
        return;
    }
    ThapHaNoiDeQui(n - 1, tu, trunggian, den);
    cout << "Di chuyen dia " << n << " tu " << tu << " den " << den << endl;
    ThapHaNoiDeQui(n - 1, trunggian, den, tu);
}

// Hàm Tháp Hà Nội khử đệ qui
void ThapHaNoiKoDeQui(int n)
{
    stack<ThapHaNoi> nganxep;
    nganxep.push({ n, 'A', 'C', 'B' });
    while (!nganxep.empty()) {
        ThapHaNoi thap = nganxep.top();
        nganxep.pop();
        if (thap.sodia == 1) {
            cout << "Di chuyen dia 1 tu " << thap.tu << " den " << thap.den << endl;
        }
        else {
            nganxep.push({ thap.sodia - 1, thap.trunggian, thap.den, thap.tu });
            nganxep.push({ 1, thap.tu, thap.den, thap.trunggian });
            nganxep.push({ thap.sodia - 1, thap.tu, thap.trunggian, thap.den });
        }
    }
}

int main()
{
    int n;
    cout << "Nhap so n de tinh Fibonacci: "; cin >> n;
    cout << "Fibonacci de quy: " << FibonacciDeQui(n) << endl;
    cout << "Fibonacci khu de quy: " << FibonacciKoDeQui(n) << endl;

    cout << "\nNhap so de dao nguoc: "; cin >> n;
    cout << "So dao nguoc de quy: " << DaoSoDeQui(n) << endl;
    cout << "So dao nguoc khu de quy: " << DaoSoKoDeQui(n) << endl;

    cout << "\nNhap so tang cua Thap Ha Noi: "; cin >> n;
    cout << "Thap Ha Noi de quy:\n";
    ThapHaNoiDeQui(n, 'A', 'C', 'B');
    cout << "\nThap Ha Noi khu de quy:\n";
    ThapHaNoiKoDeQui(n);

    return 0;
}
