class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> answer;
        sort(arr.begin(), arr.end());
        
        int Min=20000001;
        for (int i=1;i<arr.size();i++)
            Min=min(abs(arr[i]-arr[i-1]), Min);
            
        for (int i=1;i<arr.size();i++)
            if (abs(arr[i]-arr[i-1])==Min)
            {
                vector<int> tmp;
                tmp.push_back(arr[i-1]);
                tmp.push_back(arr[i]);
                answer.push_back(tmp);
            }
        
        return answer;
    }
};