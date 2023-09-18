#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

#define pb push_back

int main() {
	int n;
	cin >> n;
	
	vector<bool> vis(n);
	vector<pair<int,int>> ans;
	
	int next = 0;
	while(ans.size() < n-1)
	{
		cout << "? " << next+1 << endl;
		vector<vector<int>> d(n);
		int mx = 0, mxi = -1;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			d[x].pb(i);
			
			if(x >= mx && !vis[i]){
				mx = x;
				mxi = i;
			}
		}
		
		// for each dist
		int prev = next;
		for(int i = 1; i < n; i++){
			for(int v: d[i]){
				ans.pb({prev, v});
				vis[v] = true;
			}	
			
			if(d[i].size() == 1){
				prev = d[i][0];
			}else{
				break;
			}
		}
		
		vis[next] = true;
		next = mxi;
	}
	
	cout << "!" << endl;
	for(auto p: ans){
		cout << p.first+1 << " " << p.second+1 << endl;
	}
	return 0;
}