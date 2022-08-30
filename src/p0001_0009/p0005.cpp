/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <iostream>
#include <map>
#include <list>
#include <cmath>

bool isPrime(int n, std::list<int> primes){
    for(auto it = primes.begin(); it != primes.end(); ++it){
        if(n % *it == 0) return false;
        if(*it > sqrt(n)) return true;
    }
    return true;
}

std::map<int, int> getPrimefactors(int n, std::list<int> primes){
    std::map<int, int> primefactors;
    for(auto it = primes.begin(); it != primes.end(); ++it){
        if(n % *it == 0){
            n /= *it;
            if(primefactors.find(*it) != primefactors.end()){
                primefactors[*it]++; 
            }else{
                primefactors[*it] = 1; 
            }
            if(n == 1) return primefactors;
            it--;
        }
    }
    return primefactors;
}

std::map<int, int> mergeMap(std::map<int, int> map1, std::map<int, int> map2){
    for(auto it1 = map2.begin(); it1 != map2.end(); ++it1){
        auto it2 = map1.find(it1->first);
        if (it2 == map1.end() || it2->second < it1->second) {
            map1[it1->first] = it1->second;
        }
    }
    return map1;
}


int main(){
    std::list<int> primes;
    for(int i=2; i<=20; i++){
        if(isPrime(i, primes)) primes.emplace_back(i);
    }
    std::map<int, int> primefactors;
    for(int i=11; i<=20; i++){
        auto k = getPrimefactors(i, primes);
        primefactors = mergeMap(primefactors, getPrimefactors(i, primes));
    }
    int res = 1;
    for(auto it = primefactors.begin(); it != primefactors.end(); ++it){
        res *= pow(it->first, it->second);
    }
    std::cout << res << std::endl;
    return 0;
}