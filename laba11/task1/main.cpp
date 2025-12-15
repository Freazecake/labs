#include <vector>
#include <iostream>
#include <random>
#include <utility>

void enter_matrix_size(int &a, int &b){
    std::cout<<"enter matrix size: ";
    if(!(std::cin>>a>>b)){
        throw "you need to enter numbers";
    }
    if(a>100 || b>100 || a<0 || b<0){
        throw "this number should be positive and less then 100";
    }
}

void enter_bounds(int &a, int &b){
    std::cout<<"Enter value bounds: ";
    if(!(std::cin>>a>>b)){
        throw "you need to enter numbers: ";
    }
}

std::vector<std::vector<int>> random_input(std::vector<std::vector<int>> &matrix, int n, int m){
    std::random_device rd;
    std::mt19937 gen(rd());
    int a, b;
    enter_bounds(a, b);
    std::uniform_int_distribution<> dist(a, b);
    matrix.resize(n);
    for(int i=0;i<n;++i){
        matrix[i].resize(m);
        for(int j=0;j<m;++j){
            matrix[i][j]=dist(gen);
        }
    }
    return matrix;
}

std::pair<int, int> find_max(const std::vector<std::vector<int>> &matrix){
    int mx{matrix[0][0]}, x{}, y{};
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(matrix[i][j]>mx){
                mx=matrix[i][j];
                x=i;
                y=j;
            }
        }
    }
    std::cout<<"max element: "<<mx<<'\n';
    std::pair<int, int> result{x, y};
    return result;
}

void sortByRowsSum(std::vector<std::vector<int>> &matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    std::vector<int>rows_sum(n, 0);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            rows_sum[i]+=matrix[i][j];
        }
    }
    int mn;
    for (int i = 0; i < n; ++i)
    {
        mn = rows_sum[i];
        int k{i};
        for (int j = i; j < n; ++j)
        {
            if (rows_sum[j] < mn)
            {
                mn = rows_sum[j];
                k = j;
            }
        }
        std::swap(rows_sum[k], rows_sum[i]);
        std::swap(matrix[k], matrix[i]);
    }
}

void print_matrix(const std::vector<std::vector<int>> &matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    std::cout<<"Matrix:\n";
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            std::cout<<matrix[i][j]<<' ';
        }
        std::cout<<'\n';
    }
}

int main(){
    try{
        std::vector<std::vector<int>> matrix;
        int a, b;
        enter_matrix_size(a, b);
        matrix=random_input(matrix, a, b);
        print_matrix(matrix);
        std::pair<int, int> max_position = find_max(matrix);
        matrix.erase(matrix.begin()+max_position.first);
        --a;
        for(int i=0;i<a;++i){
            matrix[i].erase(matrix[i].begin()+max_position.second);
        }--b;
        sortByRowsSum(matrix);
        print_matrix(matrix);
    }catch(const char* msg){
        std::cout<<msg;
    }
}