```c++
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int cnt=0;
        for(int e:pushed){
            s.push(e);
            while(!s.empty()&&cnt!=popped.size()&&s.top()==popped[cnt]){
                cnt++;
                s.pop();
            }
        }
        return s.empty();
    }
};
```
