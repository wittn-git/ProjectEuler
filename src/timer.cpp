#include <chrono>
#include <iostream>
//include

using namespace std::chrono;

int main(){
    auto start = high_resolution_clock::now();
    //function
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << ((double)duration.count())/1000000 << std::endl;
}