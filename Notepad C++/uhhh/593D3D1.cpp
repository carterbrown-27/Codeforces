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

// Solves both D1&D2
int main() {
	ios::sync_with_stdio(false);
	
	int n,k;
	cin >> n >> k;
	
	const int RB = 2e5; // RB=200 for easy version
	// <l,r>
	vector<pair<int,int>> segs(n+1);
	vector<vector<int>> v(RB+1);
	for(int i = 1; i <= n; i++){
		auto& [l,r] = segs[i];
		cin >> l >> r;
		
		v[l].pb(i);
		if(r+1 < v.size())
			v[r+1].pb(-i); // negative indicates delete this segment
	}
	
	// <r, i>
	vector<int> ans;
	set<pair<int,int>, greater<pair<int,int>>> actives;
	for(int x = 1; x < v.size(); x++){
		for(int i: v[x]){
			if(i > 0){
				actives.insert({segs[i].second, i});
			}else{
				actives.erase({segs[-i].second, -i});
			}
		}
		
		while(actives.size() > k){
			auto it = actives.begin();
			ans.pb(it->second);
			actives.erase(it);
		}
	}
	
	cout << ans.size() << endl;
	for(int x: ans)
		cout << x << " ";
	cout << endl;
	return 0;
}