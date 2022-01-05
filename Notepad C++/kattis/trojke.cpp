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

#define .pb .push_back
#define .ins .insert

bool isLine(point a, point b, point c){
	// checks if the cross product of (c-a) and (b-a) is 0
	return (c.x - a.x) * (b.y - a.y) - (c.y - a.y) * (b.x - a.x) == 0;
}

int main() {
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	vector<point> pts; // at most 26
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < n; j++){
			if(s[j] != '.')
				pts.pb({i,j});
		}
	}
	
	int ans = 0;
	for(int i = 0; i < pts.size(); i++)
		for(int j = i+1; j < pts.size(); j++)
			for(int k = j+1; k < pts.size(); k++)
				ans += isLine(pts[i], pts[j], pts[k]);
	
	cout << ans << endl;
	return 0;
}