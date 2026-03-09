#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    //Idea 1 : Map 끼리 == 비교
    //Idea 2 : 슬라이딩 윈도우
    unordered_map<string, int> need;
    for (int i = 0; i < want.size(); i++)
        need[want[i]] = number[i];
    
    unordered_map<string, int> window; //Init
    for (int i = 0; i < 10; i++)
        window[discount[i]]++;
    
    if (window == need) answer++; // 첫번째 체크

    // 윈도우 한 칸씩 밀기
    for (int i = 10; i < discount.size(); i++) {
        window[discount[i]]++;             // 새로 들어오는 날 추가
        window[discount[i - 10]]--;        // 빠지는 날 제거
        if (window[discount[i - 10]] == 0) // 0이면 키 삭제
            window.erase(discount[i - 10]);
        
    // Tip 
    // 0인 키를 안 지운 경우
    // need == window → false 
    // 키가 존재하기 때문에 다르다고 판단
        
        if (window == need) answer++;
    }
    
    return answer;
}