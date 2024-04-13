#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
#define endl "\n";
typedef vector<string> vs;
typedef vector<char> vc;

int BS(vi arr, int sum, int k){
	std::sort(arr.begin(), arr.end());
	int l = 0;
	int h = arr.size()-1;
	while(l<=h){
		cout<<"while\n";
		int mid = (l+h)/2;
		if(arr[mid]+k == sum){
			return mid;
		}else if(arr[mid]+k > sum){
			h = mid - 1;
		}else{
			l = mid+1;
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	vi arr{2, 4, 5, 7, 	11, 15};
	cout<<BS(arr, 17, 3);
	
	return 0;
}