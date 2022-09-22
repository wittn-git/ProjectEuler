#include <chrono>
#include <iostream>
//

using namespace std::chrono;

int main(){
    auto start = high_resolution_clock::now();
    //
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << ((double)duration.count())/1000000 << std::endl;

    start = high_resolution_clock::now();
    //
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << ((double)duration.count())/1000000 << std::endl;
}