class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> vis;
        
        for(int num: nums){
            if(vis.count(num)){
                return num;
            }
            vis.insert(num);
        }

        return -1;
    }
};