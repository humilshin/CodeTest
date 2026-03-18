#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    // 1. 행렬 초기화 (1부터 rows * columns까지)
    vector<vector<int>> board(rows + 1, vector<int>(columns + 1));
    int num = 1;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            board[i][j] = num++;
        }
    }

    // 2. 각 쿼리 처리
    for (auto& q : queries) {
        int x1 = q[0], y1 = q[1], x2 = q[2], y2 = q[3];
        
        // 시작 위치의 값을 따로 저장
        int temp = board[x1][y1];
        int min_val = temp;

        // 왼쪽 변: 아래에 있는 값을 위로 올림
        for (int i = x1; i < x2; i++) {
            board[i][y1] = board[i + 1][y1];
            min_val = min(min_val, board[i][y1]);
        }

        // 아래쪽 변: 오른쪽에 있는 값을 왼쪽으로 당김
        for (int i = y1; i < y2; i++) {
            board[x2][i] = board[x2][i + 1];
            min_val = min(min_val, board[x2][i]);
        }

        // 오른쪽 변: 위에 있는 값을 아래로 내림
        for (int i = x2; i > x1; i--) {
            board[i][y2] = board[i - 1][y2];
            min_val = min(min_val, board[i][y2]);
        }

        // 위쪽 변: 왼쪽에 있는 값을 오른쪽으로 당김
        for (int i = y2; i > y1; i--) {
            board[x1][i] = board[x1][i - 1];
            min_val = min(min_val, board[x1][i]);
        }

        // 마지막으로 비어있는 (x1, y1 + 1) 자리에 처음 저장해둔 값을 넣음
        board[x1][y1 + 1] = temp;
        
        answer.push_back(min_val);
    }

    return answer;
}