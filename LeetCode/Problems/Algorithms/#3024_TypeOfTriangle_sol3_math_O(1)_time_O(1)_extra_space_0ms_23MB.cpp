class Solution {
public:
    string triangleType(vector<int>& nums) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        if(sortedNums[0] + sortedNums[1] <= sortedNums[2]){
            return "none";
        }

        if(sortedNums[0] == sortedNums[2]){
            return "equilateral";
        }

        if(sortedNums[0] == sortedNums[1] || sortedNums[1] == sortedNums[2]){
            return "isosceles";
        }

        return "scalene";
    }
};