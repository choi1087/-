#include<iostream>
#include<deque>
using namespace std;

struct location {
	int r, c;
};

int dr[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dc[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

int t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while(t--) {
		int N;
		cin >> N;

		int** space = new int* [N + 1];
		bool** visited = new bool* [N + 1];
		for (int i = 0; i < N + 1; i++) {
			space[i] = new int[N + 1];
			visited[i] = new bool[N + 1];
			fill(space[i], space[i] + N + 1, 0);
			fill(visited[i], visited[i] + N + 1, false);
		}		

		location inha, safe, knife, gunner;
		cin >> inha.r >> inha.c >> safe.r >> safe.c;
		cin >> knife.r >> knife.c >> gunner.r >> gunner.c;

		space[inha.r][inha.c] = 0;

		//소총수
		for (int i = 0; i < 8; i++) {
			int tempR = gunner.r;
			int tempC = gunner.c;

			while (true) {
				int nr = tempR + dr[i];
				int nc = tempC + dc[i];

				//범위 벗어나면
				if (nr <= 0 || nc <= 0 || nr > N || nc > N) {
					break;
				}

				//검사를 만나면
				if (nr == knife.r && nc == knife.c) {
					break;
				}

				space[nr][nc] = -1;
				tempR = nr;
				tempC = nc;
			}
		}

		//검사
		for (int i = 0; i < 8; i++) {
			int nr = knife.r + dr[i];
			int nc = knife.c + dc[i];

			//범위 벗어나면
			if (nr <= 0 || nc <= 0 || nr > N || nc > N) {
				continue;
			}

			if (nr == gunner.r && nc == gunner.c) {
				continue;
			}

			space[nr][nc] = -1;
		}

		//


		deque<location>q;
		q.push_back({inha.r, inha.c});

		while (!q.empty()) {
			int nowR = q.front().r;
			int nowC = q.front().c;
			q.pop_front();

			visited[nowR][nowC] = true;

			for (int i = 0; i < 8; i++) {
				int nr = nowR + dr[i];
				int nc = nowC + dc[i];

				//범위 벗어나면
				if (nr <= 0 || nc <= 0 || nr > N || nc > N) {
					continue;
				}

				//이동 불가 지역
				if (space[nr][nc] == -1) {
					continue;
				}

				//방문한 적 있다면
				if (visited[nr][nc]) {
					continue;
				}

				space[nr][nc] =space[nowR][nowC] + 1;
				visited[nr][nc] = true;
				q.push_back({ nr, nc });				
			}
		}


		cout << space[safe.r][safe.c] << "\n";
	}
}