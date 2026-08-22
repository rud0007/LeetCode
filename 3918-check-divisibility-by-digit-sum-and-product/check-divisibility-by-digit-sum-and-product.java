class Solution {
    public boolean checkDivisibility(int n) {
        int sum=0,temp=n,prod=1;
        while(temp>0){
            int digit=temp%10;
            sum+=digit;
            prod*=digit;
            temp/=10;
        }
        if(n%(sum+prod)==0){
            return true;
        }
        return false;
    }
}