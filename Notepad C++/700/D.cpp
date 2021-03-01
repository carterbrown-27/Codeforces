#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	
	int segs = 0;
	int a = -1, b = -1;
	
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	
	for(int i = 0; i < n; i++){
		int v = arr[i];
		
		if(i+1 < n && arr[i] != b && arr[i+1] == b){
			b = v;
			segs++;
		}else if(v != a){
			a = v;
			segs++;
		}else if(v != b){
			b = v;
			segs++;
		}
		// otherwise nothing changes
	}
	
	cout << segs << endl;
}

int main() {
	solve();
	return 0;
}