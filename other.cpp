#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define PII pair<int, int>
#define endl "\n"
const int MAX = 1e9;
const int N = 200010;
const ll INF = 1e9+7;
 
void solve()
{
    cout<<"entering solve()\n";
     int n;
     cin>>n;
     vector<ll> v(n);
     for(auto &x:v) cin>>x;
     cout<<"done input\n";
     map<ll,ll> m;
     ll c=0;
     for(int i=0;i<n; i++){
        cout<<"i: "<<i<<endl;
        ll mm= (2147483647^v[i]);
        if(m[v[i]]==0){
            c++;
            m[mm]++;
        }
        else{
            m[v[i]]--;
        }
     }
     cout <<"this is c: "<< c<< endl;
}
 
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}