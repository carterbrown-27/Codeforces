#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

/*
 * Start with an n*n board of empty ("0") cells. There are cannons placed before the first position of each row and column.
 * Cannonballs can be shot from these cannons as such:
 * 		A cannonball ("1") will move along the row/column, landing before whichever comes first:
 *			a) The end of the row/column
 *			b) Another cannnonball
 *	Given a board filled with 1's and 0's, determine if this board state can exist.			
 */
void solve() {
	int n;
	cin >> n;
	string board[n];
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		board[i] = s;
	}
	
	bool works = true;
	for(int y = 0; y < n; y++){
		for(int x = 0; x < n; x++){
			if(board[y][x] == '1'){
				if(y==n-1 || board[y+1][x] == '1'){
					continue;
				}else if(x==n-1 || board[y][x+1] == '1'){
					continue;
				}else{
					works = false;
					break;
				}
			}
		}
	}
	
	cout << (works ? "YES" : "NO") << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}