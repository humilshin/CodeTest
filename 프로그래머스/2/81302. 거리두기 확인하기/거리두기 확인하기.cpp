#include <string>
#include <vector>
using namespace std;

bool check(vector<string>& room) {
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++) {
            if (room[r][c] != 'P') continue;
            
            // 맨해튼 거리 1: 상하좌우 인접
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
                if (room[nr][nc] == 'P') return false;
            }
            
            // 맨해튼 거리 2: 직선 (두 칸 떨어진 경우)
            // 중간에 파티션이 없으면 위반
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d] * 2;
                int nc = c + dc[d] * 2;
                if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
                if (room[nr][nc] == 'P') {
                    // 중간 칸이 파티션이 아니면 위반
                    int mr = r + dr[d];
                    int mc = c + dc[d];
                    if (room[mr][mc] != 'X') return false;
                }
            }
            
            // 맨해튼 거리 2: 대각선
            int diagR[] = {-1, -1, 1, 1};
            int diagC[] = {-1, 1, -1, 1};
            for (int d = 0; d < 4; d++) {
                int nr = r + diagR[d];
                int nc = c + diagC[d];
                if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) continue;
                if (room[nr][nc] == 'P') {
                    // 두 경로 중 하나라도 파티션이 아니면 위반
                    if (room[r][nc] != 'X' || room[nr][c] != 'X')
                        return false;
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto& room : places) {
        answer.push_back(check(room) ? 1 : 0);
    }
    return answer;
}