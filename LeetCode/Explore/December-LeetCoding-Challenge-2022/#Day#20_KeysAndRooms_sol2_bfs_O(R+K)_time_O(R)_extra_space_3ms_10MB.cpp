class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        const int R = rooms.size();

        vector<bool> vis(R, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;

        while(!q.empty()){
            int room = q.front();
            q.pop();

            for(int nextRoom: rooms[room]){
                if(!vis[nextRoom]){
                    vis[nextRoom] = true;
                    q.push(nextRoom);
                }
            }
        }

        return (count(vis.begin(), vis.end(), true) == R);
    }
};