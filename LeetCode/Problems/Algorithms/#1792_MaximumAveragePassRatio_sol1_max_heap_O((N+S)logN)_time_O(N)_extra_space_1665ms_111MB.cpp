class Solution {
private:
    static double getContrib(double pass, double total){
        return (pass + 1) / (total + 1) - pass / total;
    }
    
public:
    double maxAverageRatio(vector<vector<int>>& initialClasses, int extraStudents) {
        const int N = initialClasses.size();
        
        vector<vector<int>> classes = initialClasses;
        priority_queue<pair<double, int>> maxHeap;
        for(int i = 0; i < N; ++i){
            maxHeap.emplace(getContrib(classes[i][0], classes[i][1]), i);
        }
        
        for(int step = 1; step <= extraStudents; ++step){
            int i = maxHeap.top().second;
            maxHeap.pop();
            
            classes[i][0] += 1;
            classes[i][1] += 1;
            
            maxHeap.emplace(getContrib(classes[i][0], classes[i][1]), i);
        }
        
        double passRatioSum = 0;
        for(int i = 0; i < N; ++i){
            passRatioSum += (double)classes[i][0] / (double)classes[i][1];
        }
        
        return passRatioSum / N;
    }
};