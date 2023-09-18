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

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	
	// Could move this loop into dp loop as well
	int sum = 0;
	vector<vector<int>> f_gaps(n), b_gaps(n);
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;

		auto calc_gaps = [&](vector<int>& gaps) {
			int g = 0;
			for(char c: s){
				if(c == '1'){
					gaps.pb(g);
					g = 0;
				}else{
					g++;
				}
			}
			gaps.pb(0);
		};
		
		calc_gaps(f_gaps[i]);		
		reverse(s.begin(), s.end());
		calc_gaps(b_gaps[i]);
		
		// find time spent w/o skips
		size_t end_time = s.find_last_of('1');
		if(end_time != string::npos)
			sum += end_time - s.find_first_of('1') + 1;
	}

	
	// amount skippable	
	int dp[n+1][k+1];
	memset(dp, 0, sizeof dp);
	// dp[0][0] = 0;
	int day_best[k+1][k+1];
	int day_best_fin[k+1];
	
	for(int i = 1; i <= n; i++){
		memset(day_best, 0, sizeof day_best);
		
		int classes = f_gaps[i-1].size()-1;
		int mxs = min(k, classes);
		// cout << i << " " << classes << endl;
		for(int f = 0; f <= mxs; f++){
			for(int b = 0; b <= mxs && b+f <= mxs; b++){
				day_best[f][b] = max(
					f > 0 ? (day_best[f-1][b] + (b+f < classes ? f_gaps[i-1][f] : 0) + 1) : 0,
					b > 0 ? (day_best[f][b-1] + (b+f < classes ? b_gaps[i-1][b] : 0) + 1) : 0
				);
			}
		}
		
		// test
		for(int kt = 0; kt <= k; kt++){
			int mx = 0;
			for(int b = 0; b <= kt; b++){
				//cout << day_best[i][kt-b][b] << " ";
				mx = max(mx, day_best[kt-b][b]);
			}
			day_best_fin[kt] = mx;
			//cout << "-->" << day_best_fin[i][kt] << endl;
		}
		
		for(int j = 0; j <= k; j++){
			for(int skp = 0; skp <= j; skp++){
				dp[i][j] = max(dp[i][j], dp[i-1][j-skp] + day_best_fin[skp]);
			}
		}
	}
	
	int mx = 0;
	for(int skp = 0; skp <= k; skp++){
		mx = max(mx, dp[n][skp]);
	}
	
	cout << sum - mx << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}