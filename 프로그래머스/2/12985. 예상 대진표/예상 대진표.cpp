#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    int A = a - 1;
    int B = b - 1;
    
    while (1) {
        A = A / 2;
        B = B / 2;
        if (A == B)
            return answer;
        answer++;
    }
}