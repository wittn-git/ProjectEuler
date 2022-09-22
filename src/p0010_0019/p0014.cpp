/*
Which starting number, under one million, produces the longest collatz-chain?
*/

#include <iostream>
#include <unordered_map>

std::unordered_map<long, int> lengths = {{1,1}};

int main(){
    p2();
    return 0;
}

int p1(){
    int max_length = 0;
    long max_n = 0;
    for(int i=1; i<1000000; i++){
        long current_n = i;
        int current_length = 0;
        while(current_n != 1){
            if(current_n % 2 == 0) current_n = current_n/2;
            else current_n = 3*current_n+1;
            current_length++;
            if(lengths.find(current_n) != lengths.end()){
                current_length += lengths[current_n];
                break;
            }
        }
        lengths[i] = current_length;
        if(max_length < current_length){
            max_length = current_length;
            max_n = i;
        }
    }
    std::cout << max_n << std::endl;
    return 0;
}

int p2(){
    int current_max = 0;
    long current_k = 0;
    for(int i=1; i<1000000; i++){
        long k = i;
        int n = 0;
        while(k!=1){
            if(k%2==0) k = k/2;
            else k = 3*k+1;
            n++;
        }
        if(current_max < n){
            current_max = n;
            current_k = i;
        }
    }
    std::cout << current_k << std::endl;
    return 0;
}