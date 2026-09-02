class Solution {
    public String removeStars(String s) {
        int top=-1;
        char[] stack=new char[s.length()];
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)!='*'){
                top++;
                stack[top]=s.charAt(i);
            }else{
                top--;
            }
        }
       return new String(stack,0,top+1);
        
    }
}