#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string s) {
    string answer = "";
    char ex = ' ';
    for (char c :  s) {
        if (ex == ' ' && c != ' ') {
            answer += ::toupper(c);
        }
        else {
            answer += ::tolower(c);
        }
        ex = c;
    }
    
    return answer;
}