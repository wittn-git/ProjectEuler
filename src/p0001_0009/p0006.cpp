/*
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include <iostream>
#include <cmath>

int main(){
    long sum1 = 0;
    for(int i=1; i<=100; i++){
        sum1 += i;
    }
    long sum2 = 0;
    for(int i=1; i<=100; i++){
        sum2 += pow(i,2);
    }
    long res = pow(sum1, 2) - sum2;
    std::cout << res << std::endl;
    return 0;
}