#include <iostream>

int n = 10;

int main() {
    int fib[n]; // create array of size n; type int
    fib[0] = 0;
    fib[1] = 1;
    
    for(int i = 1; i < n; i++) {
        fib[i + 1] = fib[i - 1] + fib[i];
    }
    
    for(int i = 0; i < n; i++) {
        std::cout << fib[i] << std::endl;
    }
    
    return 0;
}
