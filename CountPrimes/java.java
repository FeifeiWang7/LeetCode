public class Solution {
    public int countPrimes(int n) {
         boolean[] m = new boolean[n];
        int count = 0;
        for (int i=2; i<n; i++) {
            if (m[i])
                continue;

            count++;
            for (int j=i; j<n; j=j+i)
                m[j] = true;
        }

        return count;
    }
}
/////
public class Solution {
public int countPrimes(int n) {
    if (n <= 2) {
        return 0;
    }
    int count = 1;
    for (int i = 3; i < n; i++) {
        if (isPrime(i) == true) {
            count++;
        }
    }

    return count;
}

public boolean isPrime(int n) {
    if (n % 2 == 0) {
        return false;
    }
    for(int j = 3; j*j <= n; j+=2) {
        if (n%j == 0) {
            return false;
        }
    }

    return true;
}
}
