class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double minimum = 255;
        double maximum = 0;
        double elemSum = 0;
        int elemCnt = 0;
        int mode = 0;
        for(int i = 0; i < count.size(); ++i){
            if(count[i] > 0){
                minimum = min((double)i, minimum);
                maximum = max((double)i, maximum);
                elemSum += i * count[i];
                elemCnt += count[i];
                if(count[i] > count[mode]){
                    mode = i;
                }
            }
        }
        
        double mean = elemSum / elemCnt;
        double median = 0;
        int cnt = 0;
        for(int i = 0; i < count.size(); ++i){
            cnt += count[i];
            if(cnt >= elemCnt / 2){
                median = i;
                if(elemCnt % 2 == 0 && cnt == elemCnt / 2){
                    for(i = i + 1; i < count.size() && count[i] == 0; ++i);
                    median += i;
                    median /= 2;
                }
                break;
            }
        }
        
        return {minimum, maximum, mean, median, (double)mode};
    }
};