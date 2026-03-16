#include <string>
#include <vector>
using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> tri(n);
    for (int i = 0; i < n; i++)
        tri[i].resize(i + 1, 0);

    int r = -1, c = 0, val = 1;
    int dir = 0; // 0: 아래, 1: 오른쪽, 2: 대각선 위

    for (int len = n; len > 0; len--) {
        for (int i = 0; i < len; i++) {
            if (dir == 0)      r++;
            else if (dir == 1) c++;
            else             { r--; c--; }
            tri[r][c] = val++;
        }
        dir = (dir + 1) % 3;
    }

    vector<int> answer;
    for (auto& row : tri)
        for (int v : row)
            answer.push_back(v);
    return answer;
}