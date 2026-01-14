#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> ranking(k+1);
    for (int i = 1 ; i <= score.size() ; ++i){
        int temp = score[i-1];
        if( i > k) {
            ranking[k] = temp;
            sort(ranking.begin(), ranking.end(), greater<int>());
            answer.push_back(ranking[k-1]);
        }
        else {
            ranking.push_back(temp);
            sort(ranking.begin(), ranking.end(), greater<int>());
            answer.push_back(ranking[i-1]);
        }


    }
    return answer; 
}