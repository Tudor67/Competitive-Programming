class Solution {
public:
    string triangleType(vector<int>& nums) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        if(sortedNums[0] + sortedNums[1] <= sortedNums[2]){
            return "none";
        }

        int distinctLengths = unique(sortedNums.begin(), sortedNums.end()) - sortedNums.begin();

        if(distinctLengths == 1){
            return "equilateral";
        }

        if(distinctLengths == 2){
            return "isosceles";
        }

        return "scalene";
    }
};