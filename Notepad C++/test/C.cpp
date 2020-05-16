#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

void solve() {
	string str;
	cin >> str;
	set<pair<pll,pll>> st;
	pair<ll,ll> prev(0,0);
	ll nextX, nextY;
	ll sum = 0;
	for(char c: str){
		nextX = prev.first;
		nextY = prev.second;
		if(c=='N'){
			nextY++;
		} else if(c=='S'){
			nextY--;
		} else if(c=='W'){
			nextX--;
		}else if(c=='E'){
			nextX++;
		}
		pll next(nextX,nextY);
		pair<pll,pll> edge(prev,next);
		if(st.find(edge) != st.end()){
			sum+=1;
		}else{
			sum+=5;
		}
		st.insert(edge);
		pair<pll,pll> redge(next,prev);
		st.insert(redge);
		
		prev = pll(nextX,nextY);
	}
	
	cout << sum << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}