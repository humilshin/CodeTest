#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    for (char c : s) {  
        if ( c < '0' || c > '9')
            return false;
    }
    
    int n = s.length();
 
    if (n == 4 || n == 6)
        return true;
    else 
        return false;
}