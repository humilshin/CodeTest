#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    while (1) {
        int entry = n % 10;
        answer.push_back(entry);
        
        if ( n < 10 )
            return answer;
        n = n / 10;
    }

}