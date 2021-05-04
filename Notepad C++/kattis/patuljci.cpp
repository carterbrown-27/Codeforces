#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int sum = 0;
	set<int> st;
	vector<int> a;
	
	for(int i = 0; i < 9; i++){
		int v; 
		cin >> v;
		st.insert(v);
		sum += v;
		a.pb(v);
	}
	
	sum -= 100;
	for(int i: st){
		auto j = st.find(sum-i);
		if(j != st.end()){
			st.erase(i);
			st.erase(j);
			break;
		}
	}
	
	for(int i: a)
		if(st.find(i) != st.end())
			cout << i << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}