#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    vector<string> sounds = {"aya", "ye", "woo", "ma"};

    for (string s : babbling) {
        int last_idx = -1; 
        bool is_valid = true;
        int i = 0;

        while (i < s.length()) {
            bool found = false;

            for (int j = 0; j < 4; ++j) {
                if (s.substr(i, sounds[j].length()) == sounds[j] && last_idx != j) {
                    i += sounds[j].length(); 
                    last_idx = j;          
                    found = true;
                    break;
                }
            }

            if (!found) {
                is_valid = false;
                break;
            }
        }

        if (is_valid) answer++;
    }

    return answer;
}