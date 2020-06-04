#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n;
	cin >> n;
	
	int d = n%10;
	string s;
	
	if(d==3){
		s = "bon";
	}else if(d==0 || d==1 || d==6 || d==8){
		s = "pon"
	}else{
		s = "hon";
	}
	
	cout << s << endl;
}

int main() {
	solve();
	return 0;
}