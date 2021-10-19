#include<iostream>
#include<vector>
using namespace std;

int t;

struct Node {
	int parent = 0;
	vector<int>child;
	int length = 0;
};

void treeTraversal(int u, int* wordLength, Node* tree) {
	if (u == 1) {
		wordLength[u] = 4;
	}
	else {
		//본인 + 부모 길이
		wordLength[u] = tree[u].length + wordLength[tree[u].parent] + 1; 
	}

	for (int i = 0; i < tree[u].child.size(); i++) {
		treeTraversal(tree[u].child[i], wordLength, tree);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		int N;
		cin >> N; //디렉토리 개수

		Node* tree = new Node[N + 1];
		int* wordLength = new int[N + 1];

		//단어 부모, 자식 관계
		for (int i = 0; i < N - 1; i++) {
			int a, b;
			cin >> a >> b;
			tree[a].child.push_back(b);
			tree[b].parent = a;
		}

		//단어 입력
		for (int i = 1; i < N + 1; i++) {
			string str;
			cin >> str;
			tree[i].length = str.length();
		}
		

		//트리 순회
		treeTraversal(1, wordLength, tree);

		for (int i = 1; i < N + 1; i++) {
			cout << wordLength[i] << "\n";
		}

	}

}