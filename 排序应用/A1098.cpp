#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> init_seq;
vector<int> sorted_seq;
int n;
void perDown(vector<int>& seq,int pos,int n){
    //合法的pos一定是非叶子j点
    while(2*pos<=n){
        pos = 2*pos;
        if(pos+1<=n && seq[pos+1]>seq[pos]){ //if has right child
            pos++;
        }
        if(seq[pos]<=seq[pos/2]){
            break;
        }
        swap(seq[pos],seq[pos/2]);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        init_seq.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        sorted_seq.push_back(tmp);
    }
    vector<int> copy1(init_seq),copy2(init_seq);
    int flag = -1;
    for(int i=2;i<n;i++){
        sort(copy1.begin(),copy1.begin()+i);
        if(copy1==sorted_seq){
            sort(copy1.begin(),copy1.begin()+i+1);
            flag = 0;
            break;
        }
    }
    if(flag!=0){
        copy2.insert(copy2.begin(),0);
        sorted_seq.insert(sorted_seq.begin(),0);
        for(int i=n/2;i>=1;i--){
            perDown(copy2,i,n);
        }
        for(int i=n;i>1;i--){
            swap(copy2[i],copy2[1]);
            perDown(copy2, 1, i-1);
            if(copy2 == sorted_seq){
                flag = 1;
                i--;
                swap(copy2[i],copy2[1]);
                perDown(copy2, 1, i-1);
                break;
            }
        }
    }
    if(flag == 0) {
        printf("Insertion Sort\n");
        for(int i=0;i<n;i++){
            printf("%d",copy1[i]);
            if(i<n-1) printf(" ");
        } 
    }
    else {
        printf("Heap Sort\n");
        for(int i=1;i<=n;i++){
            printf("%d",copy2[i]);
            if(i<n) printf(" ");
        } 
    } 
    return 0;
}