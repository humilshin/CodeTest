#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    // 인용 횟수를 내림차순 정렬
    sort(citations.begin(), citations.end(), greater<int>());

    int h = 0;
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i + 1) { // h편 이상의 논문이 h번 이상 인용되었는지 확인
            h = i + 1;
        } else {
            break;
        }
    }
    
    return h;
}
