class Solution {
private:
    double contrib(double pass, double total){
        return (pass + 1) / (total + 1) - pass / total;
    }

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<tuple<double, int, int>> maxHeap;
        for(const vector<int>& C: classes){
            int pass = C[0];
            int total = C[1];
            maxHeap.push({contrib(pass, total), pass, total});
        }

        while(extraStudents >= 1){
            int pass = get<1>(maxHeap.top());
            int total = get<2>(maxHeap.top());
            maxHeap.pop();

            maxHeap.push({contrib(pass + 1, total + 1), pass + 1, total + 1});

            extraStudents -= 1;
        }

        double passRatioSum = 0;
        while(!maxHeap.empty()){
            double pass = get<1>(maxHeap.top());
            double total = get<2>(maxHeap.top());
            maxHeap.pop();
            passRatioSum += pass / total;
        }

        return passRatioSum / (int)classes.size();
    }
};