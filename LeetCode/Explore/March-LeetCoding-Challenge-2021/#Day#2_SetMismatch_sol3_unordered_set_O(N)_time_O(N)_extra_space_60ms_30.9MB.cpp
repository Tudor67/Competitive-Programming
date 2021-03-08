class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int N = nums.size();
        int duplicate = -1;
        int missing = -1;
        
        unordered_set<int> values;
        for(int num: nums){
            if(values.count(num)){
                duplicate = num;
            }
            values.insert(num);
        }
        
        for(int num = 1; num <= N; ++num){
            if(!values.count(num)){
                missing = num;
            }
        }
        
        return {duplicate, missing};
    }
};