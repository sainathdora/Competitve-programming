#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl "\n"
using ll = long long;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef vector<char> vc;
using namespace std;

void solve(string &s, string &ans, int k, string::iterator start){
    string::iterator i = start+1;
    if(k==0 || i == s.end()){
        return;
    }
    char max = *(std::max_element(i, s.end()));
    bool flag = false;
    for(; i != s.end(); i++){
        if(*i==max && *i>*start){
            flag = true;
            std::iter_swap(i, start);
            if(ans<s)ans=s;
            solve(s, ans, k-1, start+1);
            std::iter_swap(i, start);
        }
    }
    if(!flag){
        solve(s, ans, k, start+1);
    }
}

string find_largest_Num_k_swaps(string s, int k){
    string ans = s;
    string::iterator start  = s.begin();
    solve(s, ans, k, start);
    return ans;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cout<<find_largest_Num_k_swaps("721", 5);
    return 0;
}
