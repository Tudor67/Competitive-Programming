class Solution {
private:
    static double getContrib(double pass, double total){
        return (pass + 1) / (total + 1) - pass / total;
    }
    
public:
    double maxAverageRatio(vector<vector<int>>& initialClasses, int extraStudents) {
        const int N = initialClasses.size();
        
        vector<vector<int>> classes = initialClasses;
        
        auto comp = [&classes](const int& LHS_IDX, const int& RHS_IDX){
            double lhsContrib = getContrib(classes[LHS_IDX][0], classes[LHS_IDX][1]);
            double rhsContrib = getContrib(classes[RHS_IDX][0], classes[RHS_IDX][1]);
            return (lhsContrib < rhsContrib);
        };
        
        priority_queue<int, vector<int>, decltype(comp)> maxHeap(comp);
        for(int i = 0; i < N; ++i){
            maxHeap.push(i);
        }
        
        for(int step = 1; step <= extraStudents; ++step){
            int i = maxHeap.top();
            maxHeap.pop();
            
            classes[i][0] += 1;
            classes[i][1] += 1;
            
            maxHeap.push(i);
        }
        
        double passRatioSum = 0;
        for(int i = 0; i < N; ++i){
            passRatioSum += (double)classes[i][0] / (double)classes[i][1];
        }
        
        return passRatioSum / N;
    }
};