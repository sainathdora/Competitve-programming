#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl "\n";
typedef vector<string> vs;
typedef vector<char> vc;
using namespace std;

int Largest_Subarray_of_Sum_k(vi arr, int k){
    int maxi = INT_MIN;
    vi::iterator i = arr.begin(), j = arr.begin();
    int sum{0};
    while(j!=arr.end()){
        sum += *j;
        if(sum>k){
            while(sum>k){
                sum -= *i;
                i++;
            }
        }
        else if(sum==k){
            int size = (j-i+1);
            maxi = std::max(maxi,size);
        }
        j++;
    }
    return maxi;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    vi arr{4, 1, 1, 1, 2, 3, 5};
    cout<<Largest_Subarray_of_Sum_k(arr, 5);
    // --sainath dora
}
