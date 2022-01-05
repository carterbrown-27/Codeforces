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
		
	int k;
	cin >> k;
		
	string s;
	cin >> s;
	
	int n = s.length();
	
	ll ans = 0;
	array<ll,n+1> cnt;
	cnt[0] = 1;
	
	int sum = 0;
	for(int i = 0; i < n; i++){
		sum += s[i] == '1';
		if(sum >= k) 
			ans += cnt[sum-k];
		cnt[sum]++;
	}
	
	cout << ans << endl;
	return 0;
}