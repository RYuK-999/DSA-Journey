// Recursive function

class Solution {                                       // b is raised to the power e
  public:
    double power(double b, int e) {
        if (e==0){
            return 1;
        }
        if (e<0){
            return power(1/b,-e);
        }
        
        double half = power(b,e/2);
        
        if (e%2 == 0){
            return half * half;
        }
        else{
            return b * half * half;
        }
    }
};

// Iterative function

double power(double b, int e) {
    long long exponent = e; // to handle negative exponents safely
    if (exponent < 0) {
        b = 1 / b;
        exponent = -exponent;
    }

    double result = 1.0;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= b;       // multiply when the current bit is set (odd power)
        }
        b *= b;                // square the base each time
        exponent /= 2;         // divide exponent by 2
    }

    return result;
}
