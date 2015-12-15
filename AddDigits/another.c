int addDigits(int num) {
    int x;
    if(num==0){
        return 0;
    }
    else
    {
        x=num%9;
        if(x==0)
            return 9;
        else
             return x;
    }
}
