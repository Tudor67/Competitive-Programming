class Solution {
public:
    int minJumps(vector<int>& arr) {
        const int N = arr.size();
        const int INF = 1e9;

        unordered_map<int, vector<int>> indicesOf;
        for(int i = 0; i < N; ++i){
            indicesOf[arr[i]].push_back(i);
        }

        vector<int> minSteps(N, INF);
        queue<int> q;
        q.push(0);
        minSteps[0] = 0;

        while(!q.empty() && minSteps[N - 1] == INF){
            int i = q.front();
            q.pop();

            for(int j: {i - 1, i + 1}){
                if(0 <= j && j < N && minSteps[i] + 1 < minSteps[j]){
                    minSteps[j] = minSteps[i] + 1;
                    q.push(j);
                }
            }

            for(int j: indicesOf[arr[i]]){
                if(minSteps[i] + 1 < minSteps[j]){
                    minSteps[j] = minSteps[i] + 1;
                    q.push(j);
                }
            }

            indicesOf[arr[i]].clear();
        }

        return minSteps[N - 1];
    }
};