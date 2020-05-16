#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
	int a1, b1, a2, b2;
	cin >> a1 >> a2 >> b1 >> b2;
	cout << ((max(a1, a2) == max(b1, b2) && min(a1, a2) + min(b1, b2) == max(a1, a2)) ? "Yes" : "No") << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}