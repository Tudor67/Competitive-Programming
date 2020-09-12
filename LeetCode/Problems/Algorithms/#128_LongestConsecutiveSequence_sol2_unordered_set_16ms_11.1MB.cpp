class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nums_set;
        for(int num: nums){
            nums_set.insert(num);
        }
        
        int answer = 0;
        for(int num: nums_set){
            if(INT_MIN == num || !nums_set.count(num - 1)){
                int seq_size = 1;
                while(num <= INT_MAX - 1 && nums_set.count(num + 1)){
                    num += 1;
                    seq_size += 1;
                }
                answer = max(seq_size, answer);
            }
        }
        
        return answer;
    }
};