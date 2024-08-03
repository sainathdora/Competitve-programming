#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl "\n"
using ll = long long;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef vector<char> vc;
using namespace std;

int Min_window_substring(string s, string t){
    int mini = INT_MAX;
    map<char, int>mp;
    for(char &c:t)mp[c]++;
    string::iterator i = s.begin(), j=s.begin();
    int count = mp.size();
    while(j!=s.end()){
        if(mp.find(*j) != mp.end()){
            mp[*j]--;
            if(mp[*j]==0)count--;
        }
        if(count==0){
            while(mp[*i]<0){
                mp[*i]++;
                i++;
            }
            int subarraysize = j-i+1;
            mini = std::min(mini, subarraysize);
        }
        j++;
    }
    return mini;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cout<<Min_window_substring("TTTTA", "TTA");
    return 0;
}
