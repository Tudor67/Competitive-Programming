class Solution {
private:
    static bool incEndComp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[1] < RHS[1]);
    }
    
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        const int N = events.size();
        
        sort(events.begin(), events.end(), incEndComp);
        
        int answer = 0;
        vector<int> prefMax(N);
        for(int i = 0; i < N; ++i){
            int startTime = events[i][0];
            int endTime = events[i][1];
            int val = events[i][2];
            // binary search
            int l = 0;
            int r = i;
            while(l != r){
                int mid = (l + r) / 2;
                if(events[mid][1] < startTime){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }
            // update answer
            int j = r - 1;
            int profit = val;
            if(0 <= j && j <= i - 1){
                profit += prefMax[j];
            }
            answer = max(answer, profit);
            // update prefMax
            if(i == 0){
                prefMax[i] = val;
            }else{
                prefMax[i] = max(prefMax[i - 1], val);
            }
        }
        
        return answer;
    }
};