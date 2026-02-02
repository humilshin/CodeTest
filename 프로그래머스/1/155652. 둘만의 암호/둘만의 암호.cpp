#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<int> SkipIndex;
    for (char temp : skip) {
        int temp_index = temp - 'a';
        SkipIndex.push_back(temp_index);
    }
    
    for (char temp : s) {
        int temp_index = temp - 'a';
        int count = 0;
        while (count != index) {
            temp_index += 1;
            temp_index %= 26;
            auto it = find(SkipIndex.begin(), SkipIndex.end(), temp_index);
            if (it == SkipIndex.end()) {
                count++;
            }
        }
        temp_index %= 26;
        answer += temp_index + 'a';   
    }
    return answer;
}