public class Solution {
public boolean isValid(String s) {
    StringBuffer bf=new StringBuffer();
    int i=0;
    char temp;
    boolean flag=true;
    while(i<s.length())
    {
        temp=s.charAt(i);
        if(bf.length()!=0&&(temp==(char)(bf.charAt(bf.length()-1)+1)||temp==(char)(bf.charAt(bf.length()-1)+2)))
                bf.deleteCharAt(bf.length()-1);
        else
            bf.append(temp);
        i++;
    }
    if(bf.length()!=0)
        flag=false;
    return flag;
}
}
