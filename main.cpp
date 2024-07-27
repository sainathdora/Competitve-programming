#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl "\n";
typedef vector<string> vs;
typedef vector<char> vc;
using namespace std;

void Negative_Num_of_Every_Window_Size_k(vi arr, int k){
    vi::iterator i = arr.begin();
    vi::iterator j = arr.begin();
    vi ans;
    deque<int>dq;
    while(j!=arr.end()){
        // if j-i +1 == k then find its sum
        if(*j<0)dq.push_back(*j);
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            if(dq.size()==0){
                ans.push_back(0);
            }
            else{
                ans.push_back(dq.front());
                if(*i == dq.front()){
                    dq.pop_front();
                }
            }
            i++;
            j++;
        }
    }
    for(int &k:ans)cout<<k<<" \n";
    
    
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    vi arr{12, -1, -7, 8, -15, 30, 15, 28};
    Negative_Num_of_Every_Window_Size_k(arr, 3);
    // --sainath dora
}
