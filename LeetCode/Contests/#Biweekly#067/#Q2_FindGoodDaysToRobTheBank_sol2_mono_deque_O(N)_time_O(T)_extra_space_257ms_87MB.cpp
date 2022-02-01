class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int T) {
        const int N = security.size();
        
        deque<int> dec;
        deque<int> inc;
        vector<int> answer;
        for(int i = 0; i + T < N; ++i){
            if(!dec.empty() && security[dec.back()] < security[i]){
                dec.clear();
            }
            dec.push_back(i);
            if(i - dec.front() > T){
                dec.pop_front();
            }
            if(!inc.empty() && security[inc.back()] > security[i + T]){
                inc.clear();
            }
            inc.push_back(i + T);
            if(i + T - inc.front() > T){
                inc.pop_front();
            }
            if((int)dec.size() == T + 1 && (int)inc.size() == T + 1){
                answer.push_back(i);
            }
        }
        
        return answer;
    }
};