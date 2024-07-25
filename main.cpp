#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl "\n";
typedef vector<string> vs;
typedef vector<char> vc;
using namespace std;

void permu(string input, string op, vector<string>&vs){
    if(input.size()==0){
        vs.push_back(op);
        return;
    }
    // recursive case
    unordered_set<char>mp;
    for(int i(0); i<input.size(); ++i){
        if(mp.find(input[i])==mp.end()){
            mp.insert(input[i]);
            string newIP = input.substr(0, i)+input.substr(i+1);
            string newout = op + input[i];
            permu(newIP, newout, vs);
        }
    }
    
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    vector<string>vs;
    permu("abc", "", vs);
    for(auto i:vs)cout<<i<<endl;
    return 0;
    // --sainath dora
}
