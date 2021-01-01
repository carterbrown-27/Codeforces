#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve(){
	int d[9];
	for(int i = 0; i < 9; i++) d[i] = i+1;
	
	vector<vector<int>> p;
	do{
		p.push_back(vector<int>(begin(d),end(d)));
	}while(next_permutation(begin(d),end(d)));
	
	for(auto v: p){
		int n = 0;
		for(int i: v){
			n *= 10;
			n += i;
		}
		
		int tn = n;
		bool works = true;
		for(int i = 9; i-- > 1;){
			if(tn%(i+1) != 0){
				works = false;
				break;
			}
			tn/=10;
		}
		
		if(works){
			cout << n << endl;
			return;
		} 
	}
	
}

int main() {
	solve();
	return 0;
}