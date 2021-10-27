#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

struct Point {
	int x, y;
	double distance;	

	bool operator<(const Point& point) const {
		if (this->distance == point.distance) {
			if (this->x == point.x) {
				return this->y < point.y;
			}
			return this->x < point.x;
		}
		return this->distance < point.distance;
	}
};

int t;

//햄버거 가게
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		
		/*
			가까운 k개의 햄버거 가게 정보 필요
			Max Heap 기반 우선순위 큐를 생성하여, 가까운 k개의 햄버거 가게 정보만 저장
			우선순위 큐의 최댓값은 k번째로 가까운 햄버거 가게를 의미
			새로운 햄버거 가게가 입력될 떄마다, 
			우선순위 큐의 최댓값과 새로운 햄버거 가게를 비교하여
			더 먼 가게를 제거하고 k개의 햄버거 가게 정보만 유지
			우선순위 큐의 최댓값 출력
			Max Heap에 가까운 k개의 햄버거 가게만 저장
			새로운 가게가 입력될 때마다 Max Heap의 최댓값(k번째로 가까운 가게)출력
		*/

		int m, n, k; 
		cin >> m >> n >> k;

		priority_queue<Point>stores;

		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			//Point point = Point(x, y, sqrt(x * x + y * y));
			stores.push({ x, y, sqrt(x * x + y * y) }); //O(log K)

			int sSize = stores.size();
			if (sSize > k) {
				stores.pop(); //O(log K)
			}
			
		}


		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			//Point point = Point(x, y, sqrt(x * x + y * y));
			stores.push({ x, y, sqrt(x * x + y * y) }); //O(log K)
			stores.pop(); //O(log K)
			cout << stores.top().x << " " << stores.top().y << "\n";
		}
	}
}