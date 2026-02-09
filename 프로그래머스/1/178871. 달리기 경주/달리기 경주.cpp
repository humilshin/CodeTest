#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {

    //탐색에 관한 시간복잡도 문제
    // 순서대로 탐색(벡터) : O(n)
    // Map 이용 : hash로 index화가 이미 되어있기 때문에 O(1)
    
    // 이문제에서 등수저장및 탐색은 map으로
    // 순서에 대한 저장은 vector로
    
    //map init
    unordered_map<string, int> rank;
    for (int i = 0; i < players.size(); i++)
        rank[players[i]] = i;


     for (const string& name : callings) {
            int idx = rank[name];           // O(1)로 현재 등수 찾기
            string front = players[idx - 1]; // 바로 앞 선수

            // 배열 스왑
            swap(players[idx], players[idx - 1]);

            // 맵도 같이 갱신
            rank[name] = idx - 1;
            rank[front] = idx;
        }

    
    return players;
}