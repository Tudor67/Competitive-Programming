class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v;
        
        for(int num: nums){
            if(num < pivot){
                v.push_back(num);
            }
        }
        
        for(int num: nums){
            if(num == pivot){
                v.push_back(num);
            }
        }
        
        for(int num: nums){
            if(num > pivot){
                v.push_back(num);
            }
        }
        
        return v;
    }
};