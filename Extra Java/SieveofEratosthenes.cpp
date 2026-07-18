class Solution {
    public int countPrimes(int n) {
        
        boolean num[] = new boolean[n];
        Arrays.fill(num,true);

        if (n <= 2){
            return 0;
        }

        num[0] = false;
        num[1] = false;

        for (int i=2;i*i<n;i++){
            if (num[i]){
                for (int j = i*i;j<n;j+=i){
                    num[j] = false;
                }   
            }
        }

        int count = 0;
        for (boolean i : num){
            if (i){
                count++;
            }
        }

        return count;
    }
}