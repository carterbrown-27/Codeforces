#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n,x;
	cin >> n >> x;
	
	bool used[n+1] {false};
	vector<int> edges[n+1];
	for(int i = 0; i < n-1; i++){
		int u,v;
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	
	int dist[n+1];
	set<int> leaves;
	for(int i = 1; i <= n; i++){
		if(edges[i].size() == 1){
			leaves.insert(i);
		}
		dist[i] = 1e5;
	}
	
	
	queue<int> q;
	q.push(x);
	dist[x] = 0;
	
	while(!q.empty()){
		int c = q.front();
		q.pop();
		for(int i: edges[c]){
			if(dist[i] > 1e4){
				dist[i] = dist[c]+1;
				q.push(i);
			}
		}
	}
	
	
	bool ayush = true;
	while(true){
		int mx = 0;
		int mxl = -1;
		for(int l: leaves){
			if(l == x){
				cout << (ayush ? "Ayush" : "Ashish") << endl;
				return;
			}else if(dist[l] > mx){
				mx = dist[l];
				mxl = l;
			}	
		}
		
		leaves.erase(mxl);
		
		// update parent
		used[mxl] = true;
		if(!used[edges[mxl][0]]){
			leaves.insert(edges[mxl][0]);
			
			auto edg = edges[edges[mxl][0]];
			for(int i = 0; i < edg.size(); i++){
				if(edg[i] == mxl){
					edg.erase(edg.begin() + i);
					break;
				}				
			}
		}
		
		ayush = !ayush;
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}