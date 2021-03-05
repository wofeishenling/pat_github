#include<stdio.h>
#include<vector>

using namespace std;
int CBT[1010];
int n;
vector<vector<int>> total_path;
vector<int> path;
void traversal(int root){
    if(root>n) return;
    path.push_back(CBT[root]);
    if(2*root>n){
        total_path.push_back(path);
    }
    traversal(2*root+1);
    traversal(2*root);
    path.pop_back();
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&CBT[i]);
    } 
    traversal(1);
    int isMaxHeap = 1;
    for(int i=0;i<total_path.size();i++){
        for(int j=1;j<total_path[i].size();j++){
            if(total_path[i][j]>total_path[i][j-1]){
                isMaxHeap = 0;
                break;
            }
        }
        if(!isMaxHeap) break;
    }
    int isMinHeap = 1;
    if(!isMaxHeap){
        for(int i=0;i<total_path.size();i++){
             for(int j=1;j<total_path[i].size();j++){
                if(total_path[i][j]<total_path[i][j-1]){
                isMinHeap = 0;
                break;
            }
        }
        if(!isMinHeap) break;
        } 
    }
    for(int i=0;i<total_path.size();i++){
        for(int j=0;j<total_path[i].size();j++){
            printf("%d",total_path[i][j]);
            if(j<total_path[i].size()-1) printf(" ");
        }
        printf("\n");
    } 
    if(isMaxHeap) printf("Max Heap");
    else if(isMinHeap) printf("Min Heap");
    else printf("Not Heap");
    return 0;
}