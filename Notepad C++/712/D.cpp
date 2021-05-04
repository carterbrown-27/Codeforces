#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

template<typename T, typename U>
using umap = unordered_map<T,U>;

#define pb push_back

int main() {
	int n;
	scanf("%d", &n);

	
	// r = 2, b = 1
	int ri = 0, bi = 1;
	int rj = 0, bj = 0;
	
	for(int t = 0; t < n*n; t++){
		int a;
		scanf("%d", &a);
		int b, i, j;
		
		// cout << bi << " " << bj << endl;
		
		if(a==1){
			if(ri < n && rj < n){
				// som
				i = ri;
				j = rj;
				b = 2;
				ri+=2;
				if(ri >= n){
					rj++;
					ri = rj%2;
				}
			}else{
				i = bi;
				j = bj;
				b = 3;
				bi+=2;
				if(bi >= n){
					bj++;
					bi = (bj%2 == 0);
				}
			}
		}else if(a==2){
			if(bi < n && bj < n){
				//som
				i = bi;
				j = bj;
				b = 1;
				bi+=2;
				if(bi >= n){
					bj++;
					bi = (bj%2 == 0);
				}
			}else{
				i = ri;
				j = rj;
				b = 3;
				ri+=2;
				if(ri >= n){
					rj++;
					ri = rj%2;
				}
			}
		}else{
			if(ri < n && rj < n){
				// som
				i = ri;
				j = rj;
				b = 2;
				ri+=2;
				if(ri >= n){
					rj++;
					ri = rj%2;
				}
			} else {
				//som
				i = bi;
				j = bj;
				b = 1;
				bi+=2;
				if(bi >= n){
					bj++;
					bi = (bj%2 == 0);
				}
			}
		}
		
		printf("%d %d %d\n", b, i+1, j+1);
		fflush(stdout);
	}
	
	return 0;
}