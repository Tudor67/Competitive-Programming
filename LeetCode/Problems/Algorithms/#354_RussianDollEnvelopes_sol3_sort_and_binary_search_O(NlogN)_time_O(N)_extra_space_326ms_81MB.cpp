class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        const int N = envelopes.size();
        
        vector<pair<int, int>> sortedEnvelopes(N);
        for(int i = 0; i < N; ++i){
            sortedEnvelopes[i] = {envelopes[i][0], envelopes[i][1]};
        }
        
        sort(sortedEnvelopes.begin(), sortedEnvelopes.end(),
             [](const pair<int, int>& LHS, const pair<int, int>& RHS){
                 return (LHS.first < RHS.first || (LHS.first == RHS.first && LHS.second > RHS.second));
             });
        
        vector<pair<int, int>> v;
        for(const pair<int, int>& ENVELOPE: sortedEnvelopes){
            int l = 0;
            int r = (int)v.size();
            while(l != r){
                int mid = (l + r) / 2;
                if(v[mid].first < ENVELOPE.first && v[mid].second < ENVELOPE.second){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }
            
            int idx = r;
            if(idx >= (int)v.size()){
                v.push_back(ENVELOPE);
            }else{
                v[idx] = ENVELOPE;
            }
        }
        
        return v.size();
    }
};