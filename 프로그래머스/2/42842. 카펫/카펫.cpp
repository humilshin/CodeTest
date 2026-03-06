#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int v;
    int h;
    for (int i = 1 ; i <= yellow ; i++) {
        if(yellow % i == 0) {
            h = yellow / i; 
            v = i;
            
            if (2*(h+2) + 2*(v+2) - 4 == brown)
                break;
        }
    }
    
    answer.push_back(h+2);
    answer.push_back(v+2);
    
    return answer;
}