class Solution {
private:
    struct IncDistComp{
        bool operator()(const vector<int>& LHS, const vector<int>& RHS) const{
            return (LHS[0] * LHS[0] + LHS[1] * LHS[1]) < (RHS[0] * RHS[0] + RHS[1] * RHS[1]);
        }
    };
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, IncDistComp> maxHeap;
        for(const vector<int>& P: points){
            maxHeap.push(P);
            if((int)maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        
        vector<vector<int>> closestPoints;
        while(!maxHeap.empty()){
            closestPoints.push_back(maxHeap.top());
            maxHeap.pop();
        }
        
        return closestPoints;
    }
};