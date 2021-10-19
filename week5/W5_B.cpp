#include<iostream>
using namespace std;

int N, M; //집의 수, 주민의 수
int* house;

//거리가 가장 인접한 주민간의 거리 가능?
//length이 적절한지 확인
bool check(int length) {
	int h = 1; //주민이 입주가능한 최소한의 집 번호
	int cnt = 0; //현재 입주해 있는 주민의 수

	for (int i = 0; i < N; i++) {
		if (h <= house[i]) {
			h = house[i] + length;
			cnt++;
		}

		//모든 주민 입주 가능
		if (cnt == M) {
			return true;
		}
	}

	//모든 주민 입주 불가능
	return false;

}


int solution(int left, int right) {

	int middle;

	if (left == right) {
		return left;
	}

	if (left + 1 == right) {
		if (check(right)) {
			return right;
		}
		else {
			return left;
		}
	}

	middle = (left + right) / 2;

	//middle이 가장 인접한 주민가능 거리?
	if (check(middle)) {
		return solution(middle, right);
	}
	else {
		return solution(left, middle - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	house = new int[N + 1];

	for (int i = 0; i < N; i++) {
		cin >> house[i];
	}

	cout << solution(0, house[N - 1] - 1) << "\n";
}