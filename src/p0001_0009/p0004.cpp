/*
A palindromic number reads the same both ways. 
The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <iostream>
#include <queue>

struct it{
    int const_factor;
    int current_factor;
    bool operator<(const it& rhs) const{
        return const_factor*current_factor < rhs.const_factor*rhs.current_factor;
    }
};

bool isPalindrome(int n){
    std::string s = std::to_string(n);
    int len = s.length();
    for(int i=0; i<len/2; i++){
        if(s[i] != s[len-1-i]) return false;
    }
    return true;
}

int main(){
    std::priority_queue<it> queue;
    for(int i=0; i<1000; i++){
        queue.push(it{i, 999});
    }
    it current;
    while(!isPalindrome(current.const_factor*current.current_factor)){
        current.current_factor--;
        queue.push(current);
        current = queue.top();
        queue.pop();
    }
    std::cout << current.current_factor*current.const_factor << std::endl;
    return 0;
}