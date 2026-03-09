#include <string>
#include <vector>
#include <stack>
using namespace std;

bool IsValid(string s) {
    stack<char> stack;
    for (char c : s) {
        char temp;
        if (!stack.empty())
            temp = stack.top();
        
        if(temp == '(' && c == ')' ||
           temp == '{' && c == '}' ||
           temp == '[' && c == ']')
        {
            stack.pop();
        }
        else 
        {
            stack.push(c);
        }
    }

    return stack.empty() ? true : false; 
}

void rotate(string& s) {
    int size = s.size();
    char temp = s[0];
    for (int i = 0 ; i < size ; i++) {
        s[i] = s[i+1];
    }
    s[size-1] = temp;
}

int solution(string s) {
    int answer = 0;
    answer += IsValid(s);
    
    int t = s.size();    
    for (int i = 1 ; i < t ; i++) {
        rotate(s);
        answer += IsValid(s);
    }  
    
    return answer;
}