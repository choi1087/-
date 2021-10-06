#include<iostream>
using namespace std;

int N, M;
int* house;

//�Ÿ��� ���� ������ �ֹΰ��� �Ÿ��� �������� Ȯ��
bool check(int length) {
	int h = 1;  //�ֹ��� ���� ������ �ּ����� ���� ��ȣ
	int cnt = 0; //���� ������ �ִ� �ֹ��� ��

	for (int i = 0; i < N; i++) {
		//i��° ���� �ֹ��� ������ �� �ִ� ���
		if (h <= house[i]) {
			h = house[i] + length;
			cnt++;
		}
		// ��� �ֹ��� ������ ���
		if (cnt == M) {
			return true;
		}
	}
	//�������� ���� �ֹ��� �ִ� ���
	return false;
}

//���� ������ [left, right]���� ������ ��ȯ
int solution(int left, int right) {

	int middle; //���� ������ ���� ������ �Ǵ� �߰� ��

	//���� ������ ũ�Ⱑ 1�� ���
	if (left == right) {
		return left;
	}

	//���� ������ ũ�Ⱑ 2�� ���(�ٷ� ��)
	if (left + 1 == right) {
		if (check(right)) {
			return right;
		}
		else {
			return left;
		}
	}

	middle = (left + right) / 2;

	//middle�� ���� ������ �ֹΰ��� �Ÿ��� ������ ���
	if (check(middle)) {
		//[middle, right] ������ ���� �Լ��� ��������� ȣ��
		return solution(middle, right);
	}

	//middle�� ���� ������ �ֹΰ��� �Ÿ��� �Ұ����� ���
	else {		
		//[left, middle - 1] ������ ���� �Լ��� ��������� ȣ��
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