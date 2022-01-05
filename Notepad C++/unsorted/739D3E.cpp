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
	string t;
	cin >> t;
	
	uset<char> seen;
	vector<char> order;
	
	int i = n-1;
	while(i >= 0)
	{
		char last = t[i];
		order.pb(last);
		seen.insert(last);
		
		for(int j = i; j-- > 0 && seen.find(t[j]) != seen.end();)
		{
			
		}
		
		i = j; // new character here
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