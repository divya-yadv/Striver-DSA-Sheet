 double myPow(double x, int n) {
        if(n == 0)
        {
            return 1;
        }
        double p= myPow(x,n/2);
        if(n%2 == 0)
            return p*p;
        else{
             if(n>0)
                 return p*p*x;
             else
               // in case of negative power
                 return p*p/x;
        }
       return 1;      
}

// using binary search thing O(logn)
double myPow(double x, int n) {
       double res = 1;
        while (n) {
            if (n % 2) res = n > 0 ? res * x : res / x;
            x = x * x;
            n /= 2;
        }
        return res;
    }
