class Solution {
public:
    string toHexspeak(string num) {
        long long n =0;
        for (int i=0;i<num.size();i++)
            n=n*10+(num[i]-'0');
        // cout<<n<<endl;
        string s;
        char d[16]={'O','I','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
        while (n!=0) {
            if (1<n%16 && n%16<=9)
                return "ERROR";
            
            s=d[n%16]+s;
            n=n/16;
        }
        
        
        return s;
    }
};