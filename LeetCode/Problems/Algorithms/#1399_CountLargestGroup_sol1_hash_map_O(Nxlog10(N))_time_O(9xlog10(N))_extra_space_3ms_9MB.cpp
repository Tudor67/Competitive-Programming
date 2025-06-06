class Solution {
public:
    int countLargestGroup(int n) {
        int maxGroupSize = 0;
        unordered_map<int, int> groupSizeOf;
        for(int num = 1; num <= n; ++num){
            int digitsSum = 0;
            for(int x = num; x > 0; x /= 10){
                digitsSum += (x % 10);
            }
            groupSizeOf[digitsSum] += 1;
            maxGroupSize = max(maxGroupSize, groupSizeOf[digitsSum]);
        }

        int maxGroupCount = 0;
        for(auto& [_, groupSize]: groupSizeOf){
            if(maxGroupSize == groupSize){
                maxGroupCount += 1;
            }
        }

        return maxGroupCount;
    }
};