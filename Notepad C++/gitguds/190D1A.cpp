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

bool solve() {
	int a,b;
	cin >> a >> b;
	
	int x = 0, y = 0;
	string s;
	cin >> s;
	
	vector<pair<int,int>> ps;
	ps.pb({x,y});
	for(char c: s){
		switch(c)
		{
			case 'U':
				y++;
				break;
			case 'D':
				y--;
				break;
			case 'L':
				x--;
				break;
			case 'R':
				x++;
				break;
		}
		ps.pb({x,y});
	}
	
	int mx = min(abs(x == 0 ? b : a/x), abs(y == 0 ? a : b/y));
	int ar = a - (mx*x), br = b - (mx*y);

	for(auto p: ps){
		int px = p.first, py = p.second;
		int tmx = min(abs(x == 0 ? py : px/x), abs(y == 0 ? px : py/y));
		
		if(ar == (px - (tmx*x)) && br == (py - (tmx*y))){
			return true;
		}
	}
	
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	
	cout << (solve() ? "Yes" : "No") << endl;
	
	return 0;
}