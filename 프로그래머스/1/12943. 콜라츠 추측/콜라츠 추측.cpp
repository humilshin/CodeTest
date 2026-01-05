#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    
    long temp = num;
    int count = 0;
    while (1) {
        if (temp == 1)
            break;
        
        if ( temp % 2 == 0)
            temp = temp / 2;
        else 
            temp = temp * 3 + 1;
        
        count++;
        
        if(count == 500)
            return -1;
    }
    return count;
}