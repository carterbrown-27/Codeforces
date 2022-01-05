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
	string s, t;
	cin >> s >> t;
	
	vector<int> cnt(26);
	for(char c : s)
		cnt[c-'a']++;
		
	if(t == "abc" && cnt[0] > 0){
		while(cnt[0]-- > 0) cout << 'a';
		while(cnt[2]-- > 0) cout << 'c';
		while(cnt[1]-- > 0) cout << 'b';
	}
	
	for(int i = 0; i < cnt.size(); i++){
		for(int j = 0; j < cnt[i]; j++){
			cout << (char)('a'+i);
		}
	}
	cout << endl;
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