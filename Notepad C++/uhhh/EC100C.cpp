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
	
	vector<ll> t(n), x(n);
	for(int i = 0; i < n; i++)
		cin >> t[i] >> x[i];
	
	const ll INF = 1e10;
	int ans = 0;
	ll pos = 0, time = 0;
	for(int i = 0; i < n; i++){
		time = t[i];
		ll diff = x[i] - pos;
		ll target = x[i];
		i++;
		
		// ignored commands
		bool outer_success = true;
		while(i < n && time + abs(diff) > t[i]){
			outer_success = false;
			// cout << "Ignore " << i << ": ";
			int dir = (diff > 0 ? 1 : -1);
			
			pos += (t[i] - t[i-1])*dir;
			ll next_pos = pos + (i+1 < n ? min(t[i+1], time + abs(diff))-t[i] : INF) * dir;
			
			if(dir == 1){
				pos = min(pos, target);
				next_pos = min(next_pos, target);
			}else{
				pos = max(pos, target);
				next_pos = max(next_pos, target);
			}
			
			auto l = pos, r = next_pos;
			if(diff < 0)
				swap(l,r);
			
			if(l <= x[i] && x[i] <= r){
				// cout << "SUCCESS";
				ans++;
			}
			// cout << endl;
			i++;
		}
		i--;
		
		if(outer_success){
			// cout << i << " " << "OUTER SUCCESS" << endl;
			ans++;
		}
		pos = target;
	}
	
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