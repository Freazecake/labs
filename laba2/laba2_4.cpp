#include<iostream>

bool AreRelativelyPrime(int m, int n){
    while(n>0){
        int temp=n;
        n=m%n;
        m=temp;        
    }
    return m==1;
}

int main(){
    try{
        int num;
        bool IsOneNumber=0;
        std::cout<<"enter upper bound: ";
    if(!(std::cin>>num))  throw "you need to enter a number\n";
    for(size_t m=2, n=1;m*m+n*n<=num;++m){
        for(;n<=m && m*m+n*n<=num;++n){
            if(AreRelativelyPrime(m, n) && (m-n)%2){
                if (!IsOneNumber){
                    IsOneNumber=1;
                    std::cout<<"Piphagorean triples: ";
                }
                std::cout<<m*m-n*n<<" "<<2*m*n<<" "<<m*m+n*n<<"\n";
                for(size_t k=2;(m*m+n*n)*k<=num;++k){
                    std::cout<<(m*m-n*n)*k<<" "<<k*2*m*n<<" "<<k*(m*m+n*n)<<"\n";
                }
        }
        }
        n=1;
    }
    }
    catch(const char* msg){
        std::cout<<msg;
    }
}