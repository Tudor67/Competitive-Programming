class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        const int N = nums.size();

        unordered_map<int, int> count;
        for(int num: nums){
            count[num] += 1;
        }

        vector<int> res;
        for(const pair<int, int>& P: count){
            int num = P.first;
            int numCount = P.second;
            if(numCount > N / 3){
                res.push_back(num);
            }
        }

        return res;
    }
};