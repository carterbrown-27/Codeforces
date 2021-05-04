#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

struct cmp {
	bool operator() (const pair<int,int>  &a, const pair<int,int>& b) const {
		int al = a.second - a.first;
		int bl = b.second - b.first;
		if(al == bl){
			return a.first < b.first;
		}else{
			return al > bl;
		}
	}
};

void solve() {
	int n;
	cin >> n;
	int a[n];
	
	set<pair<int,int>, cmp> st;
	st.insert(make_pair(0,n-1));
	
	int i = 1;
	while(!st.empty()){
		pair<int,int> c = *std::next(st.begin(),0);
		int mid = (c.first + c.second) / 2;
		a[mid] = i;
		
		if(c.first <= mid-1){
			st.insert(make_pair(c.first,mid-1));
		}
		
		if(mid+1 <= c.second){
			st.insert(make_pair(mid+1,c.second));
		}
		
		i++;
		st.erase(c);
	}
	
	for(int x: a){
		cout << x << " ";
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