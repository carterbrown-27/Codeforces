#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	int n;
	cin >> n;
	vector<int> f;
	for(int i = 2; i <= sqrt(n); i++){
		if(n%i==0){
			f.push_back(i);
		}
	}
	for(int i = 0; i < f.size(); i++){
		for(int j = i+1; j < f.size(); j++){
			if(n%(f[i]*f[j]) == 0 && n/(f[i]*f[j]) != f[i] && n/(f[i]*f[j]) != f[j]){
				cout << "YES" << endl;
				printf("%d %d %d\n",f[i],f[j],n/(f[i]*f[j]));
				return;
			}
		}
	}
	cout << "NO" << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}