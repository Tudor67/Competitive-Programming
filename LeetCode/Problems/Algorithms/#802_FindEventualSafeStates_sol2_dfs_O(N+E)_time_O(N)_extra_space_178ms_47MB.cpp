class Solution {
private:
    enum State { NOT_VISITED, UNSAFE, SAFE };
    
    State computeStateOf(int node, vector<vector<int>>& graph, vector<State>& stateOf){
        if(stateOf[node] != State::NOT_VISITED){
            return stateOf[node];
        }

        stateOf[node] = State::UNSAFE;
        for(int nextNode: graph[node]){
            if(computeStateOf(nextNode, graph, stateOf) == State::UNSAFE){
                return State::UNSAFE;
            }
        }

        stateOf[node] = State::SAFE;
        return stateOf[node];
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int N = graph.size();

        vector<State> stateOf(N, State::NOT_VISITED);
        vector<int> res;
        for(int node = 0; node < N; ++node){
            if(computeStateOf(node, graph, stateOf) == State::SAFE){
                res.push_back(node);
            }
        }

        return res;
    }
};