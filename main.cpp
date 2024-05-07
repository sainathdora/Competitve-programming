#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl "\n";
typedef vector<string> vs;
typedef vector<char> vc;
 
int KadaneAlgo(vi arr){
    int m{0}, s{0};
    for(int i(0); i<arr.size(); i++){
        if(i==0){
            m = arr[i];
            s = arr[i];
            continue;
        }
        s += arr[i];
        if(m>s){
            s = arr[i];
        }
        m = std::max(s, m);
    }
    return m;
}

int main()
{
    vi a{1, 100, 3};
    cout<<KadaneAlgo(a);
    return 0;
}

