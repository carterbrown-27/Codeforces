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

int main() {
	ios::sync_with_stdio(false);
	
	string key;
	getline(cin, key);
	
	char board[5][5];
	umap<char, pair<int,int>> mp;
	
	int x = 0, y = 0;
	for(char c: key){
		if(c==' ') continue;
		if(mp.find(c) == mp.end()){
			board[y][x] = c;
			mp[c] = {y,x};
			x++;
			if(x == 5){
				x = 0;
				y++;
			}
		}
	}
	
	for(char c = 'a'; c <= 'z'; c++){
		if(c=='q') continue;
		if(mp.find(c) == mp.end()){
			board[y][x] = c;
			mp[c] = {y,x};
			x++;
			if(x == 5){
				x = 0;
				y++;
			}
		}
	}
	
	string msgTmp;
	getline(cin, msgTmp);
	
	string msg;
	for(char c: msgTmp)
		if(c!=' ')
			msg += c;
	
	string ans;
	
	for(int i = 0; i < msg.length(); i+=2){
		char a = msg[i];
		char b;
		if(i+1 == msg.length() || msg[i] == msg[i+1]){
			b = 'x';
			i--;
		}else{
			b = msg[i+1];
		}
		
		auto ap = mp[a];
		auto bp = mp[b];
		
		if(ap.first == bp.first){
			// same row
			ans += board[ap.first][(ap.second+1)%5];
			ans += board[bp.first][(bp.second+1)%5];
		}else if(ap.second == bp.second){
			// same col
			ans += board[(ap.first+1)%5][ap.second];
			ans += board[(bp.first+1)%5][bp.second];
		}else{
			ans += board[ap.first][bp.second];
			ans += board[bp.first][ap.second];
		}
	}
	
	for(char c: ans)
		putchar(toupper(c));
	
	cout << endl;
	return 0;
}