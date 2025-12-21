class DSU{
private:
    vector<int> size;
    vector<int> parent;

public:
    DSU(const int N){
        size.assign(N, 1);
        parent.resize(N);
        iota(parent.begin(), parent.end(), 0);
    }

    void reset(int x){
        size[x] = 1;
        parent[x] = x;
    }

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void join(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);
        if(xRoot == yRoot){
            return;
        }
        if(size[xRoot] > size[yRoot]){
            swap(xRoot, yRoot);
        }
        parent[xRoot] = yRoot;
        size[yRoot] += size[xRoot];
    }
};

class Solution {
public:
    vector<int> findAllPeople(int N, vector<vector<int>>& meetings, int firstPerson) {
        const int M = meetings.size();

        map<int, vector<pair<int, int>>> timeToMeetings;
        timeToMeetings[0].push_back({0, firstPerson});
        for(vector<int>& meeting: meetings){
            int x = meeting[0];
            int y = meeting[1];
            int t = meeting[2];
            timeToMeetings[t].push_back({x, y});
        }

        DSU dsu(N);
        for(auto& [currTime, currMeetings]: timeToMeetings){
            for(auto& [x, y]: currMeetings){
                dsu.join(x, y);
            }

            for(auto& [x, y]: currMeetings){
                if(dsu.find(x) != dsu.find(0)){
                    dsu.reset(x);
                    dsu.reset(y);
                }
            }
        }

        vector<int> res;
        for(int person = 0; person < N; ++person){
            if(dsu.find(0) == dsu.find(person)){
                res.push_back(person);
            }
        }

        return res;
    }
};