class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> answer;
        int k[100]={0};
        for (int i=0;i<queens.size();i++) {
            k[queens[i][0]*10+queens[i][1]]=1;
        }
        
        for (int i=king[0];i>=0;i--) 
            if (k[i*10+king[1]]) {
                vector<int> t;
                t.push_back(i);
                t.push_back(king[1]);
                answer.push_back(t);
                break;
            }
        
        for (int i=king[0];i<8;i++) 
            if (k[i*10+king[1]]) {
                vector<int> t;
                t.push_back(i);
                t.push_back(king[1]);
                answer.push_back(t);
                break;
            }
        
        for (int i=king[1];i>=0;i--) 
            if (k[king[0]*10+i]) {
                vector<int> t;
                t.push_back(king[0]);
                t.push_back(i);
                answer.push_back(t);
                break;
            }
                  
        for (int i=king[1];i<8;i++) 
            if (k[king[0]*10+i]) {
                vector<int> t;
                t.push_back(king[0]);
                t.push_back(i);
                answer.push_back(t);
                break;
            }
                  
        for (int i=1;i<8;i++) {
            int x=king[0]+i;
            int y=king[1]+i;
            if (x>=0 && y>=0 && x<8 && y<8)
                if (k[x*10+y]) {
                    vector<int> t;
                    t.push_back(x);
                    t.push_back(y);
                    answer.push_back(t);
                    break;
                }
        }
        
        for (int i=1;i<8;i++) {
            int x=king[0]+i;
            int y=king[1]-i;
            if (x>=0 && y>=0 && x<8 && y<8)
                if (k[x*10+y]) {
                    vector<int> t;
                    t.push_back(x);
                    t.push_back(y);
                    answer.push_back(t);
                    break;
                }
        }
        
        for (int i=1;i<8;i++) {
            int x=king[0]-i;
            int y=king[1]+i;
            if (x>=0 && y>=0 && x<8 && y<8)
                if (k[x*10+y]) {
                    vector<int> t;
                    t.push_back(x);
                    t.push_back(y);
                    answer.push_back(t);
                    break;
                }
        }
        
        for (int i=1;i<8;i++) {
            int x=king[0]-i;
            int y=king[1]-i;
            if (x>=0 && y>=0 && x<8 && y<8)
                if (k[x*10+y]) {
                    vector<int> t;
                    t.push_back(x);
                    t.push_back(y);
                    answer.push_back(t);
                    break;
                }
        }
        
        return answer;
    }
};