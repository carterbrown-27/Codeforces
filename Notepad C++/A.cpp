#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

int solve() {
    ll n;
    cin >> n;
    if(n < 2050){
        return -1;
    }

    ll m = 1e14;

    int c = 0;
    while(n >= 2050){
        while(2050*m > n){
            m/=10;
        }

        n -= 2050*m;
        c++;
    }

    return (n > 0 ? -1 : c);
}

int main() {
	ios::sync_with_stdio(false);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cout << solve() << endl;
	}
	return 0;
}