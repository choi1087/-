#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int t, n;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	while (t--) {
		int minValue = 100001, maxValue = -1;
		stack<int> minStack;
		stack<int> maxStack;
		cin >> n;
		while (n--) {
			int q;			
			cin >> q;
			
			//½×±â
			if (q == 1) {
				int num;
				cin >> num;
				if (num > maxValue) {
					maxValue = num;
					maxStack.push(maxValue);
				}
				else {
					int temp1 = maxStack.top();
					maxStack.push(temp1);
				}

				if (num < minValue) {
					minValue = num;
					minStack.push(minValue);
				}
				else {
					int temp2 = minStack.top();
					minStack.push(temp2);
				}
				cout << minStack.top() << " " << maxStack.top() << "\n";
			}
			//»©±â
			else {				
				minStack.pop();
				maxStack.pop();
			}
		}
	}
	return 0;
}