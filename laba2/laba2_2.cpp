#include<iostream>
#include<cmath>

void calcDigits(int num, int *digits,int &digitNumber){
    while(num>0){
        digits[digitNumber]=num%10;
        ++digitNumber;
        num/=10;
    }
}

bool IsArmstrongNumber(int num){
    int digitNumber{};
    int digits[20];
    calcDigits(num, digits, digitNumber);
    int sum{};
    for(size_t i=0;i<digitNumber;++i){
        sum+=pow(digits[i],digitNumber);
    }
    return sum==num;
}

int main(){
    try{
        int n;
        bool IsOneNumber=0;
    std::cout<<"enter upper bound: ";
    if(!(std::cin>>n))  throw "you need to enter a number\n";
    for(size_t i=1;i<=n;++i){
        if(IsArmstrongNumber(i)){
            if (!IsOneNumber){
                IsOneNumber=1;
                std::cout<<"Armstrong numbers: ";
            }
            std::cout<<i<<" ";
        }
    }
    }
    catch(const char* msg){
        std::cout<<msg;
    }
}