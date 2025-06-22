// User function Template for C++

class Solution {
  public:
    
    // Function to find the parent with path compression
   int  find(int x, int par[]){
        if(par[x]!=x){
            par[x]=find(par[x], par);
        } 
        return par[x];
    }
    
    // Function to merge two nodes a and b.
    void union_(int a, int b, int par[], int rank1[]) {
         int pa = find(a, par); 
         int pb = find(b, par);
        
        if(pa==pb) return;
        
        if(rank1[pa]<rank1[pb]){
            par[pa]=pb;
        }
        
        else if(rank1[pa]>rank1[pb]){
            par[pb]=pa;
        }
        
        else {
            par[pb] = pa;
            rank1[pa]++;
        }
    }

    // Function to check whether 2 nodes are connected or not.
    bool isConnected(int x, int y, int par[], int rank1[]) {
     return find(x,par)==find(y,par);
    }
};