#include <string>
#include <vector>
#include <cmath>

using namespace std;

int nof(int n) {
    int count = 0;
    float rootn = sqrt(n);
    for (int i = 1 ; i <= rootn  ; ++i) {
        if (i == rootn) {
            count++;
        }

        else if (i * (n/i) == n) {   
            count = count + 2;
        }
    }
    
    return count;
}

int solution(int number, int limit, int power) {

    int answer = 0;
    for (int i = 1 ; i <= number ; i++) {
        int temp = nof(i);    
        if (temp > limit)
            answer += power;
        else 
            answer += temp;
    }
    
    return answer;
}

