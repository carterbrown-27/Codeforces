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

int main() {
	ios::sync_with_stdio(false);
	
	int n, q;
	cin >> n >> q;
	n++;
	
	int d[n], c[n];
	d[0] = 1e9;
	c[0] = 0;
	for(int i = n; i-- > 1;)
		cin >> d[i] >> c[i];
	
	int par[n];
	par[0] = 0;
	stack<int> sk;
	
	for(int i = 1; i < n; i++){
		while(!sk.empty() && d[sk.top()] <= d[i]){
			sk.pop();
		}
		
		par[i] = (sk.empty() ? 0 : sk.top());
		sk.push(i);
	}
	
	// binlift
	int L = 1;
	while(1<<(++L) < n);
	
	int up[n][L];
	for(int i = 0; i < n; i++){
		up[i][0] = i;
		up[i][1] = par[i];
		for(int j = 2; j < L; j++){
			up[i][j] = up[up[i][j-1]][j-1];
		}
	}
	
	int dp[n];
	dp[0] = 0;
	for(int i = 1; i < n; i++){
		dp[i] = c[par[i]] + dp[par[i]];
		cout << dp[i] << " ";
	}
	cout << endl;
	
	for(int t = 0; t < q; t++){
		int r, v;
		cin >> r >> v;
		
		r = n-r;
		int tc = dp[r] + c[r];
		cout << tc << endl;
		
		int pos = r, prevl = L-1;
		while(pos > 0){
			int lb = 0, rb = prevl;
			while(lb<rb){
				int m = (lb+rb)/2;
				int cap = tc - dp[up[pos][m]];
				if(cap == v){
					lb = m;
					break;
				}else if(cap < v){
					lb = m+1;
				}else{
					rb = m;
				}
				// cout << lb << " ";
			}
			// cout << pos << "-";
			if(lb == 0)
				break;			
			pos = up[pos][lb];
			prevl = lb;
		}
		
		cout << (pos == 0 ? 0 : n-pos) << endl;
	}
	
	return 0;
}