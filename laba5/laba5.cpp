#include "firstIntegral.h"
#include "secondIntegral.h"
#include "thirdIntegral.h"

int main(){
    try{
        firstIntegral();
        secondIntegral();
        thirdIntegral();
    }catch(const char* msg){
        std::cout<<msg;
    }
}