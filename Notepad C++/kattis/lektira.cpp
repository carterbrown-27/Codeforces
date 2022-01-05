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

int solve(string s, int l, int k){
	if(k == 0) return s.length();
	int best = l+1;
	
	for(int i = l+1; i < s.length()-k; i++){
		for(int j = best; j-- > l;){
			int ci = i+1-(best-j);
			if(s[ci] != s[j]){
				if(s[ci] < s[j])
					best = i+1;
				break;
			}
		}
	}
	return best;
}

int main() {
	ios::sync_with_stdio(false);
	
	string s;
	cin >> s;
	
	int prev = 0;
	string ans = "";
	for(int k = 3; k-- > 0;){
		int best = solve(s, prev, k);
		// cout << best << " ";
		
		string tmp = s.substr(prev, best-prev);
		reverse(tmp.begin(), tmp.end());
		ans += tmp;
		
		prev = best;
	}
	
	cout << ans << endl;
	return 0;
}