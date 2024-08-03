#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl "\n"
using ll = long long;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef vector<char> vc;
using namespace std;

void solve(string &s, string::iterator start, vs &op){
    if(start+1==s.end()){
        op.push_back(s);
        return;
    }
    string::iterator i = start;
    for(i; i != s.end(); i++){
        // swap start with i
        iter_swap(start, i);
        solve(s, start+1, op);
        iter_swap(start, i);

    }
}

vs permute(string s){
    vs op;
    string::iterator start = s.begin();
    string::iterator i = s.begin();
    map<char, int>mp;
    for(i; i != s.end(); i++){
        // swap start with i
        if(mp.find(*i)==mp.end()){
            mp[*i]++;
            iter_swap(start, i);
            solve(s, start+1, op);
            iter_swap(start, i);
        }

    }
    return op; 
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    for(auto i:permute("abc"))cout<<i<<endl;
    return 0;
}
