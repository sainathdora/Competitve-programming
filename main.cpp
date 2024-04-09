#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
#define endl "\n";
typedef vector<string> vs;


int givedeadships(){
	int n;
	int k;
	cin>>n>>k;
	vi a(n);
	for(int i{0}; i<n; i++)cin>>a[i];
	int dead_ships = 0 ; 
	for(int i{1}; i<=k; i++){
		// use (-1) to power to identify alternative attacks;
		// if(-1)**i == -1 attack first ship else last ship
		if(pow((-1), i) == -1){
			// subtract 1 from first ele and if its zero pop it;
			a[0] -= 1;
			if(a[0]==0){
				dead_ships++;
				a.erase(a.begin());
			}
		}else{
			// subtract 1 from last ele
			a[a.size()-1] -= 1;
			if(a[a.size()-1]==0){
				dead_ships++;
				a.pop_back();
			}
		}
	}
	return dead_ships;
}
 


int main()
{
	// ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cout<<givedeadships()<<endl;
	}
	return 0;
}