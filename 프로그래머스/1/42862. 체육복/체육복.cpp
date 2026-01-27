#include <string>
#include <vector>
#include <set>
// 코드가 너무 복잡하다 구현 문제를 준비하자
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector <int> encode(n,0); 
    set <int> res;
        
    for (int temp : reserve)
        res.insert(temp);
    
    for (int temp : lost) // encode가 1일 경우
        encode[temp-1] = 1; // encode에 lost를 등록
    for (int temp : res) { // lost와 reserve가 같다면 
        if (encode[temp-1] == 1) {
            encode[temp-1] = 0;
            res.erase(temp);
        }
    }
    
    
    
    for (int temp : res) {
        
    if ((temp != 1) && encode[temp - 2] == 1) //좌측 제거
             encode[temp - 2] = 0;
    else if ((temp != n) && encode[temp] == 1) // 좌측제거 못할시 우측 제거
             encode[temp] = 0;
    }
        
    int sum = 0 ;
    for (int temp : encode)
        sum += temp;
    
    int answer = n - sum;
    return answer;
}