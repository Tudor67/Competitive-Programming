class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int N = rooms.size();
        
        vector<bool> visited(N, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            int room = q.front();
            q.pop();
            
            for(int nextRoom: rooms[room]){
                if(!visited[nextRoom]){
                    q.push(nextRoom);
                    visited[nextRoom] = true;
                }
            }
        }
        
        int visitedRooms = count(visited.begin(), visited.end(), true);
        
        return (visitedRooms == N);
    }
};