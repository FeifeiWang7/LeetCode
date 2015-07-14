public boolean isPalindrome(int x) {
            String s=null;
            if(x<0)   return false;
            else   s=String.valueOf(x);
            int i=0;int j=s.length()-1;
            while(j>=i)
            {
                if(s.charAt(i)==s.charAt(j)){ j--;i++;}
                else return false;
            }
            return true;
        }
