#include <string>
#include <vector>
#include <set>

using namespace std;

// 찾기 후 -> 정렬 (비효율적이다 생각)
// #include <algorithm>
// vector<int> solution(vector<int> numbers) {
//     vector<int> answer;
//     int size = numbers.size();
//     for (int i = 0 ; i < size ; ++i) {
//         for (int j = i + 1 ; j < size ; ++j){
//             int temp = numbers[i] + numbers[j];
//             if (find(answer.begin(), answer.end(), temp) != answer.end()) {
//                 continue;   
//             }
//             else {
//                 answer.push_back(numbers[i] + numbers[j]);
//             }
//         }
//     }
//     sort(answer.begin(),answer.end());
//     return answer;
// }

// set 사용 (Red-Black 트리)
// 자동 오름차순 정렬 + 자동 중복 제거
vector<int> solution(vector<int> numbers) {
    set<int> sums;
    //set<int, greater<int>> sums;  // 내림차순 set
    
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            sums.insert(numbers[i] + numbers[j]);
        }
    }
    
    //  sums.begin()부터 sums.end()까지의 모든 원소를 복사해서 vector를 만드는 벡터 생성자
    //  answer.assign(sums.begin(), sums.end()); 도 가능
    vector<int> answer(sums.begin(), sums.end());
    return answer;
}
