class Solution {
private:
    bool isPossible(vector<int>& nums, vector<int>& changeIndices, const int LIMIT){
        const int N = nums.size();
        const int C = changeIndices.size();

        if(N > LIMIT + 1){
            return false;
        }

        priority_queue<pair<int, int>> maxHeap;
        vector<bool> seen(N, false);
        vector<int> delta(LIMIT + 1);
        vector<bool> marked(N, false);

        for(int j = 0; j <= LIMIT; ++j){
            int i = changeIndices[j] - 1;
            if(!seen[i] && nums[i] >= 1){
                seen[i] = true;
                maxHeap.push({nums[i], j});
            }
        }

        while(!maxHeap.empty()){
            int j = maxHeap.top().second;
            int i = changeIndices[j] - 1;
            maxHeap.pop();

            delta[j] += 2;

            bool ok = true;
            int need = 1;
            for(int k = 0; k <= LIMIT && ok; ++k){
                need = max(0, need - 1);
                need += delta[k];
                if(need > LIMIT - k + 1){
                    ok = false;
                }
            }

            if(ok){
                marked[i] = true;
            }else{
                delta[j] -= 2;
            }
        }

        long long neededOps = 0;
        for(int i = 0; i < N; ++i){
            if(!marked[i]){
                neededOps += nums[i];
                neededOps += 1;
            }
        }

        int availableOps = 0;
        int need = 1;
        for(int k = 0; k <= LIMIT; ++k){
            need = max(0, need - 1);
            need += delta[k];
            availableOps += (int)(need == 0);
        }
        
        return (neededOps <= availableOps);
    }

public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        const int N = nums.size();
        const int C = changeIndices.size();

        int l = 0;
        int r = C;
        while(l != r){
            int mid = (l + r) / 2;
            if(isPossible(nums, changeIndices, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        if(r < C){
            return r + 1;
        }

        return -1;
    }
};