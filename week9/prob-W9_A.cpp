#include<iostream>

using namespace std;

//{x^n mod M, x^1 + x^2 + ... + x^n modM} 계산
pair<long long, long long>geoSeries(long long x, long long n, long long m) {
	if (n == 1) {
		return { x % m, x % m };
	}

	pair<long long, long long>half = geoSeries(x, abs(n / 2), m); //재귀호출
	long long exp = half.first; // x^(abs(n/2) mod m
	long long sum = half.second; // x^1 + x^2 + x^3 + ... + x^(abs(n/2) mod m

	if (n % 2 == 0) {
		return { (exp * exp) % m,((1 + exp) * sum) % m };
	}
	else {
		return { (x * exp * exp) % m, (x + x * (1 + exp) * sum) % m };
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		long long x, n, m; //x의 n제곱까지 합, m으로 나눈 나머지 출력
		cin >> x >> n >> m;
	
		//{x^n mod M, x^1 + x^2 + ... + x^n modM} 계산
		pair<long long, long long>answer = geoSeries(x, n, m);
		cout << answer.second << "\n";
	}
}