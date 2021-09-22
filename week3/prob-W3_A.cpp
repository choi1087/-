#include<iostream>
#include<vector>
using namespace std;

int t;

struct Node {
	int parent = 0;
	vector<int> children;
	int length = 0;
};

void treeTraversal(int u, int* directory, Node* tree) {
	if (u == 1) {
		directory[u] = 4;
	}
	else {
		directory[u] = directory[tree[u].parent] + 1 + tree[u].length;
	}

	for (int i = 0; i < tree[u].children.size(); i++) {
		treeTraversal(tree[u].children[i], directory, tree);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while (t--) {
		int n; //디렉토리 개수
		cin >> n;
		Node* tree = new Node[n + 1];
		int* directory = new int[n + 1];

		for (int i = 1; i < n; i++) {
			int a, b;
			cin >> a >> b;
			tree[a].children.push_back(b);
			tree[b].parent = a;
		}

		for (int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			tree[i].length = s.length();
		}

		//트리 순회
		treeTraversal(1, directory, tree);

		for (int i = 1; i <= n; i++) {
			cout << directory[i] << "\n";
		}
	}
}

//Wrong Anwser
//#include<iostream>
//#include<utility>
//#include<algorithm>
//using namespace std;
//
//int t;
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	cin >> t;
//	while (t--) {
//		int n; //디렉토리의 개수
//		cin >> n;
//
//		//A->B 디렉토리 연관관계
//		pair<unsigned int, unsigned int>* relationship = new pair<unsigned int, unsigned int>[n + 1];		
//		for (int i = 1; i < n; i++) {
//			int a, b;
//			cin >> a >> b;
//			relationship[i] = make_pair(a, b);
//		}
//		sort(relationship, relationship + n);
//	
//		// (index, name)
//		string* directory = new string[n + 1];
//		for (int i = 1; i <= n; i++) {
//			string name;
//			cin >> name;
//			directory[i] = name;
//		}
//
//		for (int i = 1; i < n; i++) {
//			int start = relationship[i].first;
//			int end = relationship[i].second;
//
//			directory[end] = directory[start] + "/" + directory[end];
//		}
//
//		for (int i = 1; i <= n; i++) {
//			cout << directory[i].length() << "\n";
//			cout << directory[i] << endl;
//		}
//	}
//}