#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using uset = unordered_set<T>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

void solve() {
	const int P = 8;
	
	int n;
	cin >> n;
	vector<vector<int>> prefs(n, vector<int>(P));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < P; j++){
			int v;
			cin >> v;
			prefs[i][j] = v-1; // maps to binary #s 0..7
		}
	}
	
	vector<vector<int>> adj(P);
	
	for(int i = 0; i < P; i++){
		int tmp = i;
		int m = P/2;
		while(m > 0){
			if(tmp >= m){
				// cout << i << " " << i - m << "\n";
				// bit is 1
				adj[i].pb(i-m);
				adj[i-m].pb(i);
				tmp-=m;
			}else{
				// cout << i << " " << i + m << "\n";
				adj[i].pb(i+m);
				adj[i+m].pb(i);
			}
			m/=2;
		}
	}
	
	reverse(prefs.begin(), prefs.end());
	
	vector<int> outcomes(P);
	for(int i = 0; i < P; i++) 
		outcomes[i] = i;
	
	for(int i = 0; i < n; i++){
		vector<int> tmp(P);
		
		for(int s = 0; s < P; s++){
			int mn = P, mni = -1;
			
			for(int e: adj[s]){
				int v = prefs[i][outcomes[e]];
				if(v < mn){
					mn = v;
					mni = outcomes[e];
				}
			}
			tmp[s] = mni;
		}
		outcomes = tmp;
	}
	
	int ans = outcomes[0];
	string ansStr = "";
	int m = P/2;
	while(m > 0){
		if(ans >= m){
			ansStr+="Y";
			ans-=m;
		}else{
			ansStr+="N";
		}
		m/=2;
	}
	cout << ansStr << endl;
}

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}