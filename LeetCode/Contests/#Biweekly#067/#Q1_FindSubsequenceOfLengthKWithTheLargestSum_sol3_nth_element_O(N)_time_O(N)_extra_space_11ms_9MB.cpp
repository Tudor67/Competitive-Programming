class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        const int N = nums.size();
        
        vector<int> v = nums;
        nth_element(v.begin(), v.begin() + N - k, v.end());
        
        // we need only k elements >= splitNum
        // splitNum is the kth largest element
        int splitNum = v[N - k];
        int splitNumTargetCount = count(v.begin() + N - k, v.end(), splitNum);
        
        vector<int> subseq;
        for(int num: nums){
            if(splitNum < num || (splitNum == num && splitNumTargetCount >= 1)){
                subseq.push_back(num);
                splitNumTargetCount -= (int)(splitNum == num);
            }
        }
        
        return subseq;
    }
};