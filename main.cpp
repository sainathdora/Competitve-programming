#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl "\n";
typedef vector<string> vs;
typedef vector<char> vc;
using namespace std;

int find_anagrams(string s, string ptrn){
    int k = ptrn.size();
    map<char, int>mp;
    for(char &i:ptrn){
        mp[i]++;
    }
    string::iterator i = s.begin();
    string::iterator j = s.begin();
    int count =mp.size();
    int ans{0};
    while(j != s.end()){
        if(j-i+1<k){
            // see if j exists in map then rm 1 from mp
            if(mp.find(*j) != mp.end()){
                mp[*j]--;
                if(mp[*j]==0)count--;
            }
            j++;
        }else if(j-i+1==k){
             if(mp.find(*j) != mp.end()){
                mp[*j]--;
                if(mp[*j]==0)count--;
            }
            // check if any ony of the keys are zero
            if(count==0)ans++;

            if(mp.find(*i)!=mp.end()){
                mp[*i]++;
                if(mp[*i]>0)count++;
            }
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cout<<find_anagrams("aabaabaa", "aaba");
    // --sainath dora
}
