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
	int n, k;
	cin >> n >> k;
	
	ll x;
	cin >> x;
	x--;
	
	string s;
	cin >> s;
	
	string ans = "";
	for(int i = n; i-- > 0;){
		if(s[i] == 'a'){
			ans += s[i];
			continue;
		}
		
		int j = i;
		for(; j > 0 && s[j-1] == '*'; j--);
		
		// get base of current number
		ll base = (i-j+1)*k + 1;
		
		// do base conversion step (modulo base, divide by base)
		int blen = x % c_i;
		x /= c_i;
		
		for(int b = 0; b < blen; b++){
			ans += 'b';
		}
		
		i = j;
	}
	reverse(ans.begin(), ans.end());
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