#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>

using namespace std;

vector<vector<char>> map;
vector<vector<int>> dist_map;
int max_r, max_c;

#ifdef REDIRECT_IO
void input_redirection() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}
#endif

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int BFS(const vector<pair<int,int>>& fstart , int prow, int pcol) {
	queue<pair<int,int>> fq;
	queue<pair<int,int>> pq;
	for (const auto & entry : fstart)
		fq.push(entry);

	dist_map[prow][pcol] = 0;
	pq.push({prow, pcol});

	while (!pq.empty()) {
		int f_size = fq.size();
		while (f_size--) {
			int temp_frow = fq.front().first;
			int temp_fcol = fq.front().second;
			fq.pop();

			for (int i = 0; i < 4; i++)
			{
				if (temp_frow + dx[i] >= 0 && temp_frow + dx[i] < max_r && temp_fcol + dy[i] >= 0 && temp_fcol + dy[i] < max_c)
				{
					if (map[temp_frow + dx[i]][temp_fcol + dy[i]] == '.' || map[temp_frow + dx[i]][temp_fcol + dy[i]] == 'J')
					{
						map[temp_frow + dx[i]][temp_fcol + dy[i]] = 'F';
						fq.push({temp_frow + dx[i], temp_fcol + dy[i]});
					}
				}
			}
		}

		int p_size = pq.size();
		while (p_size--) {
			int temp_prow = pq.front().first;
			int temp_pcol = pq.front().second;
			pq.pop();

			//탈출 조건
			if (temp_prow == 0 || temp_prow == max_r - 1 || temp_pcol == 0 || temp_pcol == max_c - 1)
			{
				return dist_map[temp_prow][temp_pcol] + 1;
			}

			for (int i = 0; i < 4; i++) {
				if (temp_prow + dx[i] >= 0 && temp_prow + dx[i] < max_r && temp_pcol + dy[i] >= 0 && temp_pcol + dy[i] < max_c)
				{
					if (map[temp_prow + dx[i]][temp_pcol + dy[i]] == '.' && !dist_map[temp_prow + dx[i]][temp_pcol + dy[i]])
					{
						dist_map[temp_prow + dx[i]][temp_pcol + dy[i]] = dist_map[temp_prow][temp_pcol] + 1;
						pq.push({temp_prow + dx[i], temp_pcol + dy[i]});
					}
				}
			}
		}

	}
	return -1;
}

int main()
{
#ifdef REDIRECT_IO
	input_redirection();
#endif

	cin >> max_r >> max_c;
	map.assign(max_r, vector<char>(max_c));
	dist_map.assign(max_r, vector<int>(max_c));

	int r,c;
	vector<pair<int, int>> fstart;

	for (int i = 0; i < max_r; i++)
	{
		for (int j = 0; j < max_c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'F')
				fstart.push_back({i,j});
			if (map[i][j] == 'J')
				{
					r = i;
					c = j;
				}

		}
	}

	int answer = BFS(fstart, r, c);
	if (answer == -1) {
		cout << "IMPOSSIBLE";
	}
	else {
		cout << answer; 
	}

	return 0;
}