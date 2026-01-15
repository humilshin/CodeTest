#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int idx1 = 0;  // cards1 현재 인덱스
    int idx2 = 0;  // cards2 현재 인덱스
    
    for (const string& word : goal) {
        if (idx1 < cards1.size() && cards1[idx1] == word) {
            idx1++;  // cards1에서 뽑음
        }
        else if (idx2 < cards2.size() && cards2[idx2] == word) {
            idx2++;  // cards2에서 뽑음
        }
        else {
            return "No";  // 어디서도 못 뽑음
        }
    }
    
    return "Yes";
}