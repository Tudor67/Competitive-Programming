class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> count;
        for(int num1: nums1){
            for(int num2: nums2){
                count[num1 + num2] += 1;
            }
        }
        
        int answer = 0;
        for(int num3: nums3){
            for(int num4: nums4){
                int sum34 = num3 + num4;
                int sum12 = -sum34;
                if(count.count(sum12)){
                    answer += count[sum12];
                }
            }
        }
        
        return answer;
    }
};