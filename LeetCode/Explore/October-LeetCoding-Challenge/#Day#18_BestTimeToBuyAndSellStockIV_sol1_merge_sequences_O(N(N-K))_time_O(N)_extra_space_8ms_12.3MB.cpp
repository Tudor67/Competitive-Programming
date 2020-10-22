class Solution {
private:
    int profit(const pair<int, int>& INTERVAL){
        return (INTERVAL.second - INTERVAL.first);
    }
    
    pair<int, int> getMergedInterval(const pair<int, int>& PREV_INTERVAL, const pair<int, int>& INTERVAL){
        return {PREV_INTERVAL.first, max(PREV_INTERVAL.second, INTERVAL.second)};
    }
    
    int mergeLoss(const pair<int, int>& PREV_INTERVAL, const pair<int, int>& INTERVAL){
        return (profit(PREV_INTERVAL) + profit(INTERVAL) - profit(getMergedInterval(PREV_INTERVAL, INTERVAL)));
    }
    
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k == 0 || prices.empty()){
            return 0;
        }
        
        // Step 1: keep only increasing sequences/intervals as a vector of pairs:
        //         {{prices[start1], prices[end1]}, {prices[start2], prices[end2]}, ... }
        const int N = prices.size();
        int sum = 0;
        int startPos = 0;
        vector<pair<int, int>> intervals;
        for(int i = 1; i < N; ++i){
            if(prices[i] - prices[i - 1] >= 0){
                sum += prices[i] - prices[i - 1];
            }else{
                if(sum > 0){
                    intervals.push_back({prices[startPos], prices[i - 1]});
                }
                sum = 0;
                startPos = i;
            }
        }
        
        if(sum > 0){
            intervals.push_back({prices[startPos], prices[N - 1]});
        }
        
        // Step 2: delete or merge redundant sequences/intervals, minimizing the profitLoss
        while(intervals.size() > k){
            int minDeleteIdx = 0;
            for(int i = 0; i < intervals.size(); ++i){
                if(profit(intervals[i]) < profit(intervals[minDeleteIdx])){
                    minDeleteIdx = i;
                }
            }
            int minDeleteLoss = profit(intervals[minDeleteIdx]);
            
            int minMergeIdx = 1;
            for(int i = 1; i < intervals.size(); ++i){
                if(mergeLoss(intervals[i - 1], intervals[i]) < mergeLoss(intervals[minMergeIdx - 1], intervals[minMergeIdx])){
                    minMergeIdx = i;
                }
            }
            int minMergeLoss = mergeLoss(intervals[minMergeIdx - 1], intervals[minMergeIdx]);
            
            if(minDeleteLoss < minMergeLoss){
                intervals.erase(intervals.begin() + minDeleteIdx);
            }else{
                intervals[minMergeIdx - 1] = getMergedInterval(intervals[minMergeIdx - 1], intervals[minMergeIdx]);
                intervals.erase(intervals.begin() + minMergeIdx);
            }
        }
        
        // Step 3: compute the answer
        int answer = 0;
        for(int i = 0; i < intervals.size(); ++i){
            answer += intervals[i].second - intervals[i].first;
        }
        
        return answer;
    }
};