/*
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <iostream>
#include <cmath>

int main(){
    double intpart;
    for(int a=1; a<500; a++){
        double b = (pow(1000,2)-2000*a) / (2000-2*a);
        if(modf(b, &intpart) == 0.0){
            double c = sqrt(pow(a,2)+pow(b,2));
            if(modf(b, &intpart) == 0.0){
                int res = a*b*c;
                std::cout << res << std::endl;
                break;
            }
        }        
    }
    return 0;
}