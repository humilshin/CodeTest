#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    
    sort(data.begin(), data.end(), 
         [col](const vector<int>& a, const vector<int>& b) {
    if (a[col-1] < b[col-1]) {
        return true;
    }
    else if (a[col-1] == b[col-1]) {
        return a[0] > b[0];
    }
    else 
        return false;
});
    
    for (int i = row_begin - 1 ; i <= row_end - 1 ; i++) {
        int S = 0;
        for (int j = 0 ; j < data[0].size() ; j++) {
            S += data[i][j] % (i+1);
        }
        answer ^= S;
    }
    
    return answer;
}