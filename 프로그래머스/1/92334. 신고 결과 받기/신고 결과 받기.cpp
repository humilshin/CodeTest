#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int n = id_list.size();
    vector<int> answer(n, 0);
    
    // 1. ID별 인덱스 매핑 (결과 배열 접근용)
    unordered_map<string, int> id_idx_map;
    for(int i = 0; i < n; ++i) {
        id_idx_map[id_list[i]] = i;
    }
    
    // 2. 신고 기록 관리 (key: 피신고자, value: 신고한 사람들 set)
    // set을 사용하여 동일 인물의 중복 신고를 자동으로 제거함
    unordered_map<string, unordered_set<string>> report_record;
    
    for(const string& s : report) {
        stringstream ss(s);
        string reporter, reported;
        ss >> reporter >> reported; // 공백 기준 분리
        
        report_record[reported].insert(reporter);
    }
    
    // 3. k번 이상 신고된 유저 확인 및 메일 발송 카운트
    // for(auto& it : map) -> it.first it.second의 c++20 형식
    for(auto const& [reported_user, reporters] : report_record) {
        if(reporters.size() >= k) {
            for(const string& person : reporters) {
                answer[id_idx_map[person]]++;
            }
        }
    }
    
    return answer;
}