class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        const int N = nums.size();

        vector<int> nums1 = {nums[0]};
        vector<int> nums2 = {nums[1]};

        for(int i = 2; i < N; ++i){
            if(nums1.back() > nums2.back()){
                nums1.push_back(nums[i]);
            }else{
                nums2.push_back(nums[i]);
            }
        }

        vector<int> res;
        res.reserve(N);

        copy(nums1.begin(), nums1.end(), back_inserter(res));
        copy(nums2.begin(), nums2.end(), back_inserter(res));

        return res;
    }
};