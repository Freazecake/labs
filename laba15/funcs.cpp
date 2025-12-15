#include "sort.cpp"

void fileChecking(std::ifstream &fin)
{
    if (!fin.good())
    {
        throw "file doesnt exist";
    }
    if (!fin)
    {
        throw "file error";
    }
    if (fin.peek() == EOF)
    {
        throw "file is empty";
    }
}

int16_t getNum(std::string &str, int &j)
{
    size_t k{static_cast<size_t>(j)};
    int16_t num = std::stoi(str.substr(j), &k);
    j += k;
    ++j;
    return num;
}

std::string getStr(std::string &line, int &j)
{
    std::string str;
    while (j < line.size() && line[j] != ';')
    {
        str += line[j];
        ++j;
    }
    ++j;
    return str;
}

std::vector<int16_t> getVec(std::string &i)
{
    std::vector<int16_t> marks;
    size_t k{};
    while (k < i.size())
    {
        if (isdigit(i[k]))
        {
            size_t g{k};
            int mark = std::stoi(i.substr(k), &g);
            marks.push_back(static_cast<int16_t>(mark));
            k += g;
        }
        else
        {
            ++k;
        }
    }
    return marks;
}

struct Student
{
    int16_t course{};
    int16_t group{};
    std::string name{};
    std::string surname{};
    std::string otchestvo{};
    std::vector<int16_t> marks{};
    Student(){}

    Student(int16_t _course, int16_t _group, std::string _surname, std::string _name,
            std::string _otchestvo, std::vector<int16_t> _marks)
    {
        course = _course;
        group = _group;
        name = _name;
        surname = _surname;
        otchestvo = _otchestvo;
        marks = _marks;
    }
    ~Student()
    {
    }

    friend std::ifstream& operator>> (std::ifstream& fin, Student &a){
        std::string i;
        getline(fin, i);
        int j{};
        a.course = getNum(i, j);
        a.group = getNum(i, j);
        a.name = getStr(i, j);
        a.surname = getStr(i, j);
        a.otchestvo = getStr(i, j);
        i = i.substr(j);
        a.marks = getVec(i);
        return fin;
    }
    
    friend std::ofstream& operator<< (std::ofstream& fout, const Student &a){
        fout << "Course: " << a.course << '\n';
    fout << "Group: " << a.group << '\n';
    fout << "Surname:" << a.surname << '\n';
    fout << "Name:" << a.name << '\n';
    fout << "Otchestvo:" << a.otchestvo << '\n';
    fout << "Marks: ";
    for (auto j : a.marks)
    {
        fout << j << ' ';
    }
    fout << "\n\n";
    return fout;
    }

    friend std::istream& operator>> (std::istream& cin, Student &a){
        std::string i;
        getline(cin, i);
        int j{};
        a.course = getNum(i, j);
        a.group = getNum(i, j);
        a.name = getStr(i, j);
        a.surname = getStr(i, j);
        a.otchestvo = getStr(i, j);
        i = i.substr(j);
        a.marks = getVec(i);
        return cin;
    }

    friend std::ostream& operator<< (std::ostream& out, const Student &a){
        out << "Course: " << a.course << '\n';
    out << "Group: " << a.group << '\n';
    out << "Surname:" << a.surname << '\n';
    out << "Name:" << a.name << '\n';
    out << "Otchestvo:" << a.otchestvo << '\n';
    out << "Marks: ";
    for (auto j : a.marks)
    {
        out << j << ' ';
    }
    out << "\n\n";
    return out;
    }

    bool operator> (const Student& a){
        if(course > a.course)
            return true;
        else if(course < a.course)
            return false;
        else{
            if(group > a.group)
                return true;
            else if(group < a.group)
                return false;
            else{
                if(surname > a.surname)
                    return true;
                else if(surname < a.surname)
                    return false;
                else{
                    if(name > a.name)
                        return true;
                    else if(name < a.name)
                        return false;
                }
            }
        }
        return true;
    }

