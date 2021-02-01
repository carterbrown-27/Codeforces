#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	cin >> n;
	set<ll> st;
	for(int i = 0; i < 2*n; i++){
		int v;
		cin >> v;
		st.insert(v);
	}
	
	if(st.size() > n){
		cout << "NO1" << endl;
		return;
	}
	
	vector<ll> v;
	ll esum = 0;
	for(ll x: st){
		esum += x;
		v.pb(x);
	} 
	
	cout << "SUM: " << esum << endl;
	sort(v.rbegin(), v.rend());
	
	if(v[0] % (2*n) != 0){
		cout << "NO2" << endl;
		return;
	}
	
	
	ll first = v[0] / (2*n);
	cout << first << " ";
	
	ll sum = first;
	
	for(int i = 1; i < n-1; i++){
		int num = v[i] - 2*sum;
		int den = 2*(n-i-1);
		if(num%den == 0){
			sum += num/den;
			cout << num/den << " ";
		}else{
			cout << num << "/" << den << " : ";
			cout << "NO" << endl;
			return;
		}
	}
	
	if((v[n-1] - 2*sum) % 2 == 0){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
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