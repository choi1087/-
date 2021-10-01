#include<iostream>
using namespace std;

int t;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		int x1, y1, x2, y2;
		int x3, y3, x4, y4;

		cin >> x1 >> y1 >> x2 >> y2;
		cin >> x3 >> y3 >> x4 >> y4;

		if (x1 > x2) {
			swap(x1, x2);
			swap(y1, y2);
		}
		if (x3 > x4) {
			swap(x3, x4);
			swap(y3, y4);
		}

		if (x1 == x2 && x3 == x4) {
			if (x1 != x3) {
				cout << 1 << "\n";
			}
			else if (x1 == x3) {
				if (y1 > y2) {
					swap(y1, y2);
				}
				if (y3 > y4) {
					swap(y3, y4);
				}
				if (y1 > y4 || y3 > y2) {
					cout << 1 << "\n";
				}
				if (y1 == y4 || y3 == y2) {
					cout << 2 << "\n";
				}
				if ((y1 <= y3 && y4 <= y2) || (y3 <= y1 && y2 <= y4)) {
					cout << 4 << "\n";
				}
				if ((y1 > y3 && y1 < y4 && y4 < y2) || (y3 > y1 && y3 < y2 && y2 < y4)) {
					cout << 3 << "\n";
				}
			}
		}		
		else if (x1 == x2 && y3 == y4) {
			int X = x1;
			int Y = y3;
			if ((min(y1, y2) <= Y && Y <= max(y1, y2)) && (x3 <= X && X <= x4)) {
				cout << 2 << "\n";
			}
			else {
				cout << 1 << "\n";
			}
		}
		else if (y1 == y2 && x3 == x4) {
			int X = x3;
			int Y = y1;
			if ((x1 <= X && X <= x2) && (min(y3, y4) <= Y && Y <= max(y3, y4))) {
				cout << 2 << "\n";
			}
			else {
				cout << 1 << "\n";
			}
		}
		else if (y1 == y2 && y3 == y4) {
			if (y1 != y3) {
				cout << 1 << "\n";
			}
			else if (y1 == y3) {
				if (x1 > x4 || x3 > x2) {
					cout << 1 << "\n";
				}
				if (x1 == x4 || x3 == x2) {
					cout << 2 << "\n";
				}
				if ((x1 <= x3 && x4 <= x2) || (x3 <= x1 && x2 <= x4)) {
					cout << 4 << "\n";
				}
				if ((x1 > x3 && x1 < x4 && x4 < x2) || (x3 > x1 && x3 < x2 && x2 < x4)) {
					cout << 3 << "\n";
				}
			}
		}

	}
}