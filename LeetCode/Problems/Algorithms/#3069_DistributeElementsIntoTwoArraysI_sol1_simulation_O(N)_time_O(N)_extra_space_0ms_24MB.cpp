class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> arr0 = {nums[0]};
        vector<int> arr1 = {nums[1]};
        for(int i = 2; i < N; ++i){
            if(arr0.back() > arr1.back()){
                arr0.push_back(nums[i]);
            }else{
                arr1.push_back(nums[i]);
            }
        }
        
        vector<int> res;
        copy(arr0.begin(), arr0.end(), back_inserter(res));
        copy(arr1.begin(), arr1.end(), back_inserter(res));
        
        return res;
    }
};