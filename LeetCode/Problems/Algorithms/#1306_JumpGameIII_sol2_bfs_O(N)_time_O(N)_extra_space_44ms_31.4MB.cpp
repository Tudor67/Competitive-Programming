class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        const int N = arr.size();
        
        vector<bool> vis(N, false);
        queue<int> q;
        q.push(start);
        vis[start] = true;
        
        while(!q.empty()){
            int i = q.front();
            q.pop();
            
            if(arr[i] == 0){
                return true;
            }
            
            for(int j: {i - arr[i], i + arr[i]}){
                if(0 <= j && j < N && !vis[j]){
                    q.push(j);
                    vis[j] = true;
                }
            }
        }
        
        return false;
    }
};