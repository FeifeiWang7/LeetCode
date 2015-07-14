int lengthOfLastWord(string s) {
        int i;int size = s.length();
        while(s[size-1]==' ')   s.resize(--size);
        i = s.find_last_of(' ');
        return (i==-1)?size:size-i-1;
    }
