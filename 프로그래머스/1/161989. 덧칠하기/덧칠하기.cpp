#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int count = 0;
    int cursor = 0;
    int size = section.size();
    int last = section[size-1];
    for (int entry : section) {
        if (cursor > n)
            return count;
        
        else if(cursor < entry){
            cursor = entry + m - 1;
            count++;
        }
    }
    
    return count;
}