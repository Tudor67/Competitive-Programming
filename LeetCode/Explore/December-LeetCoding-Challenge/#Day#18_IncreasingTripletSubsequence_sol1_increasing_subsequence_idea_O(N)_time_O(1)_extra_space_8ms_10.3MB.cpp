class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> a;
        for(int num: nums){
            int idx = 0;
            while(idx < min(3, (int)a.size()) && a[idx] < num){
                idx += 1;
            }
            if(idx == a.size()){
                a.resize(idx + 1);
            }
            a[idx] = num;
            if(a.size() == 3){
                return true;
            }
        }
        return false;
    }
};