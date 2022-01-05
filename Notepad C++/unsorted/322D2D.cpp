#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

struct point {
	point(int x, int y, char c) : x(x), y(y), c(c)
	{}
	int x,y;
	char c;
};

#define pb push_back

void solve()
{
	vector<point> rects;
	int A = 0;
	for(int i = 0; i < 3; i++){
		int x,y;
		cin >> x >> y;
		if(x > y)
			swap(x, y);
		
		A += x*y;
		rects.pb(point(x,y,'A'+i));
	}
	
	sort(rects.begin(), rects.end(), [] (point& a, point& b) {
		return a.y > b.y;
	});
	
	int s = sqrt(A);
	if(s*s != A || rects[0].y > s){
		cout << -1 << endl;
		return;
	}
	
	char b[s][s];
	
	for(int i = 0; i < rects[0].x; i++)
		for(int j = 0; j < rects[0].y; j++)
			b[i][j] = rects[0].c;
	
	if(rects[0].y != s){
		cout << -1 << endl;
		return;
	}
	int r = s - rects[0].x;
	
	if(rects[1].y == r){
		// go "down"
		swap(rects[1].x, rects[1].y);
	}else if(!(rects[1].y == s || rects[1].x == r)){
		cout << -1 << endl;
		return;
	}

	for(int i = rects[0].x; i < rects[0].x + rects[1].x; i++)
		for(int j = 0; j < rects[1].y; j++)
			b[i][j] = rects[1].c;
	
	int cx = rects[0].x, cy = rects[1].y;
	if(cy == s){
		cy = 0;
		cx += rects[1].x;
	}
	if(cy > cx)
		swap(rects[2].x, rects[2].y);
	
	// don't think we need both
	if(cy + rects[2].y != s || cx + rects[2].x != s){
		cout << -1 << endl;
		return;
	}
	
	for(int i = cx; i < s; i++)
		for(int j = cy; j < s; j++)
			b[i][j] = rects[2].c;
	
	cout << s << endl;
	for(int i = 0; i < s; i++){
		for(int j = 0; j < s; j++)
			cout << b[i][j];
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}