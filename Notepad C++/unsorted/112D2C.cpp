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
	int c = 0, j = 0, m = 1;
	for(int i = 0; i < n; i++){
		if(s[i] == '1')
			c++;
		if(c >= k){
			if(c > k)
				m = 1;
			
			for(; j < i && c >= k; j++){
				if(c == k)
					m++;
				if(s[j] == '1'){
					if(c == k){
						m--;
						break;
					}else{
						c--;
					}
				}
			}
			
			if(c == k){
				ans += m;
			}else{
				// 1 at i
				j++;
				c--;
			}
		}
		// cout << m << endl;
	}
	
	cout << ans << endl;
	return 0;
}