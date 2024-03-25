#include <bits/stdc++.h>
#include<bitset>
#include <iostream>
using namespace std;

void solve(int n){
    int no_of_groups=0;
    vector<bitset<31>>og;
    // fill the array with integers
    while(n--){
        int c;
        cin>>c;
        og.push_back(bitset<31>(c));
    }
    for(int i = 0; i<og.size(); i++){
        cout<<"i: "<<i<<endl;
        for(int j = i+1; j<=og.size(); j++){
            if(og[i]==~og[j]){    
                no_of_groups++;
                cout<<"----------Start-------\n";
                og.erase(og.begin()+i);
                og.erase(og.begin()+j);
                cout<<"popping: og["<<i<<"]"<<og[i]<<endl;
                cout<<"popping: og["<<j<<"]"<<og[j]<<endl;
                cout<<og[i]<<endl;
                cout<<og[j]<<"\n---End----"<<endl;
                // reset i = 0
                i = 0;
                j = i+1;
            }
        }
            
    }
        
    
    cout<<og.size()+no_of_groups<<endl;

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int a;
    cin>>a;
    solve(a);
    
    /* each group contains only 2 elements from og vector, by knowing how many groups we have, we can subtract all it's
     members from og vector then what ever left is the remaining individual group;
     no_of_groups = 2
     og.size()-2(no_of_groups) + no_of_groups= og.size()-no_of_groups
     */

    return 0;
}
