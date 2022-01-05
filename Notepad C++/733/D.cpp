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
	int n;
	cin >> n;
	
	int a[n];
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		a[i] = v-1;
	}
	
	set<int> unused;
	for(int i = 0; i < n; i++)
		unused.insert(i);
	
	map<int, int> mp;
	vector<int> frees;
	int k = 0;
	int b[n];
	for(int i = 0; i < n; i++){
		int w = a[i];
		if(unused.find(w) != unused.end()){
			b[i] = w;
			unused.erase(w);
			mp[w] = i;
			k++;
		}else{
			b[i] = -1;
			frees.pb(i);
		}
	}
	
	// unused size == frees size
	if(unused.size() == 1){
		int u = *(unused.begin());
		int i = frees[0];
		if(i != u){
			// no switch
			b[i] = u;
		}else{
			// position to switch with
			int mai = mp[a[i]];
			b[i] = b[mai];
			b[mai] = u;
			// mp[a[i]] = i;
		}
	}else{
		// no conflicts as it's in reverse order ?? 
		for(int i: frees){
			// should only go up one
			for(int x: unused){
				if(x != i){
					b[i] = x;
					unused.erase(x);
					break;
				}
			}
			// should only happen when one left
			if(b[i] == -1){
				b[i] = *(unused.begin());
				swap(b[i], b[frees[0]]);
			}
		}
	}
	
	cout << k << endl;
	for(int i = 0; i < n; i++){
		cout << b[i]+1 << " ";
	}
	cout << endl;
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