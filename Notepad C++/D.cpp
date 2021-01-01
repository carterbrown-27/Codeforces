#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	
	int w[n];
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin >> w[i];
		sum += w[i];
	}
	
	vector<set<int>> graph(n);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		graph[u].insert(v);
		graph[v].insert(u);
	}

	
	// emplace internal nodes with leaf children into queue
	// weight, node
	priority_queue<pair<int, pair<int,int>>> q;
	for(int i = 0; i < n; i++){
		if(graph[i].size() == 1){
			int v = *(graph[i].begin());
			q.push(mp(w[v], mp(v,i)));
		}
	}
	
	set<pair<int,int>> secure;
	
	// do each colouring
	cout << sum << " ";
	for(int c = 0; c < n-1; c++){
		if(q.empty()){
			cout << "unexpected end\n";
			break;
		}
		
		auto p = q.top();
		
		pair<int,int> e = p.second;
		int mx = p.first;
		int mxi = e.first;
		int prev = e.second;
		
		bool flag = true;
		while(flag){
			flag = false;
			vector<pair<int,int>> tmp;
			int tmxi = mxi;
			int tprev = prev;
			
			for(int v: graph[tmxi]){
				// find new max
				auto ne = mp(v, tprev);
				if(secure.find(ne) != secure.end()) continue;
				
				if(v != tprev){
					if(w[v] > mx){
						q.push(mp(mx, mp(mxi,tprev)));
						mx = w[v];
						prev = tmxi;
						mxi = v;
						flag = true;
					}else{
						q.push(mp(w[v], mp(v,tprev)));
					}
				}else{
					tmp.pb(mp(v,tprev));
				}
				// cout << v << endl;
			}
			
			if(flag){
				for(auto p: tmp){
					q.push(mp(w[p.first], p));
				}
			}
			
			secure.insert(mp(prev, mxi));
			secure.insert(mp(mxi, prev));
			cout << "@" << prev << " " << mxi <<  "\n";
		}
		
		if(c >= 1){
			sum += mx;
			cout << sum << " ";
		}
	}
	cout << "\n";
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}