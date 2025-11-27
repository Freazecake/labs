#include<iostream>
#include<vector>

bool IsSeparator(char* separators, char c){
    for(size_t i=0;separators[i]!='\0';++i){
        if(separators[i]==c)
            return 0;
    }
    return 1;
}

char* WordsReplacing(char* str, size_t id1, int word_size1, size_t id2, int word_size2){
    size_t i{};
}

int main(){
    char separators[300];
    std::cout<<"enter separatore symbols";
    std::cin.getline(separators, 300);
    char str[300];
    std::cout<<"enter your string";
    std::cin.getline(str,300);
    std::vector<int>size;
    int min{301}, max{-1};
    size_t min_id, max_id;
    for(size_t i=0;str[i]!='\0';++i){
        int word_size{};
        while(IsSeparator(separators, str[i])){
            ++word_size;
        }
        size.push_back(word_size);
        if(word_size<min){
            min=word_size;
            min_id=i-word_size;
        }   
        if(word_size>max){
            max=word_size;
            max_id=i-word_size;
        }
    }
    if(max_id<min_id){
        str=WordsReplacing(str, max_id, max, min_id, min);
    }
    else{
        str=WordsReplacing(str, min_id, min, max_id, max);
    }
}