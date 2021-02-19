//map+vector+string
#include<map>
#include<vector>
#include<string>
#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
    map<string,vector<int>> name_courses_map;
    int num_query,num_course;
    scanf("%d%d",&num_query,&num_course);
    int course,num_stu;
    char name[10];
    for(int i=0;i<num_course;i++){
        scanf("%d%d",&course,&num_stu);
        for(int j=0;j<num_stu;j++){
            scanf("%s",name);
            string temp(name);
            name_courses_map[name].push_back(course);
        }
    }
    for(auto &e:name_courses_map){
        sort(e.second.begin(),e.second.end());
    }
    vector<string> query_list;
    for(int i=0;i<num_query;i++){
        scanf("%s",name);
        string temp(name);
        query_list.push_back(temp);
    }
    for(auto e:query_list){
        printf("%s %llu",e.c_str(),name_courses_map[e].size());
        for(auto e:name_courses_map[e]){
            printf(" %d",e);
        }
        printf("\n");
    }
    return 0;
}