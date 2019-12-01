class Solution {
public:
    char m[3][3];
    
    char check() {
        for (int i=0;i<3;i++) {
            if (m[i][0]!=' ' && m[i][0]==m[i][1] && m[i][1]==m[i][2])
                return m[i][0];
            
            if (m[0][i]!=' ' && m[0][i]==m[1][i] && m[1][i]==m[2][i])
                return m[0][i];
        }
        
        if (m[1][1]!=' ' && m[0][0]==m[1][1] && m[1][1]==m[2][2])
            return m[0][0];
        
        if (m[1][1]!=' ' && m[2][0]==m[1][1] && m[1][1]==m[0][2])
            return m[1][1];
        
        return 'P';
    }
    
    string tictactoe(vector<vector<int>>& moves) {
        char t='A';
        
        for (int i=0;i<3;i++)
            for (int j=0;j<3;j++)
                m[i][j]=' ';
        for (auto it:moves) {
            m[it[0]][it[1]]=t;
            if (t=='A')
                t='B';
            else
                t='A';
        }
        
        char result=check();
        
        cout<<result<<endl;
        
        if (result=='A')
            return "A"; 
        else if (result=='B') 
            return "B";
        else if (result=='P') {
            if (moves.size()!=9)
                return "Pending";
            else
                return "Draw";
        }
        return "Pending";
    }
};