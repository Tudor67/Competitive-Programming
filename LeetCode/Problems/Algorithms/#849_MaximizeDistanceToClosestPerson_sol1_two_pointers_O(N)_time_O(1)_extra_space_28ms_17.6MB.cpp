class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        const int N = seats.size();
        
        int p1 = find(seats.begin(), seats.end(), 1) - seats.begin();
        int p2 = p1 + 1;
        int answer = p1;
        while(p2 < N){
            p2 = find(seats.begin() + p1 + 1, seats.end(), 1) - seats.begin();
            if(p2 < N){
                answer = max((p2 - p1) / 2, answer);
            }else{
                answer = max(N - 1 - p1, answer);
            }
            p1 = p2;
            p2 = p1 + 1;
        }
        
        return answer;
    }
};