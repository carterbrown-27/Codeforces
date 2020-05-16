#include <stdio.h>
#include <array>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

void solve() {
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	
	int c[n]{0};
	int m = 0;
	int used[11];
	memset(used, -1, sizeof(used));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 11; j++){
			if(a[i]%primes[j] == 0){
				if(used[j] == -1) used[j] = ++m;
				c[i] = used[j];
				break;
			}
		}
	}
	
	cout << m << endl;
	for(int i: c){
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}