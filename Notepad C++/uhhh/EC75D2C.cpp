#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point {
	int x,y;
};

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

template<typename T>
using uset = unordered_set<T>;

#define pb push_back

void solve() {
    string s; 
    cin >> s;
    
    int n = s.length();
    
    queue<int> ev;
    queue<int> od;
    
    for(int i = 0; i < n; i++){
        int x = s[i] - '0';
        if(x%2){
            od.push(x);
        }else{
            ev.push(x);
        }
    }
    
    string ans(n, ' ');
    
    for(int i = 0; i < n; i++){
        if(!ev.empty() && (od.empty() || ev.front() <= od.front())){
            ans[i] = ev.front() + '0';
            ev.pop();
        }else{
            ans[i] = od.front() + '0';
            od.pop();
        }
    }

    cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}