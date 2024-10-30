class Solution {
private:
    long long getRangeSum(vector<long long>& prefSum, int l, int r){
        if(l > r || r < 0 || l >= (int)prefSum.size()){
            return 0;
        }
        l = max(l, 0);
        r = min(r, (int)prefSum.size() - 1);
        if(l == 0){
            return prefSum[r];
        }
        return prefSum[r] - prefSum[l - 1];
    }

public:
    long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
        const long long N = nums.size();
        const long long INF = 1e18;

        vector<long long> prefOnes(N);
        vector<long long> prefDist(N);
        prefOnes[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefOnes[i] = prefOnes[i - 1] + nums[i];
            prefDist[i] = prefDist[i - 1];
            if(nums[i] == 1){
                prefDist[i] += i;
            }
        }
        
        long long res = INF;
        for(int aliceIndex = 0; aliceIndex < N; ++aliceIndex){
            int have = 0;
            long long cost = 0;
            
            // Step 0: take as much as you can from the range [aliceIndex - 2, aliceIndex + 2]
            for(int i: {aliceIndex, aliceIndex - 1, aliceIndex + 1, aliceIndex - 2, aliceIndex + 2}){
                if(0 <= i && i < N){
                    if(have < k && nums[i] == 1){
                        have += 1;
                        cost += abs(aliceIndex - i);
                    }
                }
            }
            
            // Step 1: take as much as you can using at most maxChanges operations of type 1
            //                                           and maxChanges operations of type 2
            int take = min(maxChanges, k - have);
            have += take;
            cost += 2 * take;

            if(have == k){
                res = min(res, cost);
                continue;
            }

            // Step 2: take (k - have) ones using min operations of type 2
            //         from the range [0, aliceIndex - 3] and [aliceIndex + 3, N - 1]
            //         binary search the min radius around aliceIndex to collect those (k - have) ones
            long long l = 3;
            long long r = max(l, N);
            while(l != r){
                long long mid = (l + r) / 2;
                if(have + getRangeSum(prefOnes, aliceIndex - mid, aliceIndex - 3) +
                          getRangeSum(prefOnes, aliceIndex + 3, aliceIndex + mid) < k){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }
            
            long long extraOnes = getRangeSum(prefOnes, aliceIndex - r, aliceIndex - 3) +
                                  getRangeSum(prefOnes, aliceIndex + 3, aliceIndex + r);
            long long extraCost = getRangeSum(prefDist, aliceIndex + 3, aliceIndex + r) -
                                  getRangeSum(prefOnes, aliceIndex + 3, aliceIndex + r) * aliceIndex +
                                  getRangeSum(prefOnes, aliceIndex - r, aliceIndex - 3) * aliceIndex -
                                  getRangeSum(prefDist, aliceIndex - r, aliceIndex - 3);

            have += extraOnes;
            cost += extraCost;
            
            if(have > k){
                have -= 1;
                cost -= r;
            }

            res = min(res, cost);
        }

        return res;
    }
};