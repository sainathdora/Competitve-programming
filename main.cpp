#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
#define endl "\n";
typedef vector<string> vs;
typedef vector<char> vc;
using namespace std;

int Max_Sub_Array_of_K(vi arr, int k){
    vi::iterator i = arr.begin();
    vi::iterator j = arr.begin();
    int sum = 0;
    int maxi = INT_MIN;
    while(j!=arr.end()){
        // if j-i +1 == k then find its sum
        sum += *j;
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            maxi = std::max(sum, maxi);
            sum -= *i;
            i++;
            j++;
        }
    }
    return maxi;
    
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    vi arr{1, 9, 3, 4};
    cout<<Max_Sub_Array_of_K(arr, 2);
    // --sainath dora
}
