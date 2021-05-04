#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	// why did I do this question, it's just busy work... :/
	int n, t;
	cin >> n >> t;
	vector<int> a(n);
	
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	// not a switch for convenience
	// not trying to consolidate anything
	if(t==1){
		const int TARGET = 7777;
		set<int> st;
		for(int i = 0; i < n; i++){
			if(st.find(TARGET-a[i]) != st.end()){
				cout << "Yes" << endl;
				return;
			}
			st.insert(a[i]);
		}
		cout << "No" << endl;
		
	}else if(t==2){
		set<int> st;
		for(int i = 0; i < n; i++)
			st.insert(a[i]);
		cout << (st.size() == n ? "Unique" : "Contains duplicate") << endl;
	}else if(t==3){
		map<int,int> m;
		for(int i = 0; i < n; i++){
			if(++m[a[i]] > n/2){
				cout << a[i] << endl;
				return;
			}
		}
		cout << -1 << endl;
	}else if(t==4){
		sort(a.begin(), a.end());
		if(n%2 == 0) cout << a[n/2 - 1] << " ";
		cout << a[n/2] << endl;
		
	}else if(t==5){
		vector<int> b;
		for(int i = 0; i < n; i++)
			if(100 <= a[i] && a[i] < 1000) b.pb(a[i]);
		sort(b.begin(), b.end());
		for(int x: b){
			cout << x << " ";
		}
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}