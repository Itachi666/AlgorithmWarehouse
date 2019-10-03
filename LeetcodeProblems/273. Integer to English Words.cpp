// Runtime: 4 ms
// Memory Usage: 813.5 KB

class Solution {
public:
    string get1k(int num) {
        int i,j,k;
        i=num/100;
        j=num%100/10;
        k=num%10;
        string a[10]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        string b[10]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        string c[10]={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        string s;
        
        if (i!=0)
            s=a[i]+" Hundred";
        
        if (num%100>9 && num%100<20)
        {
            if (i!=0) s+=' ';
            s+=b[num%100-10];
        }
        else if (num%100!=0)
        {
            if (j!=0 && i!=0)
                s+=' ';
            s+=c[j];
            if (k!=0 && num/10!=0)
                s+=' ';
            s+=a[k];
        }
        return s;
    }
    
    string numberToWords(int num) {
        string s;
        int t=num;
        if (num==0)
            return "Zero";
        
        if (num/1000000000!=0)
            s+=get1k(num/1000000000)+" Billion";
        
        num=num%1000000000;
        if (num/1000000!=0)
        {
            if (t/1000000000!=0) s+=' ';
            s+=get1k(num/1000000)+" Million";
        }
        
        num=num%1000000;
        if (num/1000!=0)
        {
            if (t/1000000!=0) s+=' ';
            s+=get1k(num/1000)+" Thousand";
        }
        
        if (t/1000!=0 && num%1000!=0) s+=' ';
        s+=get1k(num%1000);

        return s;
    }
};