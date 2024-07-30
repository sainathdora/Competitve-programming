#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl "\n";
typedef vector<string> vs;
typedef vector<char> vc;
using namespace std;

vi find_max_in_subarray(vi arr, int k){
    vi::iterator i = arr.begin();
    vi::iterator j = arr.begin();
    vi ans;
    deque<int>dq;
    dq.push_back(INT_MIN);
    while(j!=arr.end()){
        if(j-i+1<k){
            if(*j<dq.back())dq.push_back(*j);
            else{
                while(dq.size() >0 && dq.back()<*j){
                    dq.pop_back();
                }
                dq.push_back(*j);
            }
            j++;
        }else if(j-i+1==k){
            if(*j<dq.back()){
                dq.push_back(*j);
            }
            else{
                while(dq.size() >0 && dq.back()<*j){
                    dq.pop_back();
                }
                dq.push_back(*j);
            }
            ans.push_back(dq.front());
            if(dq.front()==*i){
                dq.pop_front();
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
    vi arr{1, 3, -1, -3, 5, 3, 6, 7};
    // vi arr{3, 1, 2, -1};
    for(auto &i:find_max_in_subarray(arr, 3)){
        cout<<i<<endl;
    }
    // --sainath dora
}
