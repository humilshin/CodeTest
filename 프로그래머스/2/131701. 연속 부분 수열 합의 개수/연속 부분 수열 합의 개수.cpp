#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> us;
    int size = elements.size();
    
    for (int i = 0 ; i < size ; i++) {
        elements.push_back(elements[i]);
    }
    
    for(int n = 1 ; n <= size ; n++) {
        for (int i = 0 ; i < size ; i++) {
            int temp = 0;
            for (int j = i ; j < i+n ; j++) {
               temp += elements[j];
            }
            us.insert(temp);
        }
    }
    
    
    return us.size();
}

/* two - pointer
vector<int> solution(vector<int> sequence, int k) {
    int n = sequence.size();
    int left = 0, right = 0;
    long long sum = sequence[0];
    
    int ansLeft = 0, ansRight = n - 1; // 최악의 경우 전체 수열

    while (right < n) {
        if (sum == k) {
            // 길이가 더 짧으면 갱신
            if (right - left < ansRight - ansLeft) {
                ansLeft = left;
                ansRight = right;
            }
            sum -= sequence[left++];
        }
        else if (sum < k) {
            right++;
            if (right < n) sum += sequence[right];
        }
        else { // sum > k
            sum -= sequence[left++];
        }
    }

    return {ansLeft, ansRight};
}
*/
