class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        const int N = arr.size();
        vector<bool> vis(N, false);
        queue<int> q;
        q.push(start);
        vis[start] = true;
        
        while(!q.empty()){
            int idx = q.front();
            q.pop();
            
            for(int nextIdx: {idx + arr[idx], idx - arr[idx]}){
                if(nextIdx >= 0 && nextIdx < N && !vis[nextIdx]){
                    q.push(nextIdx);
                    vis[nextIdx] = true;
                }
            }
        }
        
        for(int i = 0; i < N; ++i){
            if(arr[i] == 0 && vis[i]){
                return true;
            }
        }
        
        return false;
    }
};