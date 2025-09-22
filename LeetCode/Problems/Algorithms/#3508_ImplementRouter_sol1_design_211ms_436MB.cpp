struct Packet{
    int source;
    int destination;
    int timestamp;

    Packet(int source, int destination, int timestamp): 
           source(source), destination(destination), timestamp(timestamp){
    }

    bool operator<(const Packet& other) const {
        return tuple<int, int, int>{source, destination, timestamp} <
               tuple<int, int, int>{other.source, other.destination, other.timestamp};
    }
};

class Router {
private:
    deque<Packet> packetsDQ;
    set<Packet> packetsSet;
    unordered_map<int, deque<int>> timestampsAt;
    int memoryLimit;

public:
    Router(int memoryLimit) {
        this->memoryLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        Packet packet(source, destination, timestamp);
        if(!packetsDQ.empty() && packetsDQ.back().timestamp != timestamp){
            packetsSet.clear();
        }
        if(packetsSet.count(packet)){
            return false;
        }
        if((int)packetsDQ.size() == memoryLimit){
            forwardPacket();
        }
        packetsDQ.push_back(packet);
        packetsSet.insert(packet);
        timestampsAt[packet.destination].push_back(packet.timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(packetsDQ.empty()){
            return {};
        }
        Packet packet = packetsDQ.front();
        packetsDQ.pop_front();
        packetsSet.erase(packet);
        timestampsAt[packet.destination].pop_front();
        return {packet.source, packet.destination, packet.timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        deque<int>& t = timestampsAt[destination];
        return upper_bound(t.begin(), t.end(), endTime) -
               lower_bound(t.begin(), t.end(), startTime);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */