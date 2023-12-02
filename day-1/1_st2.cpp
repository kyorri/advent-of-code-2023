#include <iostream>
#include <fstream>

struct lut
{
    std::string digit;
    int num;
};

lut digits[] = {
    {std::string("zero"), 0},
    {std::string("one"), 1},
    {std::string("two"), 2},
    {std::string("three"), 3},
    {std::string("four"), 4},
    {std::string("five"), 5},
    {std::string("six"), 6},
    {std::string("seven"), 7},
    {std::string("eight"), 8},
    {std::string("nine"), 9}};

int value(std::string line)
{
    int l = 0;
    int r = line.size() - 1;
    bool foundL = false, foundR = false;
    int left;
    int right;
    while (!foundL || !foundR)
    {
        if (!foundL && isdigit((char)line[l]))
        {
            foundL = true;
            left = line[l] - '0';
        }
        if (!foundL)
        {
            for (lut digit : digits)
            {
                int digit_len = digit.digit.size();
                std::string curr_digit = line.substr(l, digit_len);
                if (curr_digit == digit.digit)
                {
                    foundL = true;
                    left = digit.num;
                }
            }
        }
        if (!foundR && isdigit((char)line[r]))
        {
            foundR = true;
            right = line[r] - '0';
        }
        if (!foundR)
        {
            for (lut digit : digits)
            {
                int digit_len = digit.digit.size();
                std::string curr_digit = line.substr(r, digit_len);
                if (curr_digit == digit.digit)
                {
                    foundR = true;
                    right = digit.num;
                }
            }
        }
        l++;
        r--;
    }
    return left * 10 + right;
}

int main()
{
    std::ifstream f("input_p2");
    std::ofstream o("output_p2");
    std::string line;
    int sum = 0;
    if (f.is_open())
    {
        while (getline(f, line))
        {
            sum += value(line);
        }
        f.close();
    }
    o << sum << std::endl;
    o.close();
}