/*
What is the value of the first triangle number to have over five hundred divisors?
*/

#include <iostream>
#include <cmath> 

int getDivisors_n(int n){ 
    int res = 0; 
    for(int i=1; i<=sqrt(n); i++){ 
        if(n % i == 0){ 
            res+= 2;             
        } 
    }
    return res; 
}

int main(){
    int n = 1;
    int k = 2;
    while(getDivisors_n(n) <= 500){ 
        n+=k;
        k++; 
    }
    std::cout << n << std::endl; 
    return 0;
}