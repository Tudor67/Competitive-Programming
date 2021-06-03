class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        /* 
          - Solution:
                     > solve k knapsack problems (with subsetSum = totalSum / k) using classical dp;
                     > make sure that each element is used in a single subset and the subsetSums are equal;
          - Complexity:
                     > Time: O(KNS), where N = nums.size() and S = sum of all nums;
                     > Space: O(N+S)
          - The proposed solution is not complete;
          - It can return false instead of true (but this doesn't happen very often);
          - A testcase where this solution may fail:
              > Input: nums = [10,10,10,7,7,7,7,7,7,6,6,6]
                       k = 3
              > Expected output: true
              
              > Expected: the nums can be partitioned in the following way:
                Subset1: {10, 7, 7, 6} -> sum1 = 30
                Subset2: {10, 7, 7, 6} -> sum2 = 30
                Subset3: {10, 7, 7, 6} -> sum3 = 30
                So, the expected answer is true (the nums can be partitioned into 3 subsets of equal sum);
              
              > The proposed solution fails because it builds Subset1 with valid sum1 = 30
                using vital elements for Subset1 and Subset2:
                Subset1: {10, 10, 10} -> sum1 = 30
                Subset2: {?} -> sum1 != 30
                Subset3: {?} -> sum1 != 30
              
                To avoid wrong answers for this type of testcases, the proposed algorithm runs
                on 5 random_shuffled versions on nums vector. In this way, we try to share vital elements
                to all subsets.
              
                In other words, the proposed solution is sensitive to the order of elements and
                we try to handle this by applying the dp solution on 5 random_shuffled nums.
        */
        const int N = nums.size();
        const int TOTAL_SUM = accumulate(nums.begin(), nums.end(), 0);
        const int EXPECTED_SUBSET_SUM = TOTAL_SUM / k;
        
        srand(time(NULL));
        
        for(int shuffleCount = 0; shuffleCount < 5; ++shuffleCount){
            int validSubsetsCount = 0;
            vector<bool> used(N, false);
            vector<bool> isPossible(EXPECTED_SUBSET_SUM + 1);
            vector<int> indices(EXPECTED_SUBSET_SUM + 1);

            for(int subsetIdx = 1; subsetIdx <= k; ++subsetIdx){
                fill(isPossible.begin(), isPossible.end(), false);
                fill(indices.begin(), indices.end(), -1);
                isPossible[0] = true;

                for(int i = 0; !isPossible[EXPECTED_SUBSET_SUM] && i < N; ++i){
                    if(!used[i]){
                        for(int j = EXPECTED_SUBSET_SUM; j >= nums[i]; --j){
                            if(!isPossible[j] && isPossible[j - nums[i]]){
                                isPossible[j] = true;
                                indices[j] = i;
                            }
                        }
                    }
                }

                if(isPossible[EXPECTED_SUBSET_SUM]){
                    validSubsetsCount += 1;
                    int subsetSum = EXPECTED_SUBSET_SUM;
                    while(subsetSum > 0){
                        int idx = indices[subsetSum];
                        used[idx] = true;
                        subsetSum -= nums[idx];
                    }
                }else{
                    break;
                }
            }

            int usedNumsCount = accumulate(used.begin(), used.end(), 0);
            if(validSubsetsCount == k && usedNumsCount == N){
                return true;
            }
            
            random_shuffle(nums.begin(), nums.end());
        }
        
        return false;
    }
};