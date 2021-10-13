#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

struct point {
	int x;
	int y;
};


int t;
//상하좌우, 대각선
int dr[8] = { 0, 0, -1, 1, -1, -1, 1, 1 };
int dc[8] = { -1, 1, 0,0, -1, 1, -1, 1 };


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		int N; //좌표 평면의 크기
		cin >> N;

		point inha, safe, knight, gunner;

		cin >> inha.x >> inha.y;
		cin >> safe.x >> safe.y;
		cin >> knight.x >> knight.y;
		cin >> gunner.x >> gunner.y;

		int** board = new int* [N + 1];
		for (int i = 0; i < N + 1; i++) {
			board[i] = new int[N + 1];
			memset(board[i], 0, sizeof(int) * (N + 1));
		}

		bool** visited = new bool* [N + 1];
		for (int i = 0; i < N + 1; i++) {
			visited[i] = new bool[N + 1];
			memset(visited[i], false, sizeof(bool) * (N + 1));
		}

		//소총수 범위
		for (int i = 0; i < 8; i++) {
			for (int j = 1; j < N; j++) {
				int nr = gunner.x + dr[i] * j;
				int nc = gunner.y + dc[i] * j;
				//범위 벗어나는 경우
				if (nr < 1 || nr >= N + 1 || nc < 1 || nc >= N + 1) {
					break;
				}

				//검사에 막히는 경우
				if ((nr == knight.x) && (nc == knight.y)) {
					break;
				}

				//빨강 처리
				board[nr][nc] = -1;
			}
		}

		//검사 범위
		for (int i = 0; i < 8; i++) {
			int nr = knight.x + dr[i];
			int nc = knight.y + dc[i];
			//범위 벗어나는 경우
			if (nr < 1 || nr >= N + 1 || nc < 1 || nc >= N + 1) {
				continue;
			}

			board[nr][nc] = -1;
		}


		//bfs 시작
		queue<point>q;

		//인하 위치에서 시작
		q.push({ inha.x, inha.y });

		//큐가 빌때까지
		while (!q.empty()) {			
			point now = q.front();
			q.pop();
			visited[now.x][now.y] = true; //방문처리(중복 방문 피하기 위함)

			//범위 벗어난 경우
			for (int i = 0; i < 8; i++) {
				int nr = now.x + dr[i];
				int nc = now.y + dc[i];
				if (nr < 1 || nr >= N + 1 || nc < 1 || nc >= N + 1) {
					continue;
				}

				//빨강 지역이거나 방문한 적 있다면
				if (board[nr][nc] < 0 || visited[nr][nc]) {
					continue;
				}

				board[nr][nc] = board[now.x][now.y] + 1;				
				q.push({ nr, nc });
				visited[nr][nc] = true;
			}
		}
		cout << board[safe.x][safe.y] << "\n";
	}
}