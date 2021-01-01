#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	vector<string> v(100);
	for(int i = 0; i < 100; i++){
		cin >> v[i];
	}
	
	vector<int> ans;
	int carry = 0;
	for(int i = 50; i-- > 0;){
		int sum = carry;
		for(int j = 0; j < 100; j++){
			sum += (v[j][i] - '0');
		}
		carry = (sum/10);
		if(i <= 9) ans.push_back(sum%10);
	}
	
	while(carry > 0){
		ans.push_back(carry%10);
		carry /= 10;
	}
	
	reverse(ans.begin(), ans.end());
	
	while(ans.size() > 10){
		ans.pop_back();
	}
	
	for(int i: ans){
		cout << i << " ";
	}
	cout << endl;
	
	// 5537376230
}

int main() {
	solve();
	return 0;
}