class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.empty() || nums2.empty()){
            return {};
        }
        
        vector<vector<int>> answer;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        set<pair<int, int>> pairSet;
        pq.push({nums1[0] + nums2[0], 0, 0});
        pairSet.insert({0, 0});
        
        k = min((int)nums1.size() * (int)nums2.size(), k);
        for(int i = 1; !pq.empty() && i <= k; ++i){
            int u = pq.top()[1];
            int v = pq.top()[2];
            pq.pop();
            
            answer.push_back({nums1[u], nums2[v]});
            
            if(u + 1 < nums1.size() && pairSet.find({u + 1, v}) == pairSet.end()){
                pq.push({nums1[u + 1] + nums2[v], u + 1, v});
                pairSet.insert({u + 1, v});
            }
            if(v + 1 < nums2.size() && pairSet.find({u, v + 1}) == pairSet.end()){
                pq.push({nums1[u] + nums2[v + 1], u, v + 1});
                pairSet.insert({u, v + 1});
            }
        }
        
        return answer;
    }
};