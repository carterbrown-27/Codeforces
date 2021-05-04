#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

/*
	DP would be easy here, I wanted to try doing it with combinatorics
*/

double fact(int n){
	if(n>20){
		cerr << "TOO BIG" << endl;
		return -1;
	} 
	double res = 1;
	for(int i = 1; i <= n; i++){
		res *= i;
	}
	return res;
}

void solve() {
	string a, b;
	cin >> a >> b;
	
	int d = 0;
	for(int i = 0; i < a.length(); i++){
		d += (a[i] == '+' ? 1 : -1);
	}
	
	int q = 0;
	for(int i = 0; i < b.length(); i++){
		if(b[i] == '?'){
			q++;
		}else{
			d += (b[i] == '+' ? -1 : 1);
		}
	}
	
	if(abs(d) > q){
		cout << 0 << endl;
		return;
	}
	
	int k = abs(d) + (q-abs(d))/2;
	// cout << d << " " << q << " " << k << endl;
	double c = fact(q) / (fact(q-k)*fact(k));
	// cout << c << endl;
	cout << setprecision(9) << c / (1 << q) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}