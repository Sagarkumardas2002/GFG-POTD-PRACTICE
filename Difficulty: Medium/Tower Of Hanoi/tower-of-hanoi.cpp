class Solution {
public:
    int towerOfHanoi(int n, int from, int to, int aux) {
               
        if(n==0)
        return 0;
        
        if(n==1)
        return 1;
        
        if(n==2)
        return 3;
        
        int ans=3;
        
        for(int i=3;i<=n;i++){
            ans=ans*2+1;
        }
        return ans; 
    }
};



