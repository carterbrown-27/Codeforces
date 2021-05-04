#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

bool comp(pair<int,int> p1, pair<int,int> p2){
	if(p1.first == p2.first){
		return p1.second < p2.second;
	}
	return p1.first < p2.first;
}

void solve() {
	int n;
	cin >> n;
	pair<int,int> a[n];
	for(int i = 0; i < n; i++){
		int x,y;
		cin >> x >> y;
		a[i] = make_pair(x,y);
	}
	
	sort(a, a+(sizeof(a)/sizeof(a[0])));
	int x = 0, y = 0;
	string ans = "";
	for(auto p: a){
		if(x < p.first){
			while(x<p.first){
				ans.append("R");
				x++;
			}
		}
		if(y <= p.second){
			while(y<p.second){
				ans.append("U");
				y++;
			}
		}else{
			cout << "NO" << endl;
			return;
		}
	}
	
	cout << "YES" << endl;
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}