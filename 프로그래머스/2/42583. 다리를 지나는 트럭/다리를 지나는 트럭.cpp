#include <string>
#include <vector>
#include <queue>
using namespace std;
// 트럭을 안올리면 0을 추가하는 발상도 있다.

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    queue<int> wait;
    for (int temp : truck_weights) 
        wait.push(temp);
    queue<pair<int, int>> b_current;
    int time = 0;
    int w_current = 0;
    int last_time;
    while (1) {
        if ( w_current + wait.front() <= weight) {
            w_current += wait.front();
            b_current.push({wait.front(), time});
            wait.pop();
        }
        
        if(b_current.front().second + bridge_length -1 == time ) { 
            w_current -= b_current.front().first;
            b_current.pop();
        }
        
        time++;
        if (wait.size() == 0 ) {
            last_time = time;
            break;
        }
            
    }
    
    return last_time + bridge_length;
    
} 