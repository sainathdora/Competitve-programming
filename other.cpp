#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

void solve(int n){
    int no_of_groups = 0;
    vector<bitset<31>> og;
    vector<int> inputs;
    while(n--) {
        int t;
        cin >> t;
        inputs.push_back(t);
    }
    for(int &i : inputs) {
        og.push_back(bitset<31>(i));
    }
    bool flag = true;
    while(flag) {
        for(int i = 0; i < og.size(); i++) {
            for(int j = i + 1; j < og.size(); j++) {
                if(og[i] == ~og[j]){
                    ++no_of_groups;
                    og.erase(og.begin() + i);
                    og.erase(og.begin() + j - 1); 
                    break;
                }
            }
        }
        if(og.size() == 1 || og.empty()) {
            if(og.size() == 1) {
                no_of_groups++;
            }
            flag = false;
        }
    }
    cout << no_of_groups << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int a;
    cin >> a; 
    while(a--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}
