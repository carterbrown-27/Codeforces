#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	
	const int MAX = 1e9 + 1;
	pair<int,int> minStand(MAX,MAX);
	int minStandPos = -1;
	pair<int,int> minLay(MAX,MAX);
	int minLayPos = -1;
	
	int wa[n], ha[n];
	
	for(int i = 0; i < n; i++){
		int w, h;
		cin >> w >> h;
		
		int mnl = min(minLay.first, minLay.second);
		if(w < mnl || h < mnl){
			minLay.first = w;
			minLay.second = h;
			minLayPos = i+1;
		}

		if(w <= minStand.first && h <= minStand.second){
			minStand.first = w;
			minStand.second = h;
			minStandPos = i+1;
		}
		
		wa[i] = w;
		ha[i] = h;
	}
	
	for(int i = 0; i < n; i++){
		int w = wa[i], h = ha[i];
		
		if(w > minStand.first && h > minStand.second){
			cout << minStandPos << " ";
		}else if(min(w,h) > min(minLay.first, minLay.second) && max(w,h) > max(minLay.first, minLay.second)){
			cout << minLayPos << " ";
		}else{
			cout << "-1 ";
		}
	}
	cout << "\n";
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}