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
	
	int l[n], r[n], c[n];
	for(int i = 0; i < n; i++){
		cin >> l[i] >> r[i] >> c[i];
	}
	
	vector<int> lm, rm;
	const int INF = 2e9+1;
	int mnlc = INF, mnrc = INF;
	int cur_mn = INF;
	
	for(int i = 0; i < n; i++){
		bool in_both = true;
		if(lm.empty() || l[i] <= l[lm[0]]){
			if(!lm.empty() && l[i] < l[lm[0]]){
				lm.clear();
				cur_mn = INF;
				mnlc = INF;
			}
			lm.pb(i);
			mnlc = min(mnlc, c[i]);
		}else{
			in_both = false;
		}
		
		if(rm.empty() || r[i] >= r[rm[0]]){
			if(!rm.empty() && r[i] > r[rm[0]]){
				rm.clear();
				cur_mn = INF;
				mnrc = INF;
			}
			rm.pb(i);
			mnrc = min(mnrc, c[i]);
		}else{
			in_both = false;
		}
		
		cur_mn = in_both ? min(cur_mn, c[i]) : min(cur_mn, mnlc + mnrc);
		// cout << in_lm << " " << in_rm << endl;
		cout << cur_mn << endl;
	}
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