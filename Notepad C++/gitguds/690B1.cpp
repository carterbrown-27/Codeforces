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

bool works(){
	int n;
	cin >> n;
	
	int a[n][n];
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(int j = 0; j < n; j++)
			a[i][j] = s[j] - '0';
	}
		
	set<pair<int,int>> fours;
	int fi, fj;
	fi = fj = -1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] == 4){
				if(fi == -1){
					fi = i;
					fj = j;
				}
				fours.insert({i,j});
			}
		}
	}
	
	if(fi == -1){
		return false;
	}
	
	// cout << fi << " " << fj << endl;
	
	int db;
	for(db = fi; db < n && a[db][fj] == 4; db++);
	db--;
	
	int rb;
	for(rb = fj; rb < n && a[fi][rb] == 4; rb++);
	rb--;
	
	// cout << db << " " << rb << endl;
	
	// all 4s must be in rectangle
	for(int i = fi; i <= db; i++)
		for(int j = fj; j <= rb; j++)
			if(a[i][j] != 4){
				return false;
			}else{
				fours.erase({i,j});
			}
	
	if(!fours.empty()){
		return false;
	}	
				// check adjacents
				
	
	// check rest
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			// determine value
			int val = 0;
			for(int ci = max(0, i-1); ci <= min(n-1, i+1); ci++)
				for(int cj = max(0, j-1); cj <= min(n-1, j+1); cj++)
					// should be 1 if diag, 2 if shares side
					if(a[ci][cj] == 4)
						val = max(val, 3-(abs(ci-i)+abs(cj-j)));
			
			if(a[i][j] != 4 && a[i][j] !=  val){
				// cout << i << " " << j << " " << a[i][j] << " " << val << endl;
				return false;
			}
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cout << (works() ? "Yes" : "No") << endl;
	return 0;
}