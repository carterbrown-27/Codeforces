#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	string s;
	int t = 1;
	while(true){
		cin >> s;
		if(s.compare("END")== 0) break;
		
		bool even = true;
		int gap = -1, c = 0;
		for(int i = 1; i < s.length(); i++){
			if(s[i] == '*'){
				if(gap == -1){
					gap = c;
				}else if(c != gap){
					even = false;
					break;
				}
				c = 0;
			}else{
				c++;
			}
		}
		
		cout << t << " " << (even ? "EVEN" : "NOT EVEN") << endl;
		t++;
	}
}

int main() {
	solve();
	return 0;
}