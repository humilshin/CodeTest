#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> ranking(k+1);
    for (int i = 1 ; i <= score.size() ; ++i){
        int temp = score[i-1];
        if( i > k) {
            ranking[k] = temp;
            sort(ranking.begin(), ranking.end(), greater<int>());
            answer.push_back(ranking[k-1]);
        }
        else {
            ranking.push_back(temp);
            sort(ranking.begin(), ranking.end(), greater<int>());
            answer.push_back(ranking[i-1]);
        }


    }
    return answer; 
}

/* 최대 최소 반환은 Priority Queue로 푸는게 일반적
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    // 최소 힙(Min-Heap) 선언: 가장 작은 값이 top에 위치함
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int s : score) {
        // 1. 명예의 전당에 점수 추가
        pq.push(s);

        // 2. 명예의 전당 크기가 k를 초과하면 가장 낮은 점수 제거
        if (pq.size() > k) {
            pq.pop();
        }

        // 3. 매일 명예의 전당 최하위 점수(top)를 기록
        answer.push_back(pq.top());
    }

    return answer;
}
*/
