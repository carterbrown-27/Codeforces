#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct point {
	int x,y;
};

template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<typename T, typename U>
using umap = unordered_map<T,U,custom_hash>;

template<typename T>
using uset = unordered_set<T,custom_hash>;

#define FOR(i, l, r) for (int i = (l); (i) < (r); (i)++)
#define all(x) (x).begin(), (x).end()
#define pb push_back

void solve() {
	int n;
    cin >> n;
    
    vector<string> paths(n);
    FOR(i, 0, n){
        cin >> paths[i];
    }
    
    umap<int, umap<int, uset<char>>> adj;
    int Tx = -1, Ty = -1;
    FOR(i, 0, n){
      int x = 0, y = 0;
      string path = paths[i];
      int m = path.length();
      FOR(j, 1, m) {
        char d = path[j];
        if(d == 'T'){
            Tx = x;
            Ty = y;
        }else if(d == 'N'){
            adj[x][y].insert('N');
            y++;
        }else if(d == 'E'){
            adj[x][y].insert('E');
            x++;
        }else if(d == 'S'){
            adj[x][y].insert('S');
            y--;
        }else if(d == 'W'){
            adj[x][y].insert('W');
            x--;
        }
      }
    }
    
    // cout << Tx << " " << Ty << endl;
    
    queue<pair<pair<int,int>,string>> q;
    q.push({{0,0},"H"});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        
        const auto [cx, cy] = p.first;
        string path = p.second;
        
        if(cx == Tx && cy == Ty){
            // cout << cx << " " << cy << endl;
            cout << path << "T" << endl;
            break;
        }
        
        for(char d: adj[cx][cy]){
           string newPath = path + d;
           int nx = cx, ny = cy;
            if(d == 'N'){
                ny++;
            }else if(d == 'E'){
                nx++;
            }else if(d == 'S'){
                ny--;
            }else if(d == 'W'){
                nx--;
            }
           
           q.push({{nx,ny},newPath});
        }
    }
}

int main() {
	ios::sync_with_stdio(false);
	solve();
	return 0;
}