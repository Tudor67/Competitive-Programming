class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        const int N = nums.size();

        int lessCount = 0;
        int equalCount = 0;
        int greaterCount = 0;
        for(int num: nums){
            if(num < pivot){
                lessCount += 1;
            }else if(num == pivot){
                equalCount += 1;
            }else{
                greaterCount += 1;
            }
        }

        int lessIndex = 0;
        int equalIndex = lessCount;
        int greaterIndex = lessCount + equalCount;

        vector<int> res(N);
        for(int num: nums){
            if(num < pivot){
                res[lessIndex] = num;
                lessIndex += 1;
            }else if(num == pivot){
                res[equalIndex] = num;
                equalIndex += 1;
            }else{
                res[greaterIndex] = num;
                greaterIndex += 1;
            }
        }
        
        return res;
    }
};