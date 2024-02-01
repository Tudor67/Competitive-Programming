class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        const int N = hours.size();
        
        int res = 0;
        for(int h: hours){
            if(h >= target){
                res += 1;
            }
        }
        
        return res;
    }
};