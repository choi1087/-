#include<iostream>
#include<queue>
using namespace std;

//customer information
struct customerInfo {
	int useTime;
	int cost;
};

//counter information
struct counterInfo {
	int endTime;
	int number;

	bool operator<(const counterInfo ci)const {
		if (this->endTime == ci.endTime) {
			return this->number > ci.number;
		}
		return this->endTime > ci.endTime;
	}

};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M; //계산대, 손님 수

	cin >> N >> M;

	customerInfo* customer = new customerInfo[M];
	priority_queue<counterInfo>counterPQ;
	int* counter = new int[N] {0};
	int totalTime = 0;

	for (int i = 0; i < M; i++) {
		cin >> customer[i].useTime >> customer[i].cost;
	}

	for (int i = 0; i < N; i++) {
		counterPQ.push({ customer[i].useTime, i });
		counter[i] += customer[i].cost;
		totalTime = max(totalTime, customer[i].useTime);
	}

	for (int i = N; i < M; i++) {
		counterInfo counterTemp = counterPQ.top();
		counterPQ.pop();

		counterTemp.endTime += customer[i].useTime;
		counter[counterTemp.number] += customer[i].cost;
		totalTime = max(totalTime, counterTemp.endTime);

		counterPQ.push(counterTemp);
	}

	cout << totalTime << endl;

	for (int i = 0; i < N; i++) {
		cout << counter[i] << "\n";
	}
}