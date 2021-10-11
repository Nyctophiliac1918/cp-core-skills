class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>m;
        for(char t:tasks)
            m[t]++;
        priority_queue<int>pq;
        for(auto t:m) {
            pq.push(t.second);
        }
        int res=0;
        while(!pq.empty()) {
            vector<int>v;
            for(int i=0;i<n+1;i++) {
                if(!pq.empty()) {
                    v.push_back(pq.top()-1);
                    pq.pop();
                }
            }
            for(auto f:v) {
                if(f) pq.push(f);
            }
            res += pq.empty() ? v.size() : n+1;
        }
        return res;
    }
};
