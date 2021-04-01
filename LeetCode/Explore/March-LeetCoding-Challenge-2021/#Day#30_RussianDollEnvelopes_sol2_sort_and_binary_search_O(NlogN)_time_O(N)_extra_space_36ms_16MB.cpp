class Solution {
private:
    static bool comp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[0] < RHS[0] || (LHS[0] == RHS[0] && LHS[1] > RHS[1]));
    }
    
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        
        vector<int> h;
        for(int i = 0; i < (int)envelopes.size(); ++i){
            int currentHeight = envelopes[i][1];
            int pos = lower_bound(h.begin(), h.end(), currentHeight) - h.begin();
            if(pos >= (int)h.size()){
                h.resize(pos + 1);
            }
            h[pos] = currentHeight;
        }
        
        return h.size();
    }
};