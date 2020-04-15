class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int weight: stones){
            pq.push(weight);
        }
        
        while(pq.size() >= 2){
            int mx1 = pq.top(); pq.pop();
            int mx2 = pq.top(); pq.pop();
            if(mx1 > mx2){
                pq.push(mx1 - mx2);
            }
        }
        
        int last_weight = 0;
        if(!pq.empty()){
            last_weight = pq.top();
        }
        
        return last_weight;
    }
};