#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <map>
using namespace std;

int diffMin(string a, string b) {
    return stoi(a.substr(0,2))*60 - stoi(b.substr(0,2))*60
         + stoi(a.substr(3,2)) - stoi(b.substr(3,2));
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<string, string> timemap;
    map<string, int> result;
    
    for (const auto& entry : records) {
        stringstream ss(entry);
        string time, number, checkio;
        ss >> time >> number;
        if(timemap.find(number) == timemap.end())
            timemap[number] = time;
        else {
            result[number] += diffMin(time, timemap[number]);
            timemap.erase(number);
        }
    }
    
    //출차 안된것들 23:59로 출차
    for (const auto& entry : timemap) {
        result[entry.first] += diffMin("23:59", entry.second);
    }
    
    
    for (const auto& entry : result) {
        int temp = fees[1];
        if(entry.second > fees[0]) {
            
            if((entry.second - fees[0]) % fees[2] == 0) {
              temp += ((entry.second - fees[0]) / fees[2]) * fees[3];
            }
            else {
              temp += ( (1 + (entry.second - fees[0]) / fees[2]) )* fees[3]; 
            }
            
        }
        answer.push_back(temp);
    }
    
        
    return answer;
}