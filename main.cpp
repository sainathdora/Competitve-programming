#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl "\n";
typedef vector<string> vs;
typedef vector<char> vc;
using namespace std;

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

vi removeSameParity(vi arr){
    vi narr;
    for(int i(0); i<(arr.size()-1); ++i){
        if((arr[i]%2 == 0 && arr[i+1]%2 != 0) || (arr[i]%2 != 0 && arr[i+1]%2==0)){
            narr.push_back(arr[i]);
            narr.push_back(arr[i+1]);
        }
    }
    return narr;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
 
    return 0;
}
