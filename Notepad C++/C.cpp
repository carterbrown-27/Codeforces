#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n,x,y;
	cin >> n >> x >> y;
	
	int d = y-x;
	for(int i = 1; i <= 50; i++){
		if(d%i != 0) continue;
		
		vector<int> ans;
		int c = n;
		
		// go up to y from x
		bool reached = false;
		int v = x;
		while(c > 0){
			ans.push_back(v);
			c--;
			if(v == y){
				reached = true;
				break;
			}
			v += i;
		}
		
		// go down from x to 0
		v = x;
		while(c > 0 && v-i > 0){
			v -= i;
			ans.push_back(v);
			c--;
		}
		
		v = y;
		while(c > 0){
			v += i;
			ans.push_back(v);
			c--;
		}
		
		if(reached && c == 0){
			for(int a: ans){
				cout << a << " ";
			}
			cout << endl;
			return;
		}
	}
	
	cout << "end" << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}