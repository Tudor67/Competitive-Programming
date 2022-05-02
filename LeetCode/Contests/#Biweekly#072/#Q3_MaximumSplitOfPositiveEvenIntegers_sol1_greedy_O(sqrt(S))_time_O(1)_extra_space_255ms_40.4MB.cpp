class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum % 2 == 1){
            return {};
        }
        
        vector<long long> res;
        long long x = 2;
        while(x < finalSum / 2){
            res.push_back(x);
            finalSum -= x;
            x += 2;
        }
        
        res.push_back(finalSum);
        
        return res;
    }
};