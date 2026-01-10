#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int n = number.size();
    int count = 0;
    for (int i = 0 ; i < n ; i++) {
        int temp = number[i];
        for (int j = i + 1 ; j < n ; j++) {
            for (int k = j + 1 ; k < n ; k++) {
                if ( temp == -1 * (number[j] + number[k]))
                    count++;
            }   
        }
    }
    return count;
}