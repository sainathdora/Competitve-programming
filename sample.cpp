#include <bits/stdc++.h>
#include <ranges>
using namespace std;
typedef vector<int> vi;
#include "debugging.h"
#define endl "\n"
#define all(v) v.begin(), v.end()
using ll = long long;
typedef vector<string> vs;
typedef vector<long long> vll;
typedef vector<char> vc;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    vi arr{1, 2,212, 422};
    std::ranges::sort(arr, [](int a, int b){
        return a>b;
    });
}