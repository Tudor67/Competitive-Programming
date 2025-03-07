class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        const int N = nums.size();

        vector<int> res;
        res.reserve(N);

        for(int num: nums){
            if(num < pivot){
                res.push_back(num);
            }
        }

        for(int num: nums){
            if(num == pivot){
                res.push_back(num);
            }
        }

        for(int num: nums){
            if(num > pivot){
                res.push_back(num);
            }
        }
        
        return res;
    }
};