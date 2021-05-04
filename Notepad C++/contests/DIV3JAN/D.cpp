#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	
	priority_queue<int> a;
	priority_queue<int> b;
	
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		if(v%2 == 0){
			a.push(v);
		}else{
			b.push(v);
		}
	}
	
	ll at = 0, bt = 0;
	while(!(a.empty() && b.empty())){
		// alice
		if(!a.empty() && (b.empty() || a.top() > b.top())){
			at += a.top();
			a.pop();
		}else if(!b.empty()){
			b.pop();
		}
		
		
		// bob
		if(!b.empty() && (a.empty() || b.top() > a.top())){
			bt += b.top();
			b.pop();
		}else if(!a.empty()){
			a.pop();
		}
		
		// cout << at << " " << bt << endl;
		// cout << a.size() << " " << b.size() << endl;
	}
	
	if(at > bt){
		cout << "Alice\n";
	}else if(bt > at){
		cout << "Bob\n";
	}else{
		cout << "Tie\n";
	}
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}