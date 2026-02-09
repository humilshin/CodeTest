#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    unordered_map<char,int> term_map;
    
    //init
    int year = stoi(today.substr(0,4));
    int month = stoi(today.substr(5,2));
    int day = stoi(today.substr(8,2));
    
    for (string term : terms) {
        char key = term[0];
        // 기간의 길이가 세개일경우 오류였고 이렇게 하면 2부터 모든걸 뺀다
        int value = stoi(term.substr(2));
        term_map.insert({key, value});
    }
    
    //logic
    int i = 0;
    for (string entry : privacies) {
        i++;
        char key = entry[11];

        int duration;
        auto it = term_map.find(key);
        if (it != term_map.end())
        {
            duration = it->second;  
        }
        
        int eyear = stoi(entry.substr(0,4));
        int emonth = stoi(entry.substr(5,2));
        int eday = stoi(entry.substr(8,2));
        
        emonth += duration;
        eday -= 1;
        if (eday == 0) {
            emonth -= 1;
            eday = 28;
        }
        
        while (emonth > 12) {
            emonth -= 12;
            eyear++;
        }
        
        //날짜비교 int에 모든 일수 곱하고 더해서 비교할수도있다
        if (eyear > year) 
            continue;
        else if (eyear == year && emonth > month)
            continue;
        else if (eyear == year && emonth == month && eday >= day)
            continue;
        else
            answer.push_back(i);
    }
    

    return answer;
}
