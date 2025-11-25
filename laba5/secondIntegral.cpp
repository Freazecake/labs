#include<cstdint>
#include<cmath>
#include"func.h"

void findApproximation_1_ForSecondIntegral(int64_t &n, double a, double b, double &s, int16_t num){
    double h;
    h=(b-a)/n;
    s=0;
    switch (num)
    {
    case 1:{
        for(size_t i=0;i<n;++i){
            double x=a+i*h;
            s+=exp(x)*sin(x);
        }
        break;
    }
    case 2:{
        for(size_t i=0;i<=n;++i){
            double x=a+i*h;
            s+=exp(x)*sin(x);
        }
        break;
    }
    case 3:{
        for(size_t i=0;i<n;++i){
            double x=a+i*h-h/2;
            s+=exp(x)*sin(x);
        }
        break;
    }
    }
    s*=h;
}

void findApproximation_2_ForSecondIntegral(int64_t &n, double a, double b, double &s){
    double s1{}, s2{};
    findApproximation_1_ForSecondIntegral(n, a, b, s1, 1);
    findApproximation_1_ForSecondIntegral(n, a, b, s2, 2);
    s=(s1+s2)/2;
}

void findApproximation_3_ForSecondIntegral(int64_t &n, double a, double b, double &s){
    double h;
    h=(b-a)/n;
    s=0;
    int16_t id{1};
    for(size_t i=0;i<n;++i){
        double x=a+i*h;
        s+=id*exp(x)*sin(x);
        if(i==n-2){
            id=1;
        }
        else if(i%2==0){
            id=4;
        }
        else{
            id=2;
        }
    }
    s*=h/3;
}

void findApproximation_ForSecondIntegral(int64_t &n, double a, double b, double &s, int16_t num){
    switch (num)
    {
    case 1:
        findApproximation_1_ForSecondIntegral(n, a, b, s, num);
        break;
    case 2:
        findApproximation_1_ForSecondIntegral(n, a, b, s, num);
        break;
    case 3:
        findApproximation_1_ForSecondIntegral(n, a, b, s, num);
        break;
    case 4:
        findApproximation_2_ForSecondIntegral(n, a, b, s);
        break;
    case 5:
        findApproximation_3_ForSecondIntegral(n, a, b, s);
        break;
    }
}

void findSolution_2(double a, double b, int16_t num){
    int64_t n{4};
    double e{getEpsilon()};
    double s1;
    findApproximation_ForSecondIntegral(n, a, b, s1, num);
    double s2;
    n*=2;
    findApproximation_ForSecondIntegral(n, a, b, s2, num);
    while(!(abs(s1-s2)<e)){
        s1=s2;
        n*=2;
        findApproximation_ForSecondIntegral(n, a, b, s2, num);
    }
    std::cout<<"The answer is "<<s2<<'\n';
}

void secondIntegral(){
    std::cout<<"Solving second integral\n";
    double a, b;
    enterBorders(a, b);
    int num = get_status();
    findSolution_2(a, b, num);
}
