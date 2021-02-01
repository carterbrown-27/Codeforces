#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back

void genMatches(string s, int pos, set<string> &res){
	if(pos < s.length()) genMatches(s, pos+1, res);
	
	for(string t: res){
		res.insert("_" + t);
		res.insert(s[pos] + t);
	}
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	
	map<string,int> p;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		p[s] = i;
	}
	
	vector<string> s(m);
	vector<int> mt(m);
	for(int i = 0; i < m; i++){
		cin >> s[i];
		cin >> mt[i];
	}
	
	vector<vector<pair<int,int>>> mp(n);
	// each string can generate patterns it matches
	for(int i = 0; i < m; i++){
		string t = s[i];
		set<string> matches;
		genMatches(t,0, matches);
		for(string r: matches){
			if(p.find(r) != p.end()){
				// if pattern matches
				auto pair = make_pair(mt[i], i);
				mp[p[r]].pb(pair);
			}
		}
	}
	
	vector<int> ans;
	bool used[n];
	memset(used, false, sizeof used);
	
	for(int i = 0; i < n; i++){
		sort(mp[i].begin(), mp[i].end());
		bool flag = false;
		for(int j = 0; j < mp[i].size(); j++){
			int v = mp[i][j].second;
			if(!used[v]){
				flag = true;
				used[v] = true;
				ans.push_back(v);
				break;
			} 
		}
		
		if(!flag){
			cout << "NO" << endl;
			return;
		}
	}
	
	cout << "YES" << endl;
	for(int x: ans){
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	solve();
	return 0;
}