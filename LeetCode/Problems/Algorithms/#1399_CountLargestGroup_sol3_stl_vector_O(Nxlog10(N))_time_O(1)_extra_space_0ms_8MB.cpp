class Solution {
public:
    int countLargestGroup(int n) {
        const int MAX_DIGITS_SUM = 9 * 4;
        
        int maxGroupSize = 0;
        int maxGroupCount = 0;

        vector<int> groupSizeOf(MAX_DIGITS_SUM + 1);
        for(int num = 1; num <= n; ++num){
            int digitsSum = 0;
            for(int x = num; x > 0; x /= 10){
                digitsSum += (x % 10);
            }

            groupSizeOf[digitsSum] += 1;
            
            if(maxGroupSize < groupSizeOf[digitsSum]){
                maxGroupSize = groupSizeOf[digitsSum];
                maxGroupCount = 1;
            }else if(maxGroupSize == groupSizeOf[digitsSum]){
                maxGroupCount += 1;
            }
        }

        return maxGroupCount;
    }
};