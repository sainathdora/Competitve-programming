#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl "\n";
typedef vector<string> vs;
typedef vector<char> vc;
using namespace std;
void find_sub(vc &s, int i, int j, vc &output){
    // base
    if(s[i]=='0'){
        output[j]='0';
        for(auto &i:output)cout<<i<<" ";
        cout<<"\n";
        return;
    }
    // left, include j
    output[j] = s[i];
    find_sub(s, i+1, j+1, output);
    // right
    find_sub(s, i+1, j, output);
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    vc input{'a', 'b', 'c', '0'};
    vc op(input.size()+1, '0');
    find_sub(input, 0, 0, op);
    return 0;
}
