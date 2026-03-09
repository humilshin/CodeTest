#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a,b);
}

int solution(vector<int> arr) {
        int temp = 1;
        for (int entry : arr) {
            temp = lcm(temp, entry);
        }
    return temp;
}