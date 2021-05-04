#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll sols[500001];

void precomp(){
	sols[1] = 0;
	ll amt = 0;
	ll dist = 0;
	for(ll i = 3; i < 500000; i+=2){
		amt += 8;
		dist++;
		sols[i] = sols[i-2] + amt*(dist);
	}
}

int main() {
	precomp();
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		cout << sols[n] << endl;
	}
	return 0;
}