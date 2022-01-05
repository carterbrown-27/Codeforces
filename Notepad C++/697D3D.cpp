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

// Works
void solve() {
	int n, m;
	cin >> n >> m;
	
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	priority_queue<int> rq, iq;
	vector<int> rv;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x == 1){
			rv.pb(a[i]);
		}else{
			iq.push(a[i]);
		}
	}
	
	sort(rv.begin(), rv.end(), greater<int>());
	for(int i = 0; i < rv.size(); i+=2){
		rq.push(rv[i] + (i+1 < rv.size() ? rv[i+1] : 0));
	}
	
	int sum = 0, ans = 0;
	int rc = 0;
	while(sum < m){
		if(rq.empty() && iq.empty()){
			cout << -1 << endl;
			return;
		}else if(rq.empty()){
			sum += iq.top();
			iq.pop();
		}else if(iq.empty() || rq.top() >= iq.top() || sum + rq.top() >= m){
			sum += rq.top();
			rq.pop();
			rc++;
		}else{
			sum += iq.top();
			iq.pop();
		}
		ans += 2;
	}
	
	// overcounted
	if(rv.size() % 2 == 1 && rq.empty()){
		ans--;
	// oversummed
	}else if(rc*2-1 < rv.size() && sum - rv[rc*2-1] >= m){
		ans--;
		sum -= rv[rc*2-1];
	}

	// cout << sum << " " << ans << endl;
	cout << ans << endl;
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