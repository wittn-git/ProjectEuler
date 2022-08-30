/*
What is the 10 001st prime number?
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
    int k = 1;
    int n = 0;
    while(n != 10001){
        k++;
        if(isPrime(k)) n++;
    }
    std::cout << k << std::endl;
    return 0;
}
