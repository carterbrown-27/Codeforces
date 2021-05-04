#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

void solve() {
	int n, k;
	cin >> n >> k;
	
	char lim = 'a'+k-1;
	char cur = 'a';
	string s = "";
	while(s.length() < n){
		s += cur;
		for(char inn = cur+1; inn <= lim; inn++){
			s += cur;
			s += inn;
		}
		cur++;
		if(cur > lim) break;
	}
	
	while(s.length() < n) s += s;
	
	cout << s.substr(0, n) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}