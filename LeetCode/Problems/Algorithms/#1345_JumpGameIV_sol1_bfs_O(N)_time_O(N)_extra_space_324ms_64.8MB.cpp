class Solution {
public:
    int minJumps(vector<int>& arr) {
        const int N = arr.size();
        
        unordered_map<int, vector<int>> positionsOf;
        for(int i = 0; i < N; ++i){
            positionsOf[arr[i]].push_back(i);
        }
        
        vector<int> minSteps(N, INT_MAX);
        unordered_set<int> visitedValues;
        queue<int> q;
        minSteps[0] = 0;
        q.push(0);
        
        while(!q.empty()){
            int pos = q.front();
            q.pop();
            
            if(!visitedValues.count(arr[pos])){
                for(int nextPos: positionsOf[arr[pos]]){
                    if(1 + minSteps[pos] < minSteps[nextPos]){
                        minSteps[nextPos] = 1 + minSteps[pos];
                        q.push(nextPos);
                    }
                }
                visitedValues.insert(arr[pos]);
            }
            
            for(int nextPos: {pos - 1, pos + 1}){
                if(0 <= nextPos && nextPos < N && 1 + minSteps[pos] < minSteps[nextPos]){
                    minSteps[nextPos] = 1 + minSteps[pos];
                    q.push(nextPos);
                }
            }
        }
        
        return minSteps[N - 1];
    }
};