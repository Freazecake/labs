#include<iostream>
#include<cmath>

bool IsPrime(int n){
    for(size_t i=2;i<=sqrt(n);++i){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    try{
        int t;
        std::cout<<"enter the number of twins: ";
        if(!(std::cin>>t))  throw "you need to enter a number";
        int i{2};
        while(t>0){
            if(IsPrime(i) && IsPrime(i+2)){
                std::cout<<i<<" and "<<i+2<<"; ";
                --t;
            }
            ++i;
        }
    }
    catch(const char* msg){
        std::cout<<msg;
    }
}