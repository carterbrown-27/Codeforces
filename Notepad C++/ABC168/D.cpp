#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> edges[n+1];
	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	
	int prev[n+1] {0};
	queue<int> q;
	q.push(1);
	prev[1] = 1;
	
	while(!q.empty()){
		int c = q.front();
		q.pop();
		for(int i: edges[c]){
			if(prev[i] == 0){
				prev[i] = c;
				q.push(i);
			}
		}
	}
	
	bool works = true;
	for(int i = 2; i <= n; i++){
		if(prev[i] == 0){
			works = false;
			break;
		}
	}
	
	if(works){
		cout << "Yes" << endl;
		for(int i = 2; i <= n; i++){
			cout << prev[i] << endl;
		}
	}else{
		cout << "No" << endl;
	}
}

int main() {
	solve();
	return 0;
}