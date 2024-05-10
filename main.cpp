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
        int curr{arr[i]};
        int prev{arr[i-1]};
        if((curr%2==0 && prev%2==0) || (curr%2!=0 && prev%2!=0)){
            s = curr;
        }else{
            s += curr;
            cout<<"s = "<<s<<endl;
            if(s<0){
                s = 0;
            }
            m = std::max(s, m);
            cout<<"m = "<<m<<endl;
            cout<<"curr = "<<curr<<endl;
            cout<<"----------\n";
            
        }
    }
    return m;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int tt;
    cin>>tt;
    while (tt--)
    {
        int s;
        cin>>s;
        vi arr(s);
        for(int i(0); i<s; ++i)cin>>arr[i];
        cout<<KadaneAlgo(arr)<<endl;
    }
    
    return 0;
}
