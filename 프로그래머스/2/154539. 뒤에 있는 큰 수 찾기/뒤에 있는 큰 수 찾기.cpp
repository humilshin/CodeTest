#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    int n = numbers.size();
    vector<int> answer(n, -1);
    stack<int> st;  // 인덱스를 저장

    for (int i = 0; i < n; i++) {
        // 스택 top보다 크면 → 그 애의 뒷 큰수 확정
        while (!st.empty() && numbers[st.top()] < numbers[i]) {
            answer[st.top()] = numbers[i];
            st.pop();
        }
        st.push(i);
    }

    return answer;
}