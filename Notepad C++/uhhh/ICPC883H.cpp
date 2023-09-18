#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

#define pb push_back

string make_palindrome(int n, queue<char>& evens, queue<char>& odds){
	string ans(n, '_');
	if(!odds.empty()){
		ans[n/2] = odds.front();
		odds.pop();
	}
		
	for(int i = 0; i < n/2; i++){
		ans[i] = ans[n-1-i] = evens.front();
		evens.pop();
	}
	return ans;
}

void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	umap<char, int> frq;
	for(char c: s)
		++frq[c];
	
	queue<char> evens; // each here represent a pair
	queue<char> odds;
	
	for(auto &p: frq){
		auto& [c, x] = p;
		if(x%2 == 1){
			odds.push(c);
			x--;
		}
		for(int i = 0; i < x; i+=2)
			evens.push(c);
	}
	
	// 0 if even, 1 if odd
	if(odds.size() == n%2){
		cout << 1 << endl;
		cout << make_palindrome(n, evens, odds) << endl;
		return;
	}
	
	// odds.size() will evenetually equal n if no divisors are possible
	while(!evens.empty() && (odds.empty() || n % odds.size() != 0 || n/odds.size() % 2 == 0)){
		auto c = evens.front();
		evens.pop();
		for(int i = 0; i < 2; i++)
			odds.push(c);
	}
	
	// guaranteed non-zero
	int part_size = n/odds.size();
	int parts = odds.size();
	cout << parts << endl;
	for(int i = 0; i < parts; i++){
		cout << make_palindrome(part_size, evens, odds) << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}