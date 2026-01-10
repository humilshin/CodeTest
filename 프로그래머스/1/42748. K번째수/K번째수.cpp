#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (vector<int> vtemp : commands) {
        int i = vtemp[0]-1;
        int j = vtemp[1]-1;
        int k = vtemp[2]-1;
        
        vector<int> clip;
        for (int idx = i; idx <= j; idx++)
            clip.push_back(array[idx]);
        
        sort(clip.begin(), clip.end());
        
        answer.push_back(clip[k]);
    }

    return answer;
}