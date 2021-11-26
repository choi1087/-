#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		int* message = new int[m];
		int* read = new int[m];
		fill_n(read, m, n);		

		for (int i = 0; i < m; i++) {
			cin >> message[i];
		}

		set<int> people;
		for (int i = m - 1; i >= 0; i--) {
			people.insert(message[i]);			
			read[i] -= people.size();			
		}

		for (int i = 0; i < m; i++) {
			cout << read[i] << "\n";
		}		

		/*
		시간초과
		
		vector<set<int>> check;

		for (int i = 0; i < m; i++) {
			int a;
			cin >> a;
			set<int>iSet;
			iSet.insert(a);
			check.push_back(iSet);
			for (int j = 0; j < i; j++) {
				check[j].insert(a);				
			}
		}

		for (int i = 0; i < m; i++) {
			cout << n - check[i].size() << "\n";
		}*/
	}
}