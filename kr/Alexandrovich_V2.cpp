#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void checkInputFile(std::ifstream &fin)
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

void checkOutputFile(std::ofstream &fout)
{
    if (!fout)
    {
        throw "file error";
    }
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

void getBounds(std::string &bounds, int &a, int &b)
{
    size_t i = 0;
    a = std::stoi(bounds.substr(i), &i);
    ++i;
    b = std::stoi(bounds.substr(i), &i);
}

std::string itos(int num)
{
    std::string num_dig;
    while (num > 0)
    {
        int dig = num % 10;
        num /= 10;
        num_dig += dig + '0';
    }
    for (size_t i = 0; i < num_dig.size() / 2; ++i)
    {
        std::swap(num_dig[i], num_dig[num_dig.size() - i - 1]);
    }
    return num_dig;
}

void numberProcessing(std::string &line, size_t &j, int a, int b,
                      std::string &num_str, std::string &notnum_str, bool &num_not_written)
{
    size_t g;
    int num = std::stoi(line.substr(j), &g);
    j += g - 1;
    if (num > a && num < b)
    {
        num_str += itos(num);
        num_str += ' ';
        num_not_written = 0;
    }
    else
    {
        notnum_str += itos(num);
        num_not_written = 1;
    }
}

int main()
{
    try
    {
        std::ifstream fin("input.txt");
        checkInputFile(fin);
        std::ofstream fout("output.txt");
        checkOutputFile(fout);

        std::vector<std::string> lines;
        getLines(lines, fin);
        fin.close();

        std::string separators = lines[0];
        std::cout << "Separators are written\n";
        
        std::string bounds = lines[1];
        int a, b;
        getBounds(bounds, a, b);
        std::cout << "Bounds are written\n";

        size_t n = lines.size();
        for (size_t i = 2; i < n; ++i)
        {
            size_t m = lines[i].size();
            std::string num_str;
            std::string notnum_str;
            bool separator = 1, num_not_written = 1;
            for (size_t j = 0; j < m; ++j)
            {
                if (separators.find(lines[i][j]) != std::string::npos)
                {
                    notnum_str += lines[i][j];
                    num_not_written = 1;
                    separator = 1;
                    continue;
                }
                if (isdigit(lines[i][j]) && separator == 1)
                {
                    separator = 0;
                    numberProcessing(lines[i], j, a, b, num_str, notnum_str, num_not_written);
                }
                else if (num_not_written)
                {
                    num_not_written = 1;
                    separator = 0;
                    notnum_str += lines[i][j];
                }
            }
            if (!num_str.empty())
            {
                fout << num_str << "|| ";
            }
            fout << notnum_str << '\n';
        }
        std::cout << "All lines are processed\n";
        fout.close();
    }
    catch (const char *msg)
    {
        std::cout << msg;
    }
}