#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    deque<vector<int>> matri;
    for(int i=0;i<n;i++){
        vector<int> v(2);
        for(int j=0;j<2;j++){
            cin >> v[j];
        }
        matri.push_back(v);
    }
    sort(matri.begin(),matri.end(),[](vector<int> v1,vector<int> v2){
        if(v1[0]<v2[0])return true;
        else if(v1[0]==v2[0])return v1[1]<=v2[1];
//        else if(v1[0]-v1[1]>=v2[0]-v2[1])return true;
        else return false;
    });
    vector<vector<int>> ans;
    while (!matri.empty()){
        if(matri.size()>1&&matri[0][1]==matri[1][1]&&matri[0][0]>matri[1][0]){
            int temp=matri[0][0];
            matri[0][0]=matri[1][0];
            matri[1][0]=temp;
        }
        if(matri.size() > 1 && matri[0][1] >= matri[1][0]){
            vector<int> v({matri[0][0], max(matri[1][1],matri[0][1])});
            matri.pop_front();
            matri.pop_front();
            matri.push_front(v);
        }
        else if(matri.size() >= 1){
            ans.push_back(matri.front());
            matri.pop_front();
        }
    }
    for (int k = 0; k < ans.size(); ++k) {
        cout << ans[k][0] << " " << ans[k][1] <<endl;
    }
}
/*
4
1
3
2
6
8
10
15
18
 */