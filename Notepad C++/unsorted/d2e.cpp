#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	vector<int> num;
	num.push_back(1);
	for(int i = 2; i <= 100; i++){
		int carry = 0;
		for(int j = 0; j < num.size(); j++){
			int v = num[j] * i + carry;
			num[j] = v%10;
			carry = v/10;
		}
		
		while(carry){
			num.push_back(carry%10);
			carry /= 10;
		}
	}
	
	int sum = 0;
	for(int i: num){
		sum += i;
	}
	cout << sum << endl;
}

int main() {
	solve();
	return 0;
}