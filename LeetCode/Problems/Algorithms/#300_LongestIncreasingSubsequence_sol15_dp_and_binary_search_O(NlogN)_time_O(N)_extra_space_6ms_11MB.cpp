class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int N = nums.size();

        // v[i]: min value of the last element of a LIS of length (i + 1)
        vector<int> v;
        for(int num: nums){
            int j = lower_bound(v.begin(), v.end(), num) - v.begin();
            if(j == (int)v.size()){
                v.push_back(num);
            }else{
                v[j] = num;
            }
        }

        return v.size();
    }
};