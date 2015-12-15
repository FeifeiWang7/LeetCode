public String convert(String s, int numRows) {
        StringBuilder res = new StringBuilder();
        StringBuilder[] sb = new StringBuilder[numRows];
        for(int i=0;i<sb.length;i++)    sb[i] = new StringBuilder();
        int i=0;
        while(i<s.length()){
            for(int n=0;n<numRows&&i<s.length();n++) sb[n].append(s.charAt(i++));
            for(int n=0;n<numRows-2&&i<s.length();n++)    sb[numRows-2-n].append(s.charAt(i++));
        }
        for(StringBuilder b: sb)    res.append(b);
        return res.toString();
    }
///
public class Solution {
    public String convert(String s, int numRows) {
        if(numRows==1) return s;
        String res="";
        String [] row_strs=new String [numRows];

        boolean inc=true;
        int r=0;
        for(int i=0; i<s.length(); i++){
            char cha=s.charAt(i);
            if(row_strs[r]==null) row_strs[r]=""; //CAUTION
            row_strs[r]+=cha;

            //Update inc
            if(r==numRows-1) inc=false;
            if(r==0) inc=true;

            //Update r
            if(inc) r++; else r--;
        }

        //Concate strings
        for(int i=0; i<numRows; i++){
            if(row_strs[i]==null) row_strs[i]="";//CAUTION
            res+=row_strs[i];
        }

        return res;
    }
}
