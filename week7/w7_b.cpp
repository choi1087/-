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

//�ܹ��� ����
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		
		/*
			����� k���� �ܹ��� ���� ���� �ʿ�
			Max Heap ��� �켱���� ť�� �����Ͽ�, ����� k���� �ܹ��� ���� ������ ����
			�켱���� ť�� �ִ��� k��°�� ����� �ܹ��� ���Ը� �ǹ�
			���ο� �ܹ��� ���԰� �Էµ� ������, 
			�켱���� ť�� �ִ񰪰� ���ο� �ܹ��� ���Ը� ���Ͽ�
			�� �� ���Ը� �����ϰ� k���� �ܹ��� ���� ������ ����
			�켱���� ť�� �ִ� ���
			Max Heap�� ����� k���� �ܹ��� ���Ը� ����
			���ο� ���԰� �Էµ� ������ Max Heap�� �ִ�(k��°�� ����� ����)���
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