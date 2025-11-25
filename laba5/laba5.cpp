#include"firstIntegral.cpp"
#include"secondIntegral.cpp"
#include"thirdIntegral.cpp"

int main(){
    try{
        firstIntegral();
        secondIntegral();
        thirdIntegral();
    }catch(const char* msg){
        std::cout<<msg;
    }
}