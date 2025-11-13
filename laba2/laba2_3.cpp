#include<iostream>

void calcDigits(int num, int *digits,size_t digitNumber);
bool IsGoodNumber(int num);

int main(){
    try{
        int a, b;

        std::cout<<"enter left border: ";
        if(!(std::cin>>a))  throw "you need to enter a number\n";
        std::cout<<"enter right border: ";
        if(!(std::cin>>b))  throw "you need to enter a number\n";

        if(a>b) std::swap(a, b);
        bool IsOneNumber=0;
        for(int i=a; i<=b; ++i){
            if(IsGoodNumber(i)){
                if (!IsOneNumber){
                IsOneNumber=1;
                std::cout<<"Numbers which digits are in increasing order: ";
            }
            std::cout<<i<<" ";
            }
        }
    }
    catch(const char* msg){
        std::cout<<msg;
    }
}

void calcDigits(int num, int *digits,int &digitNumber){
    while(num>0){
        digits[digitNumber]=num%10;
        ++digitNumber;
        num/=10;
    }
}

bool IsGoodNumber(int num){
    int digitNumber{};
    int digits[20];
    bool IsGoodNum=1;
    
    calcDigits(num, digits, digitNumber);
    for(size_t i=0;i<digitNumber-1;++i){
        if(digits[i]<digits[i+1]){
            IsGoodNum=0;
            break;
        }
    }
    return IsGoodNum;
}

