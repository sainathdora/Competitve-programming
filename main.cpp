#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl "\n";
typedef vector<string> vs;
typedef vector<char> vc;
 
int KadaneAlgo(vi arr){
    int m{arr[0]}, s{0};
    for(int i(0); i<arr.size(); i++){
        s += arr[i];
        m = std::max(s, m);
        if(s<0)s=0;
    }
    return m;
}

int main()
{
    vi a{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout<<KadaneAlgo(a);
    return 0;
}

