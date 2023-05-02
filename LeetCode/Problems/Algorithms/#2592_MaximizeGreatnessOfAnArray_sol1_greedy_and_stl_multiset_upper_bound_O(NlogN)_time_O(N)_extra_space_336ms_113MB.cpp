class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        const int N = nums.size();
        
        int res = 0;
        multiset<int> numsMultiset(nums.begin(), nums.end());
        for(int num: nums){
            multiset<int>::iterator it = numsMultiset.upper_bound(num);
            if(it != numsMultiset.end()){
                numsMultiset.erase(it);
                res += 1;
            }
        }

        return res;
    }
};