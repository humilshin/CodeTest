#include <string>
#include <vector>

using namespace std;

/*
int solution(int n) {
    for (int i = 2; i < n; i++) {
        if (n % i == 1)
        return i;
    }
}
*/

//n % x == 1은 (n - 1) % x == 0과 동일 
int solution(int n)
{
    int target = n - 1;
    
    for (int x = 2; x * x <= target; x++)
    {
        if (target % x == 0)
        {
            return x;
        }
    }
    return target;  // n-1이 소수인 경우
}