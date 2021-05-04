#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	string s;
	cin >> s;
	
	bool one = false;
	int p = 0;
	
	for(int i = 0; i < s.length(); i++){
		if(!one){
			one = (s[i] == '1');
		}else if(s[i] == '0'){
			p = i;
			break;
		}
	}
	
	cout << s.substr(0,p) << s.substr(p+1) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}