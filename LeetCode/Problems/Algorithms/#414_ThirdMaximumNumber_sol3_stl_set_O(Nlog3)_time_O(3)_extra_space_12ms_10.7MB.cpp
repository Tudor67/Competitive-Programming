class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> set3;
        for(int num: nums){
            set3.insert(num);
            if((int)set3.size() > 3){
                set3.erase(set3.begin());
            }
        }
        
        if((int)set3.size() < 3){
            return *prev(set3.end());
        }
        
        return *set3.begin();
    }
};