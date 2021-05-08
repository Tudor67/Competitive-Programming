class Solution {
private:
    static bool incLastDayComp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[1] < RHS[1]);
    }
    
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        const int N = courses.size();
        
        sort(courses.begin(), courses.end(), incLastDayComp);
        
        int takenCourses = 0;
        int totalTime = 0;
        priority_queue<int> maxHeap;
        for(int i = 0; i < N; ++i){
            int duration = courses[i][0];
            int lastDay = courses[i][1];
            
            if(totalTime + duration <= lastDay){
                takenCourses += 1;
                totalTime += duration;
                maxHeap.push(duration);
            }else{
                totalTime += duration;
                maxHeap.push(duration);
                totalTime -= maxHeap.top();
                maxHeap.pop();
            }
        }
        
        return takenCourses;
    }
};