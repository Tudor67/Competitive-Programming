class Solution {
private:
    int reverse(int num){
        int reversedNum = 0;
        while(num > 0){
            reversedNum = reversedNum * 10 + num % 10;
            num /= 10;
        }
        return reversedNum;
    }

public:
    int minMirrorPairDistance(vector<int>& nums) {
        const int N = nums.size();

        int minDist = -1;
        unordered_map<int, int> lastIndexOf;

        for(int i = 0; i < N; ++i){
            if(lastIndexOf.contains(nums[i])){
                int currDist = i - lastIndexOf[nums[i]];
                if(minDist == -1 || minDist > currDist){
                    minDist = currDist;
                }
            }
            lastIndexOf[reverse(nums[i])] = i;
        }

        return minDist;
    }
};