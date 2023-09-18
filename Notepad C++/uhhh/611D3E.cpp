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

void solve(){
	int n;
	cin >> n;
	
	vector<int> a(n);
	for(auto &x: a)
		cin >> x;
	
	// max = |occ|
	sort(a.begin(), a.end());
	
	uset<int> occ;
	for(int &x: a){
		for(int i = x-1; i <= x+1; i++){
			if(occ.find(i) == occ.end()){
				occ.insert(i);
				break;
			}
		}
	}
	
	// a is sorted
	vector<bool> h(n+2);
	int p = -1;
	for(int &x: a){
		if(x == p)
			continue;
		p = x;
		
		if(!h[x] && !h[x-1]){
			h[x+1] = true;
		}
	}
	
	int mn = 0;
	for(bool b: h){
		mn += b;
		//cout << b;
	}
	//cout << endl;
	
	cout << mn << " " << occ.size() << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}