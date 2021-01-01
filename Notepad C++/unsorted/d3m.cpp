#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	// Brute Force, should do generative solution instead of filtrative
	
	set<int> p;
	for(int i = 1; i < 1e6; i++){
		string s = to_string(i);
		bool isP = true;
		for(int k = 0; k < s.length()/2; k++){
			if(s[k] != s[s.length()-k-1]){
				isP = false;
				break;
			}
		}
		if(isP) p.insert(i);
	}
	
	long sum = 0;
	for(int i: p){
		vector<int> n;
		int v = i;
		while(v > 0){
			n.push_back(v%2);
			v/=2;
		}
		
		bool isP = true;
		for(int k = 0; k < n.size()/2; k++){
			if(n[k] != n[n.size()-k-1]){
				isP = false;
				break;
			}
		}
		
		if(isP) sum += i;
	}
	
	cout << sum << endl;
}

int main() {
	solve();
	return 0;
}