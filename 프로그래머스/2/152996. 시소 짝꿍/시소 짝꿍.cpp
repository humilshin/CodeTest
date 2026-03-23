#include <string>
#include <vector>
#include <map>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<int, int> m; 
    
    for (int i = 0 ; i < weights.size() ; i++) {
        m[weights[i]]++;
    }
    
    for (auto it1 = m.begin(); it1 != m.end(); it1++) {
        auto it_temp = it1;
        it_temp++;
        int n = it1->second;
        
        if (n > 1) {
            answer += (long long) n * (n-1) / 2;
        }
        
        for (auto it2 = it_temp; it2 != m.end(); it2++) {
            int big; 
            int small; 
            if (it1->first > it2->first) {
                big = it1->first;
                small = it2->first;
            }
            else {
                big = it2->first;
                small = it1->first;
            }
            
            if (big * 2 == small * 4) {
                answer = answer +  it1->second * it2->second;
                continue;
            }

            else if (big * 2 == small * 3) {
                answer = answer +  it1->second * it2->second;
                continue;
            }

            else if (big * 3 == small * 4) {
                answer = answer +  it1->second * it2->second;
                continue;
            }   
        }
    } 

        
    
    return answer;
}