#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int n = min(a,b);
    int N = max(a,b);
    for (int i = n ; i <= N ; i++) {
        answer += i;
    }
    return answer;
}