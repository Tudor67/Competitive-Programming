class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
             [](const vector<int>& LHS, const vector<int>& RHS){
                 int lhsLastDay = LHS[1];
                 int rhsLastDay = RHS[1];
                 return (lhsLastDay < rhsLastDay);
             });
        
        int currentTotalTime = 0;
        priority_queue<int> maxHeap;
        for(const vector<int>& COURSE: courses){
            int duration = COURSE[0];
            int lastDay = COURSE[1];
            if(currentTotalTime + duration <= lastDay){
                currentTotalTime += duration;
                maxHeap.push(duration);
            }else if(!maxHeap.empty() && maxHeap.top() > duration){
                currentTotalTime -= maxHeap.top();
                maxHeap.pop();
                currentTotalTime += duration;
                maxHeap.push(duration);
            }
        }
        
        return maxHeap.size();
    }
};