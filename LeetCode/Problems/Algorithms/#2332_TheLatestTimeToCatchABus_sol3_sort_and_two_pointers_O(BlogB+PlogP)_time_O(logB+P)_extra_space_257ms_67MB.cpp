class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& b, vector<int>& p, int capacity) {
        const int B = b.size();
        const int P = p.size();
        
        sort(b.begin(), b.end());
        sort(p.begin(), p.end());
        
        int maxTime = 1;
        int j = 0;
        vector<int> waiting;
        for(int i = 0; i < B; ++i){
            int startJ = j;
            
            waiting.clear();
            for(int k = 1; k <= capacity; ++k){
                if(j < P && p[j] <= b[i]){
                    waiting.push_back(p[j]);
                    j += 1;
                }else{
                    break;
                }
            }
            
            if(waiting.empty() ||
               ((int)waiting.size() < capacity && waiting.back() < b[i] && (j == P || p[j - 1] + 1 < p[j]))){
                maxTime = max(maxTime, b[i]);
            }
            
            if(startJ > 0){
                waiting.insert(waiting.begin(), p[startJ - 1]);
            }else{
                waiting.insert(waiting.begin(), -1);
            }
            
            for(int k = 1; k < (int)waiting.size(); ++k){
                if(waiting[k - 1] + 1 != waiting[k]){
                    maxTime = max(maxTime, waiting[k] - 1);
                }
            }
        }
        
        return maxTime;
    }
};