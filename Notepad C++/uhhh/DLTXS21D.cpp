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

int getSum(int i, int j){
	i++, j++; // 1-index
	
	cout << "or " << i << " " << j << endl;
	int iorj;
	cin >> iorj;
	// assert(iorj != -1);
		
	cout << "and " << i << " " << j << endl;
	int iandj;
	cin >> iandj;
	// assert(iorj != -1);
	
	int ixorj = ~iandj & iorj;
	return ixorj + (iandj << 1);
}

int main() {
	ios::sync_with_stdio(false);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> a0_plus(n);
	// 2*n-1 ops
	for(int j = 1; j < n; j++){
		a0_plus[j] = getSum(0, j);
	}
	
	int a1_plus_a2 = getSum(1,2);
	int a1_minus_a0 = a1_plus_a2 - a0_plus[2];
	// a0+a1 - (a1-a0) = 2a0
	int a0 = (a0_plus[1] - a1_minus_a0)/2;
	
	vector<int> nums(n);
	nums[0] = a0;
	for(int i = 1; i < n; i++){
		nums[i] = a0_plus[i] - a0;
	}
	
	sort(nums.begin(), nums.end());
	
	cout << "finish " << nums[k-1] << endl;
	return 0;
}