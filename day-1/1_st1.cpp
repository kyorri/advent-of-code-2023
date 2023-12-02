#include <iostream>
#include <fstream>

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
        if (!foundR && isdigit((char)line[r]))
        {
            foundR = true;
            right = line[r] - '0';
        }
        l++;
        r--;
    }
    return left * 10 + right;
}

int main()
{
    std::ifstream f("input_p1");
    std::ofstream o("output_p1");
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
    o << sum;
    o.close();
}