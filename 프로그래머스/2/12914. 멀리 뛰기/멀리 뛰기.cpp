#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    if (n <= 2) return n;
    long long a = 1, b = 2;
    for (int i = 3; i <= n; i++) {
        long long tmp = (a + b) % 1234567;
        a = b;
        b = tmp;
    }
    return b;
}