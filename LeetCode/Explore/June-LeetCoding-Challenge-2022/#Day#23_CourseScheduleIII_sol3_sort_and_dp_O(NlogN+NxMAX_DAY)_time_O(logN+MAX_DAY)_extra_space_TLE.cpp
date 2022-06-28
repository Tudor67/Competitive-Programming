class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
             [](const vector<int>& LHS, const vector<int>& RHS){
                 int lhsLastDay = LHS[1];
                 int rhsLastDay = RHS[1];
                 return (lhsLastDay < rhsLastDay);
             });
        
        // maxCourses[x]: max number of taken courses
        //                when we finish the last course in the xth day
        int maxDay = courses.back()[1];
        vector<int> maxCourses(maxDay + 1);
        for(const vector<int>& COURSE: courses){
            int duration = COURSE[0];
            int lastDay = COURSE[1];
            for(int day = lastDay; day >= duration; --day){
                maxCourses[day] = max(maxCourses[day], maxCourses[day - duration] + 1);
            }
        }
        
        return *max_element(maxCourses.begin(), maxCourses.end());
    }
};