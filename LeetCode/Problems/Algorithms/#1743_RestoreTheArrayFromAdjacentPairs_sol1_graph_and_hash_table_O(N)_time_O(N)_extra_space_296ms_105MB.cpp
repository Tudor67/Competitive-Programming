class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        const int N = 1 + adjacentPairs.size();

        unordered_map<int, vector<int>> neighborsOf;
        for(const vector<int>& V: adjacentPairs){
            int a = V[0];
            int b = V[1];
            neighborsOf[a].push_back(b);
            neighborsOf[b].push_back(a);
        }

        int startNum = 0;
        for(pair<const int, vector<int>>& P: neighborsOf){
            int a = P.first;
            const vector<int>& NEIGHBORS = P.second;
            if((int)NEIGHBORS.size() == 1){
                startNum = a;
            }
        }

        vector<int> nums(N);
        nums[0] = startNum;
        for(int i = 0; i + 1 < N; ++i){
            int a = nums[i];
            for(int b: neighborsOf[a]){
                if(i == 0 || nums[i - 1] != b){
                    nums[i + 1] = b;
                }
            }
        }

        return nums;
    }
};