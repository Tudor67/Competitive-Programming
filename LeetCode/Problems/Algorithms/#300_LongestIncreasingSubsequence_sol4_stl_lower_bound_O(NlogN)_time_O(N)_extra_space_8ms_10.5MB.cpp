class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for(int num: nums){
            vector<int>::iterator it = lower_bound(v.begin(), v.end(), num);
            if(it == v.end()){
                v.push_back(num);
            }else{
                *it = num;
            }
        }
        return (int)v.size();
    }
};