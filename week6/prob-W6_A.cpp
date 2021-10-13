#include<iostream>
#include<queue>
using namespace std;


//손님의 정보
struct customerInfo {
	int useTime; //계산대 이용 시간
	int cost; //계산할 가격
};

//계산대의 정보
struct counterInfo {
	int endTime; //현재 이용중인 손님이 계산을 마치는 시간
	int number; //계산대 번호 저장

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
	//손님의 정보를 저장할 배열
	customerInfo* customer = new customerInfo[M]; 

	//계산대의 정보를 저장하는 우선순위 큐
	//endTime, number가 작을수록 우선순위 높음
	priority_queue <counterInfo> counterPQ;
	//각 계산대마다 계산하는 총 가격
	int* costAnswer = new int[N] {0};

	//모든 손님이 계산을 마치는데 소요되는 시간
	int timeAnswer = 0;
	
	//각 손님 정보 입력
	for (int i = 0; i < M; i++) {
		cin >> customer[i].useTime >> customer[i].cost;
	}

	//N개의 계산대를 1~N번의 손님이 차례대로 이용
	for (int i = 0; i < N; i++) {
		counterPQ.push({ customer[i].useTime, i });
		costAnswer[i] += customer[i].cost;
		timeAnswer = max(timeAnswer, customer[i].useTime);
	}

	//가장 먼저 빈 계산대를 우선순위 큐를 이용하여 찾음
	for (int i = N; i < M; i++) {
		counterInfo counterTemp = counterPQ.top();
		counterPQ.pop();

		//계산대의 정보를 변경
		counterTemp.endTime += customer[i].useTime;
		costAnswer[counterTemp.number] += customer[i].cost;
		timeAnswer = max(timeAnswer, counterTemp.endTime);

		//변경된 계산대의 정보를 우선순위 큐에 삽입
		counterPQ.push(counterTemp);
	}

	cout << timeAnswer << "\n";

	for (int i = 0; i < N; i++) {
		cout << costAnswer[i] << "\n";
	}	
}