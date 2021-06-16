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

string foutp(int i, int j, char c){
	stringstream res;
	if(toupper(c) != 'P')
		res << (char) toupper(c);
	res << (char) ('a' + j) << i;
	return res.str();
}

int main() {
	ios::sync_with_stdio(false);
	
	const int N = 8;
	
	char board[N][N];
	for(int i = 0; i < N; i++){
		string s;
		getline(cin, s);
		getline(cin, s);
		for(int j = 0; j < N; j++){
			board[i][j] = s[(j+1)*4 - 2];
		}
	}
	
	cin.ignore(1000, '\n');
	
	
	char ord[] = {'k','q','r','b','n','p'};
	
	string ws = "White: ";
	for(char a: ord)
		for(int i = N; i-- > 0;)
			for(int j = 0; j < N; j++)
				if(board[i][j] == toupper(a))
					ws += foutp(N-i,j,board[i][j]) + ',';
	
	cout << ws.substr(0, ws.length()-1) << endl;
	
	string bs = "Black: ";
	for(char a: ord)
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				if(board[i][j] == a)
					bs += foutp(N-i,j,board[i][j]) + ',';
	
	cout << bs.substr(0, bs.length()-1) << endl;
	
	return 0;
}