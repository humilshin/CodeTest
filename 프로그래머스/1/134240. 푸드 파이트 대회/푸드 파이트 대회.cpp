#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string s;
    for ( int i = 1 ; i < food.size() ; ++i) {
        int n = food[i];
        for ( int j = 0 ; j < n / 2 ; ++j) {
            s += to_string(i);
        }
    }
    
    answer = s; 
    reverse(s.begin(), s.end());
    answer += '0' + s; 

    return answer;
}