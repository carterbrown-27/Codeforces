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
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	ll a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	map<ll,minpq<int>> idxs;
	for(int i = 0; i < n; i++){
		idxs[a[i]].push(i);
	}
	
	for(auto &p: idxs){
		auto &pq = p.second;
	
		while(pq.size() >= 2){
			int i = pq.top(); pq.pop();
			int j = pq.top(); pq.pop();
			// cout << p.first << " " << i << " " << j << endl;
			a[i] = -1;
			a[j] *= 2;
			idxs[a[j]].push(j);
		}
	}
	
	vector<ll> ans;
	for(int i = 0; i < n; i++)
		if(a[i] != -1)
			ans.pb(a[i]);
	
	cout << ans.size() << endl;
	for(ll x: ans)
		cout << x << " ";
	cout << endl;

	return 0;
}