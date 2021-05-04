#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define pb push_back
#define mp make_pair

void solve() {
	int n;
	scanf("%d", &n);
	
	const int MAX = 1e6;
	int l = 1, r = n;
	
	int known[n+1];
	memset(known, 0, sizeof known);
	
	while(l < r){
		int m = (l+r)/2;
		
		int flm, fm, frm;
		flm = fm = frm = MAX;
		
		if(known[m] != 0){
			fm = known[m];
		}else{
			printf("? %d\n", m);
			fflush(stdout);
			scanf("%d", &fm);
			known[m] = fm;
		}
		
		
		if(m > 1){
			if(known[m-1] != 0){
				flm = known[m-1];
			}else{
				printf("? %d\n", m-1);
				fflush(stdout);
				scanf("%d", &flm);
				known[m-1] = flm;
			}
		}
		
		if(m < n){
			if(known[m+1] != 0){
				frm = known[m+1];
			}else{
				printf("? %d\n", m+1);
				fflush(stdout);
				scanf("%d", &frm);
				known[m+1] = frm;
			}
		}
		
		if(fm < min(flm, frm)){
			l = m;
			break;
		}else if(flm <= frm){
			r = m-1;
		}else{
			l = m+1;
		}
	}
	
	printf("! %d\n", l);
	fflush(stdout);
}

int main() {
	solve();
	return 0;
}