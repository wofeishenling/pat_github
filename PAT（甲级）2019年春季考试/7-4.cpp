#include<stdio.h>
#include<iostream>
#include<string>
#include<sstream>
#include <tuple>
#include<vector>
#include<map>
#include<queue>

using namespace std;
int N;
int post[33],in[33];
struct node{
    node* left;
    node*right;
    int val;
    node* p;
    int level;
};
map<int,node*> mp;
node* createT(node* p,int inl,int inr,int postl,int postr,int lev){
    if(inl>inr) return nullptr;
    node* root = new node();
    int val_root = post[postr];
    int pos_root = inl;
    for(int i=inl;i<=inr;i++){
        if(in[i]==val_root){
            pos_root = i;
            break;
        }
    }
    int num_left = pos_root - inl;
    root->val = val_root;
    root->p = p;
    root->level = lev;
    mp[root->val] = root;
    root->left = createT(root,inl,pos_root-1,postl,postl+num_left-1,lev+1);
    root->right= createT(root,pos_root+1,inr,postl+num_left,postr-1,lev+1);
    return root;
}
bool isCBT(node* &root){
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node* tmp = q.front();
        q.pop();
        if(tmp==nullptr) break;
        q.push(tmp->left);
        q.push(tmp->right);
    }
    while(!q.empty()){
        if(q.front()!=nullptr)return false;
        q.pop();
    }
    return true;
};
int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin>>post[i];
    for(int i=0;i<N;i++) cin>>in[i];
    node* root;
    root = createT(nullptr,0,N-1,0,N-1,0);
    int M;
    scanf("%d\n",&M);
    for(int i=0;i<M;i++){
        string input;
        getline(cin,input);
        vector<string> statement;
        stringstream ss(input);
        string tmp;
        while(ss >> tmp){
            statement.push_back(tmp);
        }        
        string rot("root"),sib("siblings"),level("level"),
        tree("tree"),par("parent"),left("left"),right("right");
        bool flag = false;
        if(statement[statement.size()-1]==rot){
            int num;
            sscanf(statement[0].c_str(),"%d",&num);
            if(mp[num]->p==nullptr) flag = true;
        }
        else if(statement[statement.size()-1]==sib){
            int num1,num2;
            sscanf(statement[0].c_str(),"%d",&num1);
            sscanf(statement[2].c_str(),"%d",&num2);
            if(mp[num1]->p!=nullptr && mp[num2]->p!=nullptr && mp[num1]->p==mp[num2]->p) flag = true;
        }
        else if(statement[statement.size()-1]==level){
            int num1,num2;
            sscanf(statement[0].c_str(),"%d",&num1);
            sscanf(statement[2].c_str(),"%d",&num2);
            if(mp[num1]->level==mp[num2]->level) flag = true;
        }
        else if(statement[statement.size()-1]==tree){
            if(isCBT(root)) flag = true;
        }
        else if(statement[3]==par){
            int A,B;
            sscanf(statement[0].c_str(),"%d",&A);
            sscanf(statement[statement.size()-1].c_str(),"%d",&B);
            if(mp[B]->p!=nullptr && mp[B]->p->val==A) flag = true;
        }
        else if(statement[3]==left){
            int A,B;
            sscanf(statement[0].c_str(),"%d",&A);
            sscanf(statement[statement.size()-1].c_str(),"%d",&B);
            if(mp[B]->left!=nullptr && mp[B]->left->val==A) flag = true;
        }
        else if(statement[3]==right){
            int A,B;
            sscanf(statement[0].c_str(),"%d",&A);
            sscanf(statement[statement.size()-1].c_str(),"%d",&B);
            if(mp[B]->right!=nullptr && mp[B]->right->val==A) flag = true;
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
