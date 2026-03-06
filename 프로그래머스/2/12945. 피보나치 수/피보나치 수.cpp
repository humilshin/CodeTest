#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int a = 0;
    int b = 1;
    int index = 1;
    long temp;
    while (1) {
        temp = (a + b) % 1234567;
        a = b;
        b = temp;
        index++;
        
        if (index == n)
            return temp;
    }

}