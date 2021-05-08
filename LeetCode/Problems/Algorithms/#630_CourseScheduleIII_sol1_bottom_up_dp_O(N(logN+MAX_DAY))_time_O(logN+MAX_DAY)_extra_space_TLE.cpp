class Solution {
private:
    static bool incLastDayComp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[1] < RHS[1]);
    }
    
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), incLastDayComp);
        
        const int MAX_DAY = courses.back()[1];
        const int N = courses.size();
        
        vector<int> dp(MAX_DAY + 1, 0);
        for(int i = 0; i < N; ++i){
            int duration = courses[i][0];
            int lastDay = courses[i][1];
            // dp[x]: max number of courses we can take from courses[0..i],
            //        with the last course finished on the xth day
            for(int day = lastDay; day >= duration; --day){
                dp[day] = max(1 + dp[day - duration], dp[day]);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};