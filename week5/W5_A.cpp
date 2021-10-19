#include<iostream>
using namespace std;


int t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		int N;
		cin >> N;

		int* signal = new int[N]; //���ļ�
		int* prefix = new int[N]; //���λ�, ���̻� ��ġ ����

		//���ļ� �Է�
		for (int i = 0; i < N; i++) {
			cin >> signal[i];
		}

		
		prefix[0] = 0; //���λ�, ���̻� 0��°�� ��ġ ���� 0
		int k = 0; //���� 0���� ����

		for (int i = 1; i < N; i++) {

			//��ġ ���̰� 0�̻��̰�, �ش� ���� k��° ���� ��ġ���� ������
			while (k > 0 && signal[i] != signal[k]) {
				k = prefix[k - 1]; //���� ��ġ ���̷� ����
			}

			//���� ���ļ��� k��° ���ļ��� ������
			if (signal[i] == signal[k]) {
				k++; //��ġ ���� ����
			}

			prefix[i] = k; //��ġ ���� ����
		}

		for (int i = 0; i < N - prefix[N - 1]; i++) {
			cout << signal[i] << " ";
		}
		cout << "\n";

	}
}