#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T>
using uset = unordered_set<T>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

const int MXN = 1e5;
const ll INF = 1e18;
ll pows[MXN+1];

void solve() {
	ll n, k;
	cin >> n >> k;
	
	if(n == 1){
		cout << (k == 1 ? 1 : -1) << endl;
		return;
	}
	
	if(k > pows[n]*2){
		cout << -1 << endl;
		return;
	}
	
	k--;
	
	vector<bool> bin(n);
	bin[n] = 0; // last value has to be "lowest"
	int p = 0;
	while(k > 0){
		if(k < pows[n-p]){
			bin[p] = 0;
		}else{
			k -= pows[n-p];
			bin[p] = 1;
		}
		p++;
	}
	
	int lowest = 1;
	
	vector<int> ans(n);
	int up = 0;
	for(int i = 0; i < n; i++){
		if(!bin[i]){
			// lowest
			ans[i] = lowest++;
			for(int j = i; j-- > up;){
				ans[j] = lowest++;
			}
			up = i+1;
		}
	}
	
	/*
	for(int j = n; j-- > up;){
		ans[j] = lowest++;
	}*/
	
	for(int x: ans)
		cout << x << " ";
	cout << endl;
}	

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	
	pows[1] = pows[2] = 1;
	for(int i = 3; i <= MXN; i++){
		pows[i] = min(INF, 2*pows[i-1]);
	}
	
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}