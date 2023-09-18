#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point {
	int x,y;
};

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

#define pb push_back

void solve() {
	int n;
	cin >> n;
	
	vector<int> ans(n+1);
	uset<int> unv;
	for(int i = 1; i <= n; i++)
		unv.insert(i);
	
	while(!unv.empty()){
		int i = *unv.begin();
		int v;
		do{
			cout << "? " << i << endl;
			cin >> v;
		} while (v != i);
		
		// we have identity now
		int prev = i;
		do{
			cout << "? " << i << endl;
			cin >> v;
			ans[prev] = v;
			prev = v;
			unv.erase(v);
		} while (v != i);
		
		// jic
		if(unv.find(i) != unv.end())
			unv.erase(i);
	}
	
	cout << "! ";
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << endl;
}

int main() {
	// ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}