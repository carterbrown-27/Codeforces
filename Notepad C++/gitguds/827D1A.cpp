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
	
	int n;
	cin >> n;
	
	umap<string, int> mp;
	vector<string> strs;
	vector<vector<int>> x(n);
	
	size_t len = 0;
	for(int i = 0; i < n; i++){
		string t;
		cin >> t;
		
		int p = i;
		if(mp.find(t) != mp.end()){
			p = mp[t];
		}else{
			strs.pb(t);
			mp[t] = i;
		}
		
		int k;
		cin >> k;
		for(int j = 0; j < k; j++){
			int v;
			cin >> v;
			v--;
			x[p].pb(v);
			len = max(len, v + t.length());
		}
	}
	
	sort(strs.begin(), strs.end(),
		[](string a, string b) {
			return a.length() > b.length();
		}
	);
	
	set<int> unvis;
	for(int i = 0; i < len; i++)
		unvis.insert(unvis.end(), i);
	
	string ans(len, '?');
	for(string t: strs){
		int p = mp[t];
		
		for(int tmp: x[p]){
			int cur = tmp;
			// cout << t << " ";
			while(true){
				// cout << cur << " ";
				auto it = unvis.lower_bound(cur);
				if(it == unvis.end() || *it >= tmp+t.length()) break;
				int b = *it;
				
				for(int j = b; j < tmp+t.length(); j++){
					if(ans[j] != '?'){
						cur = j;
						break;
					}
					ans[j] = t[j-tmp];
					unvis.erase(j);
				}
			}
			// cout << endl;
		}
	}
	
	for(int i = 0; i < len; i++)
		if(ans[i] == '?')
			ans[i] = 'a';
		
	cout << ans << endl;
	return 0;
}