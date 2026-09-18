class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, int>> com;

        for (int i = 0; i < speed.size(); i++) {
            com.push_back({position[i], speed[i]});
        }

        sort(com.begin(), com.end(), greater<>());

        double maxx = 0.0;
        int fleet = 0;

        for (auto p : com) {

            double tta = (double)(target - p.first) / p.second;

            if (tta > maxx) {
                fleet++;
                maxx = tta;
            }
        }

        return fleet;
    }
};