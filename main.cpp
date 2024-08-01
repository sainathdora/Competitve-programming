#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl "\n"
using ll = long long;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef vector<char> vc;
using namespace std;

int Longest_Substring(string s, int k){
    string::iterator i = s.begin(), j = s.begin();
    map<char, int>mp;
    int maxi = INT_MIN;
    while(j != s.end()){
        mp[*j]++;
        if(mp.size()>k){
            mp[*i]--;
            if(mp[*i]==0)mp.erase(*i);
            i++;
        }else if(mp.size()==k){
            int length_of_sub = j-i+1;
            maxi = std::max(maxi, length_of_sub);
        }
        j++;
    }
    return maxi;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s = "aabacbebebe";
    cout<<Longest_Substring(s, 3);
    return 0;
}
