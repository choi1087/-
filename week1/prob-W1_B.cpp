#include<iostream>
#include<stack>
using namespace std;

int t;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		stack<int> minStack;
		stack<int> maxStack;
		int n;
		cin >> n;
		while (n--) {
			int q;			
			cin >> q;
			
			//쌓기
			if (q == 1) {
				int num;
				cin >> num;

				//스택이 비었을 경우
				if (minStack.empty()) {
					maxStack.push(num);
					minStack.push(num);
				}
				else {
					//최대값 스택
					if (num > maxStack.top()) {
						maxStack.push(num);
					}
					else {
						maxStack.push(maxStack.top());
					}

					//최소값 스택
					if (num < minStack.top()) {
						minStack.push(num);						
					}
					else {
						minStack.push(minStack.top());
					}
				}											
				
				cout << minStack.top() << " " << maxStack.top() << "\n";
			}

			//빼기
			else {		
				if (!minStack.empty()) {
					minStack.pop();
					maxStack.pop();
				}				
			}
		}
	}
	return 0;
}