class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<array<double, 3>> maxHeap;
        for(vector<int>& c: classes){
            double pass = c[0];
            double total = c[1];
            maxHeap.push({(pass + 1) / (total + 1) - (pass / total), pass, total});
        }

        for(int i = 1; i <= extraStudents; ++i){
            double pass = maxHeap.top()[1];
            double total = maxHeap.top()[2];
            maxHeap.pop();

            pass += 1;
            total += 1;

            maxHeap.push({(pass + 1) / (total + 1) - (pass / total), pass, total});
        }
        
        double passRatioSum = 0;
        while(!maxHeap.empty()){
            double pass = maxHeap.top()[1];
            double total = maxHeap.top()[2];
            maxHeap.pop();

            passRatioSum += (pass / total);
        }

        return passRatioSum / classes.size();
    }
};