    bool operator< (const Student& a){
        if(course > a.course)
            return false;
        else if(course < a.course)
            return true;
        else{
            if(group > a.group)
                return false;
            else if(group < a.group)
                return true;
            else{
                if(surname > a.surname)
                    return false;
                else if(surname < a.surname)
                    return true;
                else{
                    if(name > a.name)
                        return false;
                    else if(name < a.name)
                        return true;
                }
            }
        }
        return false;
    }
};

int get_sort_method()
{
    int status;
    std::cout << "enter a way to sort array:\n\
    1-bubble sort\n\
    2-insert sort\n\
    3-selection sort\n\
    4-quick sort\n\
    5-merge sort\n\
    6-heap sort\n\
    7-counting sort(only for numbers from 0 to 99)\n\
    8-shell sort\n";
    std::cout << "your choice: ";
    std::cin >> status;
    return status;
}

int get_type_status()
{
    int status{};
    std::cout << "enter a vector type:\n"
                 "    1-int vector\n"
                 "    2-double vector\n"
                 "    3-char vector\n"
                 "    4-string vector\n"
                 "    5-student vector\n"
                 "your choice: ";
    if (!(std::cin >> status))
        throw "you need to enter a number\n";
    return status;
}

int get_status()
{
    int status{};
    std::cout << "enter input mode:\n"
                 "    1-keyboard input -> write to file\n"
                 "    2-random generate -> write to file\n"
                 "    3-read from file -> print to console\n"
                 "your choice: ";
    if (!(std::cin >> status))
        throw "you need to enter a number\n";
    return status;
}

int32_t enter_size()
{
    std::cout << "enter size of your vector: ";
    int32_t size{};
    if (!(std::cin >> size))
        throw "you need to enter a number";
    if (size <= 0)
        throw "size must be positive";
    return size;
}

bool my_isalpha(char ch)
{
    return std::isalpha(static_cast<unsigned char>(ch));
}

void getLines(std::vector<std::string> &lines, std::ifstream &fin)
{
    std::string str;
    while (std::getline(fin, str))
    {
        if (!str.empty())
            lines.push_back(str);
    }
    std::cout << "Lines readed: " << lines.size() << '\n';
}

template <typename T>
void print_array(const std::vector<T> &arr)
{
    for (const auto &v : arr)
        std::cout << v << '\n';
}

template <typename T>
void write_to_file(const std::vector<T> &arr, std::ofstream &fout)
{
    for (const auto &v : arr)
        fout << v << '\n';
}

int32_t enter_string_size(int32_t i)
{
    std::cout << "enter size of your string number " << i + 1 << ": ";
    int32_t size{};
    if (!(std::cin >> size))
        throw "you need to enter a number";
    if (size <= 0)
        throw "size must be positive";
    return size;
}

void enterBorders(int &a, int &b)
{
    std::cout << "enter borders: ";
    if (!(std::cin >> a >> b))
        throw "you need to enter numbers";
    if (a > b)
        std::swap(a, b);
}

template <typename T/*, typename = std::enable_if_t<std::is_arithmetic_v<T>>*/>
void keyboard_input(std::vector<T> &arr, int32_t size)
{
    arr.resize(size);
    std::cout << "enter your array elements:\n";
    for (int32_t i = 0; i < size; ++i)
    {
        if (!(std::cin >> arr[i]))
            throw "invalid input\n";
    }
}

void keyboard_input(std::vector<std::string> &arr, int32_t size)
{
    arr.resize(size);
    std::cout << "enter your array elements:\n";
    std::cin.ignore();
    for (int32_t i = 0; i < size; ++i)
        std::getline(std::cin, arr[i]);
}

