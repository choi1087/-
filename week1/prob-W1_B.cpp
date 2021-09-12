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
			
			//�ױ�
			if (q == 1) {
				int num;
				cin >> num;

				//������ ����� ���
				if (minStack.empty()) {
					maxStack.push(num);
					minStack.push(num);
				}
				else {
					//�ִ밪 ����
					if (num > maxStack.top()) {
						maxStack.push(num);
					}
					else {
						maxStack.push(maxStack.top());
					}

					//�ּҰ� ����
					if (num < minStack.top()) {
						minStack.push(num);						
					}
					else {
						minStack.push(minStack.top());
					}
				}											
				
				cout << minStack.top() << " " << maxStack.top() << "\n";
			}

			//����
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