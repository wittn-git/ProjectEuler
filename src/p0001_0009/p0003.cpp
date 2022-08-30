/*
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
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
    long res = 600851475143;
    int largest_prime;
    for(int i=2; i<=res; i++){
        if(isPrime(i)){
            if(res % i == 0){
                res = res / i;
                largest_prime = i;
                if(res == 1) break;
            }
        }
    }
    std::cout << largest_prime << std::endl;
    return 0;
}