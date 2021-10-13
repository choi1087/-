#include<iostream>
#include<queue>
using namespace std;


//�մ��� ����
struct customerInfo {
	int useTime; //���� �̿� �ð�
	int cost; //����� ����
};

//������ ����
struct counterInfo {
	int endTime; //���� �̿����� �մ��� ����� ��ġ�� �ð�
	int number; //���� ��ȣ ����

	bool operator<(const counterInfo ci)const {

		if (this->endTime == ci.endTime) {
			return this->number > ci.number;
		}

		return this->endTime > ci.endTime;
	}
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	//�մ��� ������ ������ �迭
	customerInfo* customer = new customerInfo[M]; 

	//������ ������ �����ϴ� �켱���� ť
	//endTime, number�� �������� �켱���� ����
	priority_queue <counterInfo> counterPQ;
	//�� ���븶�� ����ϴ� �� ����
	int* costAnswer = new int[N] {0};

	//��� �մ��� ����� ��ġ�µ� �ҿ�Ǵ� �ð�
	int timeAnswer = 0;
	
	//�� �մ� ���� �Է�
	for (int i = 0; i < M; i++) {
		cin >> customer[i].useTime >> customer[i].cost;
	}

	//N���� ���븦 1~N���� �մ��� ���ʴ�� �̿�
	for (int i = 0; i < N; i++) {
		counterPQ.push({ customer[i].useTime, i });
		costAnswer[i] += customer[i].cost;
		timeAnswer = max(timeAnswer, customer[i].useTime);
	}

	//���� ���� �� ���븦 �켱���� ť�� �̿��Ͽ� ã��
	for (int i = N; i < M; i++) {
		counterInfo counterTemp = counterPQ.top();
		counterPQ.pop();

		//������ ������ ����
		counterTemp.endTime += customer[i].useTime;
		costAnswer[counterTemp.number] += customer[i].cost;
		timeAnswer = max(timeAnswer, counterTemp.endTime);

		//����� ������ ������ �켱���� ť�� ����
		counterPQ.push(counterTemp);
	}

	cout << timeAnswer << "\n";

	for (int i = 0; i < N; i++) {
		cout << costAnswer[i] << "\n";
	}	
}