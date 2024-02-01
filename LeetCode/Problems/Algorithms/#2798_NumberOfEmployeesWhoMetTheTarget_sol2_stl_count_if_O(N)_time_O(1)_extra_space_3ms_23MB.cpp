class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        return count_if(hours.begin(), hours.end(),
                        [&](int h){
                            return (h >= target);
                        });
    }
};