template <typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
void new_rand_input(std::vector<T> &arr, int32_t size)
{
    arr.resize(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    int a{}, b{};
    enterBorders(a, b);
    std::uniform_int_distribution<> dist(a, b);
    for (int32_t i = 0; i < size; ++i)
        arr[i] = static_cast<T>(dist(gen));
}

void new_rand_input(std::vector<std::string> &arr, int32_t size)
{
    arr.resize(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 94);
    for (int32_t i = 0; i < size; ++i)
    {
        int32_t s_size = enter_string_size(i);
        for (int32_t j = 0; j < s_size; ++j)
            arr[i] += ' ' + dist(gen);
    }
}

std::string get_random_str(std::uniform_int_distribution<> dist, std::mt19937 gen){
    std::string temp;
    for (int32_t j = 0; j < 6; ++j)
            temp += ' ' + dist(gen);
    return temp;
}

void new_rand_input(std::vector<Student> &arr, int32_t size)
{
    arr.resize(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist1(0, 10);
    std::uniform_int_distribution<> dist2(0, 94);
    for (int32_t i = 0; i < size; ++i)
    {
        Student temp_student;
        temp_student.course = dist1(gen);
        temp_student.group = dist1(gen);
        temp_student.surname = get_random_str(dist2, gen);
        temp_student.name = get_random_str(dist2, gen);
        temp_student.otchestvo = get_random_str(dist2, gen);
        for(int32_t j=0;j<3;++j){
            temp_student.marks.push_back(dist1(gen));
        }
    }
}

void new_rand_input(std::vector<char> &arr, int32_t size)
{
    arr.resize(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 94);
    for (int32_t i = 0; i < size; ++i)
    {
        arr[i] += ' ' + dist(gen);
    }
}

template <typename T>
void file_input(std::vector<T> &arr, std::ifstream &fin)
{
    fileChecking(fin);
    T temp;
    while (fin >> temp)
    {
        arr.push_back(temp);
    }
}

void file_input(std::vector<std::string> &arr, std::ifstream &fin)
{
    fileChecking(fin);
    std::string temp;
    while (getline(fin, temp))
    {
        arr.push_back(temp);
    }
}

template<typename T>
void ArraySortMethod(std::vector<T>arr, int32_t size)
{
    switch (int status = get_sort_method(); status)
    {
    case 1:
        bubble_sort(arr, size);
        break;
    case 2:
        insert_sort(arr, size);
        break;
    case 3:
        selection_sort(arr, size);
        break;
    case 4:
        quick_sort(arr, 0, size - 1);
        break;
    case 5:
        merge_sort(arr, size);
        break;
    case 6:
        heap_sort(arr, size);
        break;
    case 7:
        counting_sort(arr, size);
        break;
    case 8:
        shell_sort(arr, size);
        break;
    default:
        throw "you entered wrong number!!!\n";
    }
}

template <typename T>
void ArrayInputMethod(std::vector<T> &arr)
{
    switch (int status = get_status(); status)
    {
    case 1:
    {
        int32_t size = enter_size();
        keyboard_input(arr, size);
        std::ofstream fout("out.txt");
        fout << "Unsorted vector:\n";
        write_to_file(arr, fout);
        fout << "----------------------------------------------------------\n";
        ArraySortMethod(arr, size);
        fout << "Sorted vector:\n";
        write_to_file(arr, fout);
        fout.close();
        break;
    }
    case 2:
    {
        int32_t size = enter_size();
        new_rand_input(arr, size);
        std::ofstream fout("out.txt");
        fout << "Unsorted vector:\n";
        write_to_file(arr, fout);
        fout << "----------------------------------------------------------\n";
        ArraySortMethod(arr, size);
        fout << "Sorted vector:\n";
        write_to_file(arr, fout);
        fout.close();
        break;
    }
    case 3:
    {
        std::ifstream fin("in.txt");
        file_input(arr, fin);
        fin.close();
        std::cout << "Unsorted vector:\n";
        print_array(arr);
        std::cout << "----------------------------------------------------------\n";
        int32_t size = arr.size();
        ArraySortMethod(arr, size);
        std::cout << "Sorted vector:\n";
        print_array(arr);
        break;
    }
    default:
        throw "unknown input mode";
    }
}