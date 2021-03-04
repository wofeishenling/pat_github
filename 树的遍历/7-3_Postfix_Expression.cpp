#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;
struct node{
    string data;
    int left;
    int right;
}SBT[30];
bool isRoot[30];
string ans;
void dfs(int root){
    if(root == -1) return;
    ans.push_back('(');
    dfs(SBT[root].left);
    dfs(SBT[root].right);
    ans+=SBT[root].data;
    ans += ')';
}
int main(){
    int n;
    string s;
    int l,r;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin>>s>>l>>r;
        SBT[i].left = l;
        SBT[i].right = r;
        SBT[i].data = s;
        if(l!=-1) isRoot[l] = false;
        if(r!=-1) isRoot[r] = false;
    }
    int root;
    for(int i=1;i<=n;i++){
        if(isRoot[i]){
            root = i;
            break;
        }
    } 
    dfs(root);
    cout << ans;
    return 0;
}