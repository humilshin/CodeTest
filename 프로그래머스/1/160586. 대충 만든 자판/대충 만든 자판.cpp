#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    int size = targets.size();
    
    for (int i = 0; i < size; i++) {
        string target_ = targets[i];
        int count = 0;
        bool impossible = false;
        
        for (int j = 0; j < target_.size(); j++) {
            int minPress = 101;  // 최소 누름 횟수 (키당 최대 100개 문자)
            
            // 모든 키를 다 검색해야 함
            for (int k = 0; k < keymap.size(); k++) {
                string keymap_ = keymap[k];
                
                for (int l = 0; l < keymap_.size(); l++) {
                    if (target_[j] == keymap_[l]) {
                        if (l + 1 < minPress) {
                            minPress = l + 1;  // l+1번 눌러야 해당 문자 입력
                        }
                        break;  // 같은 키에서 더 찾을 필요 없음
                    }
                }
            }
            
            if (minPress == 101) {
                impossible = true;
                break;
            }
            else {
                count += minPress;
            }
        }
        
        if (impossible)
            answer.push_back(-1);
        else
            answer.push_back(count);
    }
    
    return answer;
}