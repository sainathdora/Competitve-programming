#include <bits/stdc++.h>
using namespace std;
typedef vector<long long> vi;
#define endl "\n";
typedef vector<string> vs;
typedef vector<char> vc;
using namespace std;

struct SegmentTree{
    vi ST;
    int n;
    void init(int _n){
        this->n = _n;
        this->ST.resize(4*n, 0);
    }
    void build(int start, int end, int node, vi &arr){
        if(start == end){
            ST[node] = arr[start];
            return ;
        }
        int mid = (start+end)/2;
        // build left -> [start, mid]
        build(start, mid, 2*node+1, arr);
        // build right -> [mid+1, end]
        build(mid+1, end, 2*node+2, arr);
        // find curr node value
        ST[node] = ST[2*node+1]+ST[2*node+2];
    }
    void build(vi &arr){
        build(0, arr.size()-1, 0, arr);
    }
    void show_St_arr(){
        for(auto &i:ST)cout<<i<<endl;
    }

    int query(int l, int r, int start, int end, int node){
        // no overlapp
        if(l>end || r<start){
            return 0;
        }
        // complete overlapp
        if(l<=start && r>=end){
            return ST[node];
        }
        // partial overlap
        int mid = (start+end)/2;
        int q1 = query(l, r, start, mid, 2*node+1);
        int q2 = query(l, r, mid+1,end, 2*node+2);
        return q1+q2;
    }
    int query(int l, int r){
        return query(l, r, 0, n-1, 0);
    }

    void update(int start, int end, int node, int index, int val){
        // base case
        if(start==end){
            ST[node]=val;
            return ;
        }
        int mid=(start+end)/2;
        // if value is to left of mid
        if(index<=mid){
            update(start, mid, 2*node+1, index, val);
        }else{
            update(mid+1, end, 2*node+2, index, val);
        }
        ST[node]=ST[2*node+1]+ST[2*node+2];
    }
    void update(int index, int value){
        update(0, n-1, 0, 2, 9);
    }    
};

int main()
{
    vi arr{2, 1, 10, 9, 3, 4, 2, 8};
    SegmentTree t1;
    t1.init(arr.size());
    t1.build(arr);
    // t1.show_St_arr();
    cout<<"query = "<<t1.query(2, 3)<<"\n";
    cout<<"update index 2 to 10\n";
    t1.update(2, 10);
    cout<<"query = "<<t1.query(2, 3);
    return 0;
}
