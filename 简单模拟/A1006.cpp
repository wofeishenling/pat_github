//std::max的使用
#include<stdio.h>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

struct node{
    string ID_number;
    string Sign_in_time;
    string Sign_out_time;
};

int main(){
    vector<node> input;
    int n;
    string a,b,c;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        node temp;
        temp.ID_number = a;
        temp.Sign_in_time = b;
        temp.Sign_out_time = c;
        input.push_back(temp);
    }
    auto sign_in = min_element(input.begin(),input.end(),
                [](const node& a,const node& b)
                {return a.Sign_in_time<b.Sign_in_time;});
    auto sign_out = max_element(input.begin(),input.end(),
                [](const node& a,const node& b)
                {return a.Sign_out_time<b.Sign_out_time;});
    cout << sign_in->ID_number <<' ' << sign_out->ID_number;
    return 0;
}