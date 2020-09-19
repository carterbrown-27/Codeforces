#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};

bool isLeaf(TreeNode* n){
	return n && (!n->left && !n->right);
}

bool isConnected(TreeNode* p, TreeNode* c){
	return p && c && (p->left == c || p->right == c);
}

int main() {
	TreeNode* n = new TreeNode();
	TreeNode* c = new TreeNode();
	n->left = c;
	cout << isConnected(n,c) << endl;
	cout << isLeaf(n) << endl;
}