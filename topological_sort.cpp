#include<vector>
#include<queue>
using namespace std;

class Solution {
public: 
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> in(numCourses, 0);
        vector<vector<int>> E(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            in[prerequisites[i][0]]++;
            E[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> ans;
        vector<int> used(numCourses, 0);
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            used[cur] = 1;
            ans.push_back(cur);
            for(int i=0;i<E[cur].size();i++){
                in[E[cur][i]]--;
                if(in[E[cur][i]]==0) q.push(E[cur][i]);
            }

        }
        for(int i=0;i<numCourses;i++){
            if(used[i]==0){
                ans.clear();
                return ans;
            }
        }
        return ans;
    }
};