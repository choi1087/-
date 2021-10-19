#include<iostream>
#include<stack>
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
		stack<int>smallStack;
		stack<int>bigStack;
		for (int i = 0; i < N; i++) {
			int q;
			cin >> q;

			//½×±â
			if (q == 1) {
				int x;
				cin >> x;
				if (smallStack.empty()) {
					smallStack.push(x);
					bigStack.push(x);
				}
				else {
					int s = smallStack.top();
					if (s < x) {
						smallStack.push(s);
					}
					else {
						smallStack.push(x);
					}

					int b = bigStack.top();
					if (b > x) {
						bigStack.push(b);
					}
					else {
						bigStack.push(x);
					}					
				}

				cout << smallStack.top() << " " << bigStack.top() << "\n";

			}
			//Á¦°Å
			else {
				if (smallStack.empty()) {
					continue;
				}
				else {
					smallStack.pop();
					bigStack.pop();
				}				
			}
		}
	}

}