int get_status()
{
    int status;
    std::cout << "enter a way to enter array:\n\
    1-enter from keybord\n\
    2-enter random numbers\n\
    3-enter random numbers using the Mersenne vortex method\n";
    std::cout << "your choice: ";
    std::cin >> status;
    return status;
}

void keyboard_input(int *arr, int size)
{
    try{
        std::cout << "enter your array elements: ";
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
        if(!std::cin >> arr[i]){
            throw "invalid input\n";
        }
    }
    }
    catch(const char* msg){
        std::cout<<msg;
    }
}

void rand_input(int *arr, int size)
{
    srand(time(0));
    int a, b;
    std::cout << "enter borders: ";
    std::cin >> a >> b;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = a + rand() % (b - a + 1);
    }
}

void new_rand_input(int *arr, int size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    int a, b;
    std::cout << "enter borders: ";
    std::cin >> a >> b;
    std::uniform_int_distribution<> dist(a, b);
    for (int i = 0; i < size; ++i)
    {
        arr[i] = dist(gen);
    }
}

void print_array(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

int sum_even_number(int *arr, int size)
{
    int sum = 0;
    for (int i = 1; i < size; i += 2)
    {
        sum += arr[i];
    }
    return sum;
}

void ArrayInputMethod(int arr[100], int size, bool &IskeybordInput, bool &IsGoodNumber)
{
    switch (int status = get_status(); status)
    {
    case 1:
        keyboard_input(arr, size);
        IskeybordInput = 1;
        break;
    case 2:
        rand_input(arr, size);
        break;
    case 3:
        new_rand_input(arr, size);
        break;
    default:
        std::cout << "you entered wrong number!!!\n";
        IsGoodNumber = 0;
        break;
    }
}

int sum_between_zero_elements(int *arr, int size)
{
        int sum{}, num1{-1}, num2{-1};
    bool IsThereOneZero = 0;
    bool IsThereTwoZero = 0;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == 0)
        {
            num2 = i;
        }
        if (!IsThereOneZero)
        {
            num1=num2;
        }
        if (num2 != -1)
        {
            IsThereOneZero = 1;
        }
        if(num1 != -1 && num2 != -1){
            IsThereTwoZero = 1;
        }
    }
    if(!IsThereTwoZero){
        throw "there is no two zero\n";
    }
    for (int i = num1 + 1; i < num2; ++i)
    {
        sum += arr[i];
    }
    return sum;
}

void negative_sort(int *arr, int size)
{
    int *arr1 = new int [size];
    int *arr2 = new int [size];
    int j{}, k{};
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] < 0)
        {
            arr1[j] = arr[i];
            ++j;
        }
        else
        {
            arr2[k] = arr[i];
            ++k;
        }
    }
    std::cout << "sorted by negativity value array: ";
    for (int i = 0; i < j; ++i)
    {
        std::cout << arr1[i] << ' ';
    }
    for (int i = 0; i < k; ++i)
    {
        std::cout << arr2[i] << ' ';
    }
    std::cout << '\n';
    delete[] arr1;
    delete[] arr2;
}

int max_abs_element(int *arr, int size)
{
    int MaxElement = abs(arr[0]);
    for (int i = 0; i < size; ++i)
    {
        if (abs(arr[i]) > MaxElement)
        {
            MaxElement = arr[i];
        }
    }
    return MaxElement;
}

int sum_between_positive(int *arr, int size)
{
        bool q = 0;
    int a, b;
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] > 0)
        {
            if (!q)
            {
                a = arr[i];
                q = 1;
            }
            else
            {
                b = arr[i];
            }
        }
    }
    if(!q){
        throw "there is no positive elements";
    }
    int sum{};
    for (int i = a + 1; i < b; ++i)
    {
        sum += arr[i];
    }
    return sum;    
}