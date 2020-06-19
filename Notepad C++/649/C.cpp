#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define push_back pb
#define make_pair mp

void solve() {
	int n;
	cin >> n;
	
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	const int INF = 1e6;
	int b[n];
	int MEX = 0;
	queue<int> w;
	
	for(int i = 0; i < n; i++){
		if(a[i] == MEX+1){
			b[i] = MEX++;
		}else if(a[i] > MEX){
			b[i] = MEX++;
			
			while(!w.empty()){
				if(a[i] == MEX) break;
				b[w.front()] = MEX++;
				w.pop();
			}
			
			if(a[i] != MEX){
				cout << -1 << endl;
				return;
			}
		}else{
			w.push(i);
		}
	}
	
	while(!w.empty()){
		b[w.front()] = INF;
		w.pop();
	}
	
	for(int x: b){
		cout << x << " ";
	}
	cout << endl;
}

int main() {
	solve();
	return 0;
}