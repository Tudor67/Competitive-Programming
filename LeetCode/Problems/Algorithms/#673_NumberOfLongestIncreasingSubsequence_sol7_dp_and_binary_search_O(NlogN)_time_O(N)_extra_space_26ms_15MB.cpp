class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        const int N = nums.size();

        // At xth iteration:
        //    dpVal[len] = {val_k, ...}
        //    dpCount[len] = {count_k, ...}
        //    dpVal[len].back() = val = min value of a lis of length len
        //    dpCount[len].back() = count = number of lis of length len and
        //                                  ending with any val from dpVal[len]
        // At each iteration we maintain dpVal and dpCount such that:
        //    1.) dpVal[0].back() < dpVal[1].back() < dpVal[2].back() < ... dpVal[maxLen].back()
        //    2.) for any len: dpVal[len][0] > dpVal[len][1] > dpVal[len][2] > ... dpVal[len].back()
        // The total number of lis is dpCount[maxLen].back()
        
        vector<vector<int>> dpVal = {{INT_MIN}};
        vector<vector<int>> dpCount = {{1}};
        for(int num: nums){
            int len = lower_bound(dpVal.begin(), dpVal.end(), num,
                                  [](const vector<int>& V, const int NUM){ return V.back() < NUM; })
                      - dpVal.begin();

            if(len == (int)dpVal.size()){
                dpVal.push_back({num});
                dpCount.push_back({0});
            }

            int idxRev = lower_bound(dpVal[len - 1].rbegin(), dpVal[len - 1].rend(), num) - dpVal[len - 1].rbegin() - 1;
            int idx = (int)dpVal[len - 1].size() - 1 - idxRev;
            int count = dpCount[len - 1].back() - (idx - 1 >= 0 ? dpCount[len - 1][idx - 1] : 0);

            if(dpVal[len].back() == num){
                dpCount[len].back() += count;
            }else{
                dpVal[len].push_back(num);
                dpCount[len].push_back(count);
                int size = dpCount[len].size();
                if(size >= 2){
                    dpCount[len].back() += dpCount[len][size - 2];
                }
            }
        }

        return dpCount.back().back();
    }
};