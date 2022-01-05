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
	int n[3];
	for(int i = 0; i < 3; i++)
		cin >> n[i];
	
	string s;
	
	if(n[0] > 0){
		if(n[2] > 0)
			n[1]--;
		n[0]++;
	}else if(n[2] == 0){
		n[1]++;
	}
	
	for(int i = 0; i < n[0]; i++)
		s+='0';
	
	if(n[2] > 0)
		n[2]++;
	
	for(int i = 0; i < n[2]; i++)
		s+='1';
	
	for(int i = 0; i < n[1]; i++){
		s += '0' + ((i%2 == 0) == (n[2] == 0));
	}

	
	cout << s << endl;
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