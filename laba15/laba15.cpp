#include "funcs.cpp"

int main(){
    try
    {
        switch (int status = get_type_status(); status)
        {
        case 1:
        {
            std::vector<int32_t> arr;
            ArrayInputMethod(arr);
            break;
        }
        case 2:
        {
            std::vector<double> arr;
            ArrayInputMethod(arr);
            break;
        }
        case 3:
        {
            std::vector<char> arr;
            ArrayInputMethod(arr);
            break;
        }
        case 4:
        {
            std::vector<std::string> arr;
            ArrayInputMethod(arr);
            break;
        }
        case 5:
        {
            std::vector<Student> arr;
            ArrayInputMethod(arr);
            break;
        }
        default:
            std::cout << "unknown type\n";
        }
    }
    catch (const char *msg)
    {
        std::cout << msg;
    }
    return 0;
}