#include <vector>
using namespace std;

int cnt[2] = {0, 0};  // cnt[0] = 0의 개수, cnt[1] = 1의 개수

void quad(vector<vector<int>>& arr, int x, int y, int size) {
    // 현재 영역이 전부 같은 값인지 체크
    bool same = true;
    int val = arr[x][y];
    for (int i = x; i < x + size && same; i++)
        for (int j = y; j < y + size && same; j++)
            if (arr[i][j] != val)
                same = false;

    if (same) {
        cnt[val]++;
        return;
    }

    // 4등분해서 재귀
    int half = size / 2;
    quad(arr, x,        y,        half);  // 좌상
    quad(arr, x,        y + half, half);  // 우상
    quad(arr, x + half, y,        half);  // 좌하
    quad(arr, x + half, y + half, half);  // 우하
}

vector<int> solution(vector<vector<int>> arr) {
    cnt[0] = 0;
    cnt[1] = 0;
    quad(arr, 0, 0, arr.size());
    return {cnt[0], cnt[1]};
}
