class Solution {
    public boolean checkIfPangram(String sentence) {
        boolean seen[]=new boolean[26];
        for(int  i=0;i<sentence.length();i++){
            char current=sentence.charAt(i);
            seen[current-'a']=true;
        }
        for(int  i=0;i<seen.length;i++){
            if(!seen[i]){
                return false;
            }
        }
        return true;
        
    }
}