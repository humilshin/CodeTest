#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int left, int right) {
    
    int answer = 0;
    for (int n = left ; n <= right; ++n) {
        int temp = sqrt(n);
        if (temp * temp == n) 
            answer -= n; 
        else
            answer += n;
    }
    return answer;
}