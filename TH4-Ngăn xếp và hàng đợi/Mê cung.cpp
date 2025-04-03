#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Nut {
    int x, y, truoc_x, truoc_y; // Lưu vị trí hiện tại và vị trí trước đó trong đường đi
};

struct ToaDo {
    int x, y;
};

int n, m, x0, y0, x1, y1;
int mecung[100][100]; // Mê cung
bool duyet[100][100]; // Mảng đánh dấu ô đã thăm
Nut cha[100][100]; // Lưu thông tin nút cha của mỗi ô

int dx[] = { -1, 1, 0, 0 }; // Di chuyển lên, xuống, trái, phải
int dy[] = { 0, 0, -1, 1 };

void in(stack<ToaDo>& vitri) 
{
    cout << vitri.size() << endl; // In đường đi theo thứ tự từ điểm xuất phát đến đích
    while (!vitri.empty()) {
        ToaDo p = vitri.top();
        cout << p.x << " " << p.y << endl;
        vitri.pop();
    }
}

void BFS() 
{
    queue<Nut> q;
    duyet[x0][y0] = true;
    q.push({ x0, y0, -1, -1 }); // Bắt đầu từ điểm xuất phát
    while (!q.empty()) {
        Nut hientai = q.front();
        q.pop();
        if (hientai.x == x1 && hientai.y == y1) { // Nếu đã đến được đích
            stack<ToaDo> vitri; // Lưu đường đi từ đích về xuất phát
            while (hientai.x != -1 && hientai.y != -1) {
                vitri.push({ hientai.x + 1, hientai.y + 1 }); // Chuyển về chỉ số bắt đầu từ 1
                hientai = cha[hientai.x][hientai.y];
            }
            in(vitri);
            return;
        }
        for (int i = 0; i < 4; i++) { // Di chuyển đến các ô liền kề
            int nx = hientai.x + dx[i], ny = hientai.y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && mecung[nx][ny] == 0 && !duyet[nx][ny]) {
                duyet[nx][ny] = true;
                cha[nx][ny] = hientai; // Lưu vị trí nút cha
                q.push({ nx, ny, hientai.x, hientai.y });
            }
        }
    }
    cout << 0 << endl; // Nếu không tìm thấy đường đi
}

void DFS() 
{
    stack<Nut> s;
    duyet[x0][y0] = true;
    s.push({ x0, y0, -1, -1 }); // Bắt đầu từ điểm xuất phát

    while (!s.empty()) {
        Nut hientai = s.top();
        s.pop();
        if (hientai.x == x1 && hientai.y == y1) { // Nếu đã đến được điểm đích
            stack<ToaDo> vitri;
            while (hientai.x != -1 && hientai.y != -1) { // Lưu đường đi từ đích về xuất phát
                vitri.push({ hientai.x + 1, hientai.y + 1 }); // Chuyển về chỉ số bắt đầu từ 1
                hientai = cha[hientai.x][hientai.y];
            }
            in(vitri);
            return;
        }
        for (int i = 0; i < 4; i++) { // Thử di chuyển đến các ô liền kề
            int nx = hientai.x + dx[i], ny = hientai.y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && mecung[nx][ny] == 0 && !duyet[nx][ny]) {
                duyet[nx][ny] = true;
                cha[nx][ny] = hientai; // Lưu vị trí cha
                s.push({ nx, ny, hientai.x, hientai.y });
            }
        }
    }
    cout << 0 << endl; // Nếu không tìm thấy đường đi
}

int main() 
{
    int luachon;
    cout << "Chon thuat toan (1: BFS, 2: DFS): ";
    cin >> luachon;
    cin >> n >> m >> x0 >> y0 >> x1 >> y1;
    x0--; y0--; x1--; y1--; // Chuyển về chỉ số bắt đầu từ 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mecung[i][j];
        }
    }
    if (luachon == 1) {
        BFS();
    }
    else if (luachon == 2) {
        DFS();
    }
    else {
        cout << "Lua chon khong hop le!" << endl;
    }
    return 0;
}
