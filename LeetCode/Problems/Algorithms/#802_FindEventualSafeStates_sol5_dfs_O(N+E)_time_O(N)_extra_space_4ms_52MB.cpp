class Solution {
private:
    enum State { NOT_VISITED, UNSAFE, SAFE };

    State computeState(int node, vector<vector<int>>& graph, vector<State>& stateOf){
        if(stateOf[node] != State::NOT_VISITED){
            return stateOf[node];
        }

        stateOf[node] = State::UNSAFE;
        for(int nextNode: graph[node]){
            if(computeState(nextNode, graph, stateOf) == State::UNSAFE){
                return State::UNSAFE;
            }
        }

        stateOf[node] = State::SAFE;
        return State::SAFE;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        const int N = graph.size();

        vector<int> safeNodes;
        vector<State> stateOf(N, State::NOT_VISITED);
        for(int node = 0; node < N; ++node){
            if(computeState(node, graph, stateOf) == State::SAFE){
                safeNodes.push_back(node);
            }
        }

        return safeNodes;
    }
};