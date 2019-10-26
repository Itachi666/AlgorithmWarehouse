class Solution {
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
        map<int, int> times;

        map<int, vector<int>> list;

        int answer = 0;
        times[0] = 0;
        for (int i = 0; i < startTime.size(); i++) {
            times[endTime[i]] = 0;
            list[endTime[i]].push_back(i);
        }

        for (auto e:list) {
            for (auto i:e.second) {
                auto t = times.upper_bound(startTime[i]);
                t--;

                answer = max(answer, t->second + profit[i]);
            }
            times[e.first] = answer;
        }


        return answer;
    }
};