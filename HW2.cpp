//
// Created by zeyne on 6.04.2022.
//

#include <valarray>
#include <ctime>
#include <iostream>
using namespace std;

int naiveAlgorithm(long a, long long n, long p) {
    int result = 0;
    for(int i = 0; i < n; i++){
        a = (a*a)%p;
        result = a;
    }
    return result;
}

int naiveWithCycle(int a, long long n, long long p) {
    int result = 0;
    for(int i = 0; i < n; i++){
        a = (a*a)%p;
        result = a;
        if(((a*a)%p)==1){
            for(int j = i; j < n; j++){
                a = pow(a,n%i);
                a=a%p;
                result = a;
            }
        }
    }
    return result;
}

int recursiveAlgorithm(int a, long long n, long long p) {
    if(n==1){
        return a%p;
    }
    if(n%2==0){
        return recursiveAlgorithm(a,n/2,p)* recursiveAlgorithm(a,n/2,p)%p;
    }
    else{
        return a*recursiveAlgorithm(a,(n-1)/2,p)* recursiveAlgorithm(a,(n-1)/2,p)%p;
    }

}
int main() {
    double duration;

    clock_t startTime = clock();
//Code block
  //  naiveAlgorithm(5000000 ,1000000,10007);
  //  naiveWithCycle(5000000 ,1000000,10007);
    recursiveAlgorithm(5000000 ,1000000,10007);
//Compute the number of seconds that passed since the starting time
    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
}
