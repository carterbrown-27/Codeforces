#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

bool isPrime(int n){
	for(int i = 2; i*i <= n; i++){
		if(n%i == 0) return false;
	}
	return true;
}

void solve() {
	int n;
	cin >> n;
	const string a = "Ashishgup";
	const string f = "FastestFinger";
	if(n == 1){
		cout << f << endl;
	}else if(n%2==1 || n == 2){
		cout << a << endl;
	}else{
		for(int i = 2; i*i <= n; i++){
			if(n%i == 0 && ((i%2==1 && isPrime(i)) || (i > 2 && (n/i)%2 == 1 && isPrime(n/i)))){
				cout << a << endl;
				return;
			}
		}
		cout << f << endl;
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