#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    
    int answer = 0;

    for (int i = 0 ; i < signs.size() ; ++i) {
        string stemp;
        int itemp;
        
        if(!signs[i])
            stemp.push_back('-');
        stemp += to_string(absolutes[i]);
        itemp = stoi(stemp); 
        answer += itemp;
    }
    
    return answer;
}