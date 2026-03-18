#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9; // 충분히 큰 값으로 초기화

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    
    // 1. 인접 리스트 생성 (마을 번호, 가중치)
    vector<pair<int, int>> adj[51];
    for (auto r : road) {
        adj[r[0]].push_back({r[1], r[2]});
        adj[r[1]].push_back({r[0], r[2]});
    }

    // 2. 최단 거리 배열 초기화
    vector<int> dist(N + 1, INF);
    dist[1] = 0;

    // 3. 우선순위 큐 (거리, 마을 번호) - 최소 힙 구성
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        // 이미 처리된 더 짧은 경로가 있다면 스킵
        if (dist[curr] < current_dist) continue;

        for (auto edge : adj[curr]) {
            int next = edge.first;
            int weight = edge.second;

            // 현재 마을을 거쳐가는 것이 더 빠를 경우 업데이트
            if (dist[curr] + weight < dist[next]) {
                dist[next] = dist[curr] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    // 4. 거리 K 이하인 마을 개수 세기
    for (int i = 1; i <= N; i++) {
        if (dist[i] <= K) answer++;
    }

    return answer;
}