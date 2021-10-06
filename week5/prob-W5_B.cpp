#include<iostream>
using namespace std;

int N, M;
int* house;

//거리가 가장 인접한 주민간의 거리로 가능한지 확인
bool check(int length) {
	int h = 1;  //주민이 입주 가능한 최소한의 집의 번호
	int cnt = 0; //현재 입주해 있는 주민의 수

	for (int i = 0; i < N; i++) {
		//i번째 집에 주민이 입주할 수 있는 경우
		if (h <= house[i]) {
			h = house[i] + length;
			cnt++;
		}
		// 모든 주민이 입주한 경우
		if (cnt == M) {
			return true;
		}
	}
	//입주하지 못한 주민이 있는 경우
	return false;
}

//정답 구간이 [left, right]에서 정답을 반환
int solution(int left, int right) {

	int middle; //정답 구간을 줄일 기준이 되는 중간 값

	//정답 구간의 크기가 1인 경우
	if (left == right) {
		return left;
	}

	//정답 구간의 크기가 2인 경우(바로 옆)
	if (left + 1 == right) {
		if (check(right)) {
			return right;
		}
		else {
			return left;
		}
	}

	middle = (left + right) / 2;

	//middle이 가장 인접한 주민간의 거리로 가능한 경우
	if (check(middle)) {
		//[middle, right] 구간에 대한 함수를 재귀적으로 호출
		return solution(middle, right);
	}

	//middle이 가장 인접한 주민간의 거리로 불가능한 경우
	else {		
		//[left, middle - 1] 구간에 대한 함수를 재귀적으로 호출
		return solution(left, middle - 1);
	}
	

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	house = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> house[i];
	}
	
	cout << solution(0, house[N - 1] - 1) << "\n";
}