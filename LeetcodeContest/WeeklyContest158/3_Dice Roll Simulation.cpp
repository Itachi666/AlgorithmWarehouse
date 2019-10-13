class Solution {
public:
    int c[5000][6][16]={0};
    
    int dieSimulator(int n, vector<int>& rollMax) {
        const int T=1000000007;
        
        int answer=0;
        
        
        for (int i=0;i<6;i++) {
            c[0][i][1]=1;
        }
        
        for (int i=1;i<n;i++) {
            for (int j=0;j<6;j++) {
                
                for (int k=2;k<=rollMax[j];k++) {
                    c[i][j][k]=(c[i][j][k]+c[i-1][j][k-1]) %T;
                    
                    for (int l=0;l<6;l++) 
                        if (l!=j) 
                            c[i][l][1]= (c[i][l][1] + c[i-1][j][k-1] )%T;
                }
                
                int t=c[i-1][j][rollMax[j]];
                
                for (int l=0;l<6;l++) 
                    if (l!=j) 
                        c[i][l][1]= (c[i][l][1] + t )%T;
                
            }
        }
        
        for (int i=0;i<6;i++)
            for (int j=1;j<=rollMax[i];j++) 
                answer = (answer+c[n-1][i][j]) %T;
        return answer;
    }
};