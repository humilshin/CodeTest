#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    const int MOD = 1000000007;

    //init
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (auto& p : puddles)
        dp[p[1]][p[0]] = -1;

    dp[1][1] = 1;
    
    //main
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) continue;  

            // puddle 처리
            if (dp[i][j] == -1) {  
                dp[i][j] = 0;
                continue;
            }

            // 계산 부분 
            int fromUp   = (dp[i-1][j] == -1) ? 0 : dp[i-1][j];
            int fromLeft = (dp[i][j-1] == -1) ? 0 : dp[i][j-1];
            dp[i][j] = ((long long)fromUp + fromLeft) % MOD;
        }
    }

    return dp[n][m];
}