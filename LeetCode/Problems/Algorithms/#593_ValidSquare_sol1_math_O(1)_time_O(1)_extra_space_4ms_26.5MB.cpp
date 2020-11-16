class Solution {
private:
    int dist(const vector<int>& P1, const vector<int>& P2){
        return (P1[0] - P2[0]) * (P1[0] - P2[0]) + (P1[1] - P2[1]) * (P1[1] - P2[1]);
    }
    
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        const int N = 4;
        vector<vector<int>> p = {p1, p2, p3, p4};
        
        vector<int> distances;
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                distances.push_back(dist(p[i], p[j]));
            }
        }
        
        sort(distances.begin(), distances.end());
        
        bool isValid = (distances[0] == distances[3] &&
                        distances[4] == distances[5] &&
                        distances[3] != distances[4]);
        
        return isValid;
    }
};