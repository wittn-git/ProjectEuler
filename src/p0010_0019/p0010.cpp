/*
Find the sum of all the primes below two million.
*/

#include <iostream>
#include <cmath>

bool isPrime(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    long res = 0;
    for(int i=2; i<2000000; i++){
        if(isPrime(i)) res += i;
    }
    std::cout << res << std::endl;
    return 0;
}
