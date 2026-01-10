#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (char c : s) {
        if (c == ' ') {
            answer += ' ';
        }
        else {
            // 소문자
            if (c >= 'a') {          
                int push = ( (c - 'a') + n ) % 26;
                answer += 'a' + push;

            }
            // 대문자 
            else {                
                int push = ( (c - 'A') + n ) % 26;
                answer += 'A' + push;
            }
        }
    }
    
    return answer;
}
