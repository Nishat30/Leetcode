class Solution {
    public int myAtoi(String s) {
        int sign=1;
        long fans=0;
        int i=0;
        int n=s.length();

        while (i<n && s.charAt(i)==' ') {
            i++;
        }

        if(i<n && (s.charAt(i)=='-' || s.charAt(i)=='+')){
            sign=(s.charAt(i)=='-')?-1:1;
            i++;
        }

        while(i < n && Character.isDigit(s.charAt(i))){
            fans = fans * 10 + (s.charAt(i) - '0');
            if (fans*sign > Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if (fans*sign < Integer.MIN_VALUE) return Integer.MIN_VALUE;
            i++;
        }
        return (int)(fans * sign);
    }
}