class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int a[2002]={0};
        vector<int> answer;
        for (int i=0;i<arr1.size();i++)
            a[arr1[i]]++;
        for (int i=0;i<arr2.size();i++)
            a[arr2[i]]++;
        for (int i=0;i<arr3.size();i++)
            a[arr3[i]]++;
        for (int i=1;i<=2000;i++)
            if (a[i]==3)
                answer.push_back(i);
        return answer;
    }
};