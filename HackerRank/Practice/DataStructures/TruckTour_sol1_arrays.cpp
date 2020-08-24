int truckTour(vector<vector<int>> petrol_pumps) {
    const int N = petrol_pumps.size();

    int petrol = 0;
    int start_idx = 0;

    for(int i = 0; i < 2 * N; ++i){
        petrol += petrol_pumps[i % N][0] - petrol_pumps[i % N][1];
        if(petrol < 0){
            petrol = 0;
            start_idx = i + 1;
        }else if(petrol >= 0 && i + 1 - start_idx == N){
            break;
        }
    }

    return start_idx;
}