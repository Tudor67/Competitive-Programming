class Solution {
public:
    int minimumPairRemoval(vector<int>& originalNums) {
        const int N = originalNums.size();
        const long long INF = 1e15;

        vector<long long> nums(N);
        vector<int> L(N + 1);
        vector<int> R(N + 1);
        for(int i = 0; i < N; ++i){
            nums[i] = originalNums[i];
            L[i] = i - 1;
            R[i] = i + 1;
        }

        int badAdjPairs = 0;
        set<pair<long long, int>> s;
        
        auto add = [&](int i){
            if(0 <= i && R[i] < N){
                int j = R[i];
                s.insert({nums[i] + nums[j], i});
                badAdjPairs += (int)(nums[i] > nums[j]);
            }
        };

        auto remove = [&](int i){
            if(0 <= i && R[i] < N){
                int j = R[i];
                s.erase({nums[i] + nums[j], i});
                badAdjPairs -= (int)(nums[i] > nums[j]);
            }
        };

        for(int i = 0; i + 1 < N; ++i){
            add(i);
        }

        int minOps = 0;
        while(badAdjPairs > 0){
            minOps += 1;

            int i = s.begin()->second;
            int j = R[i];

            int h = L[i];
            int k = R[j];

            remove(h);
            remove(i);
            remove(j);

            nums[i] += nums[j];
            R[i] = k;
            L[k] = i;

            add(h);
            add(i);
        }

        return minOps;
    }
};