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

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	// generate substrings
	vector<string> ss;
	queue<string> q;
	q.push("");
	
	while(!q.empty()){
		string t = q.front();
		q.pop();
		
		if(t.length() > 0) ss.pb(t);
		if(t.length() >= 3) continue;
		
		for(char c = 'a'; c <= 'z'; c++){
			q.push(t+c);
		}
	}
	
	for(string t: ss){
		if(s.find(t) == string::npos){
			cout << t << endl;
			break;
		}
	}
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