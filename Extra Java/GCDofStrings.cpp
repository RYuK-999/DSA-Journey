
class Solution {

    public int gcd(int a,int b){
        if (a%b == 0){
            return b;
        }

        return gcd(b,a%b);
    }

    public String gcdOfStrings(String str1, String str2) {
        
        int lenStr1 = str1.length();
        int lenStr2 = str2.length();

        if ((str1+str2).equals(str2+str1)){
            int gcdValue = gcd(lenStr1,lenStr2);
            String result = str1.substring(0,gcdValue);
            return result;
        }
        
        return "";
    }
}