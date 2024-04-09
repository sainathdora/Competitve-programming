#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef map<int, vector<int> > G;



void DFS(G &map){
    vector<int>visited;
    stack<int>Stack;
    G::iterator itr = map.begin();
    int curr{0};
    int count  = 0;
    Stack.push(1);
    while(!Stack.empty()){
        // now explore visited and make sure the one you're exploring is not in visited so take set difference 
        if(visited.size()==0){
            curr = itr->first;
            visited.push_back(curr);
            Stack.pop();
            Stack.push(curr);
            curr = (itr->second)[0];
            continue;
        }
        // a)check if the curr exists within visited and add it if it does'nt else dont add it
        auto itr2 = std::find(visited.begin(), visited.end(), curr);
        if(itr2 == visited.end()){
            visited.push_back(curr);
        }
        // b) check if there exists one value in map[curr] that doesn't exist in visited, if so then add curr to stack and set curr
        // to the element that exists within map[curr] that doesn't exist in visited
        // if all elements in the map[curr] exists in visited, then remove top ele from stack and set curr to that top ele
        vi map_curr = map[curr];
        bool flag = false;
        for(int &i:map_curr){
            auto itr = std::find(visited.begin(), visited.end(), i);
            if(itr == visited.end()){
                Stack.push(curr);
                curr = i;
                flag=true;
                break;
            }
        }
        if(!flag){
            curr = Stack.top();
            Stack.pop();
        }
      
    }
    for(auto &i:visited)cout<<"visited: "<<i<<endl;
}



int main(){
    map<int, vector<int> >AdjList;
    AdjList[1] = vector<int>{2,3,4};
    AdjList[2] = vector<int>{1,3};
    AdjList[3] = vector<int>{1,4,5};
    AdjList[4] = vector<int>{1,3,5};
    AdjList[5] = vector<int>{4,3,6,7};
    AdjList[6] = vector<int>{5};
    AdjList[7] = vector<int>{5};
    DFS(AdjList);
    return 0;
}

// DONE BY - Sainath Dora