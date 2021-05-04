#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair
#define MOD 1000000007

#define MAX_CHOOSE 1000
int choose[MAX_CHOOSE+1][MAX_CHOOSE+1];

void prepChoose(){
	// generate n choose k mod m table
	choose[0][0] = 1;
	for(int i = 1; i <= MAX_CHOOSE; i++){
		choose[i][0] = choose[i][i] = 1;
		for(int j = 1; j < i; j++){
			choose[i][j] = (choose[i-1][j-1] + choose[i-1][j]) % MOD;
		}
	}
}

void solve() {
	int n, k;
	cin >> n >> k;
	
	map<int,int, greater<int>> mp;
	for(int i = 0; i < n; i++){
		int v;
		cin >> v;
		mp[v]++;
	}
	
	int j;
	for(auto const &p: mp){
		j = p.second;
		// cout << j << endl;
		if(j>=k) break;
		k-=j;
	}
	
	//cout << "J:  " << j << endl;
	//cout << "K : " << k << endl;
	
	cout << choose[j][k] << endl;
}

int main() {
	int t;
	cin >> t;
	prepChoose();
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}