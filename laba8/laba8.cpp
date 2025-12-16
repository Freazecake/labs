#include <iostream>
#include <string>
#include <vector>

bool isSeparator(const std::string &separators, char c)
{
    for (size_t i = 0; i < separators.length(); ++i)
    {
        if (separators[i] == c)
            return true;
    }
    return false;
}

bool isPalindrome(const std::string &word)
{
    if (word.empty())
        return false;
    
    size_t left = 0;
    size_t right = word.length() - 1;
    
    while (left < right)
    {
        if (word[left] != word[right])
            return false;
        left++;
        right--;
    }
    return true;
}

std::vector<std::string> extractWords(const std::string &str, const std::string &separators)
{
    std::vector<std::string> words;
    std::string currentWord;
    
    size_t n=str.length();
    for (size_t i = 0; i < n; ++i)
    {
        if (isSeparator(separators, str[i]))
        {
            if (!currentWord.empty())
            {
                words.push_back(currentWord);
                currentWord.clear();
            }
        }
        else
        {
            currentWord += str[i];
        }
    }
    
    if (!currentWord.empty())
    {
        words.push_back(currentWord);
    }
    
    return words;
}

int main()
{
    std::string separators;
    std::cout << "Enter separator symbols: ";
    std::getline(std::cin, separators);
    
    std::string input;
    std::cout << "Enter your string: ";
    std::getline(std::cin, input);
    
    if (input.empty())
    {
        std::cout << "The string is empty. Cannot solve the problem.\n";
        return 0;
    }
    
    std::vector<std::string> words = extractWords(input, separators);
    
    if (words.empty())
    {
        std::cout << "No words found in the string. Cannot solve the problem.\n";
        return 0;
    }
    
    std::vector<std::string> palindromes;
    size_t maxLength = 0;
    
    for (const auto &word : words)
    {
        if (isPalindrome(word))
        {
            if (word.length() > maxLength)
            {
                maxLength = word.length();
                palindromes.clear();
                palindromes.push_back(word);
            }
            else if (word.length() == maxLength)
            {
                bool found = false;
                for (const auto &p : palindromes)
                {
                    if (p == word)
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    palindromes.push_back(word);
                }
            }
        }
    }
    
    if (palindromes.empty())
    {
        std::cout << "No palindromes found in the string.\n";
        return 0;
    }
    
    std::string result;
    for (size_t i = 0; i < palindromes.size(); ++i)
    {
        result += palindromes[i];
        if (i < palindromes.size() - 1)
        {
            result += ",";
        }
    }
    
    std::cout << "Longest palindrome words: " << result << "\n";
    
    return 0;
}
