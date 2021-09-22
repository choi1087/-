#include<iostream>
#include<vector>
using namespace std;

struct roadInfo {
	int neighbor, distance;
};

int t, answer;

//u가 root인 트리에 대한 검색
int treeSearch(int u, vector<roadInfo>* house, bool* visitedHouse) {
	//노드 u의 각 자식 노드와 연결된 leaf 노드
	int maxDistance = 0, secondMaxDistance = 0;
	//노드 u와의 거리들 중 가장 큰 2개의 값을 max, second에 저장
	int tempDistance;

	visitedHouse[u] = true;
	for (int i = 0; i < house[u].size(); i++) {
		//이전에 방문한 적 없다면		
		if (visitedHouse[house[u][i].neighbor] == false) {			
			tempDistance = treeSearch(house[u][i].neighbor, house, visitedHouse) + house[u][i].distance;
			if (tempDistance > maxDistance) {
				swap(tempDistance, maxDistance);
			}
			if (tempDistance > secondMaxDistance) {
				swap(tempDistance, secondMaxDistance);
			}
		}
	}

	answer = max(answer, maxDistance + secondMaxDistance);

	return maxDistance;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		int n; // 집 개수
		cin >> n;
		vector<roadInfo>* house = new vector<roadInfo>[n + 1];
		bool* visitedHouse = new bool[n + 1]{ false };
		answer = 0;
		for (int i = 1; i < n; i++) {
			int u, v, d;
			cin >> u >> v >> d;
			house[u].push_back({ v, d });
			house[v].push_back({ u, d });			
		}
		
		
		treeSearch(1, house, visitedHouse);
		cout << answer << "\n";			
	}
}



// 플로이드 워셜
//#include<iostream>
//using namespace std;
//
//int t;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> t;
//	while (t--) {
//		int n; //인하마을 집 개수
//		cin >> n;
//		int** relationship = new int* [n];
//		for (int i = 0; i < n; i++) {
//			relationship[i] = new int[n];
//			fill(relationship[i], relationship[i] + n, 1001);
//		}
//
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				if (i == j) {
//					relationship[i][j] = 0;
//				}
//			}
//		}
//		
//		for (int i = 0; i < n - 1; i++) {
//			int v, u, d;
//			cin >> v >> u >> d;
//			relationship[v - 1][u - 1] = d;
//			relationship[u - 1][v - 1] = d;
//		}
//
//		for (int k = 0; k < n; k++) {
//			for (int i = 0; i < n; i++) {
//				for (int j = 0; j < n; j++) {
//					relationship[i][j] = min(relationship[i][j], relationship[i][k] + relationship[k][j]);
//				}
//			}
//		}
//
//		int maxDistance = -1;
//		for (int i = 0; i < n - 1; i++) {
//			for (int j = i + 1; j < n; j++) {
//				if (relationship[i][j] > maxDistance) {
//					maxDistance = relationship[i][j];
//				}
//			}
//		}
//		cout << maxDistance << "\n";
//	}
//}