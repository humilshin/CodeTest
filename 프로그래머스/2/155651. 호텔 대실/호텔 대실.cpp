#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int getTime(string format)
{
	return stoi(format.substr(0, 2)) * 60 + stoi(format.substr(3, 2));
}

int solution(vector<vector<string>> book_time) {

	// pair에 입실, 퇴실(청소 시간 포함)을 삽입
	vector<pair<int, int>> v;
	for (vector<string> s : book_time)
		v.push_back({ getTime(s[0]) , getTime(s[1]) + 10 });

	// 정렬 수행(입실 시간 오름차순)
	sort(v.begin(), v.end());

	// 우선순위 큐를 이용하여 검사
	priority_queue<int> q;
	for (int i = 0; i < v.size(); ++i)
	{
		// 큐에서 v[i].first(입장 시간)이 q.top 이상이라면?
		if (!q.empty() && -q.top() <= v[i].first) // 제일 빠른 퇴장 시간 << 입장 시간
			q.pop(); // 다닥다닥 붙였으므로 퇴장시간 갱신

        // q.pop을 한상태면 퇴장시간 갱신
        // q.pop을 안했으면 하나의 방 추가 
		q.push(-v[i].second);
	}

	// 큐의 size가 최소로 사용해야하는 방의 개수
	return q.size();
}

// 최소 객실의 수이므로 최대한 다닥 다닥 붙여야 한다. 
// Vector를 Sort한 이유는 앞에서 부터 다닥다닥 붙여야 하기 때문에 