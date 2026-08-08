class Solution {
    public int countPrimes(int n) {
        boolean[] isPrime=new boolean[n+1];
        for(int i=2; i<n; i++){
            isPrime[i]=true;
        }
        for(int p=2; p*p<n; p++){
            if(isPrime[p]){
                for(int j=p*p; j<=n; j+=p){
                    isPrime[j]=false;
                }
            }
        }
        int count=0;
        for(int i=2;i<n;i++){
            if(isPrime[i]) count++;
        }
        return count;
    }
}