class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        const int N = nums.size();

        vector<int> v;
        for(int num: nums){
            vector<int>::iterator it = upper_bound(v.begin(), v.end(), num);
            if(it == v.end()){
                v.push_back(num);
            }else{
                *it = num;
            }
        }

        return N - (int)v.size();
    }
};