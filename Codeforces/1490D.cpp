/**
 *   author: winky
 *   created: 2023-05-29 23:24:59
**/

#include                    <bits/stdc++.h>
using namespace             std;
#define tri(a, b, c)        ((a) ? (b) : (c))
#define pb(x)               push_back(x)
#define fi                  first
#define se                  second
#define debug(x)            cerr<<"+Debug for "<<(#x)<<" : "<<x<<"\n";
#define endl                cout<<"\n";
//#define int               long long
typedef pair<int, int>      ii;
typedef long long           ll;
const int maxN =            3e5;
const int mod =             1e9 + 7;
const int inf =             INT_MAX;
const double PI =           3.14159265358979;
const auto INP_FILE =       "sample.inp";
const auto OUT_FILE =       "sample.out";
void IO(short choice){      if (choice == 1) freopen(INP_FILE, "r", stdin);
else                        if (choice == 2){freopen(INP_FILE, "r", stdin); freopen(OUT_FILE, "w", stdout);}
else                        if (choice == 3) ios::sync_with_stdio(false);cin.tie(nullptr);}
/*----- ----- ----- ----- ----- ----- ----- ----- ----- -----*/

vector<int> v(maxN), t(maxN);

void dfs(int l, int r, int timeD){
    //if (l == r) return;
    int val = 0, pos = 0;
    for (int i=l; i<=r; i++){
        if (v[i] > val){
            val = v[i];
            pos = i;
        }
    }
    t[pos] = timeD;
    //cout << v[pos] << " ";
    if (pos - 1 >= l) dfs(l, pos - 1, timeD+1);
    if (pos + 1 <= r) dfs(pos + 1, r, timeD+1);
}

signed main(){
    IO(3);//1 for INP, 2 for INP and OUT, 3 for stdio
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        for (int i=1; i<=n; i++){
            cin >> v[i];
        }
        dfs(1, n, 0);
        for (int i=1; i<=n; i++) cout << t[i] << " ";
        endl;
    }
}