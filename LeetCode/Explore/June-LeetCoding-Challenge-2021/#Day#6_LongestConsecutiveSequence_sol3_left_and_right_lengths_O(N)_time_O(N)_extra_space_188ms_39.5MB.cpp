class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> l;
        unordered_map<int, int> r;
        // After processing first i elements (i.e., at step i, only for nums[i]):
        // l[nums[i]]: length of the longest consecutive sequence x[j], x[j] + 1, ... , x[nums[i]]
        // r[nums[i]]: length of the longest consecutive sequence x[nums[i]], x[nums[i]] + 1, ... , x[k]
        // Length of the longest consecutive sequence after processing all elements of nums:
        // maxLength = max(l[nums[i]] + r[nums[i]] - 1, maxLength), for all i in [0 .. nums.size() - 1]
        int maxLength = 0;
        for(int num: nums){
            if(!l.count(num)){
                l[num] = 1 + (l.count(num - 1) ? l[num - 1] : 0);
                r[num] = 1 + (r.count(num + 1) ? r[num + 1] : 0);
                int curLength = l[num] + r[num] - 1;
                r[num - l[num] + 1] = curLength;
                l[num + r[num] - 1] = curLength;
                maxLength = max(curLength, maxLength);
            }
        }
        return maxLength;
    }
};