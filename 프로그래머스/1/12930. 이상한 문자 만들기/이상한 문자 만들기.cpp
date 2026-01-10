#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int n = 0;
    for (char c : s) {
        if (c == ' ') {
            answer += ' ';
            n = 0;
            continue;
        }
        // 짝수 -> 대문자로
        if ( n % 2 == 0) {
            c = toupper(c);   
            answer += c;        
        }
        // 홀수 -> 소문자로
        if ( n % 2 == 1) {
            c = tolower(c);   
            answer += c;          
        }            
        n++;
    }
    return answer;
}