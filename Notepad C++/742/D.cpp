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
	int s, n;
	cin >> s >> n;
	
	vector<int> ans;
	int c = 1;
	while(s > 0){
		if(s%10)
			ans.pb((s%10)*c);
		c *= 10;
		s /= 10;
	}
	
	for(int a: ans)
		cout << a << " ";
	cout << endl;

	int pos = 0;
	while(ans.size() < n){
		c = 1;
		while(ans[pos] % 10 == 0){
			c *= 10;
			ans[pos] /= 10;
		}
		
		if(!c) continue;
		
		cout << pos << " " << c << endl;
		
		for(int j = 0; j < ans[pos]/c*10 - 1; j++)
			ans.pb(c);
		
		ans[pos] = c;
		pos++;
	}
	
	for(int i = n; i < ans.size(); i++){
		ans[n-1] += ans[i];
	}
		
	for(int i = 0; i < n; i++)
		cout << ans[i] << " ";
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