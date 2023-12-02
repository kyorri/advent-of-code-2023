#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void evalLine(std::string line, int& ID, int& r, int &g, int &b) {
    r = 0;
    g = 0;
    b = 0;

    std::string parse = line;
    int colonPos = parse.find(':');
    std::string strID = parse.substr(parse.find(' '), colonPos - parse.find(' '));
    ID = atoi(strID.c_str());

    std::replace(parse.begin(), parse.end(), ';', ',');
    std::vector<std::string> sequences;
    int lastPos = colonPos;
    while (lastPos < parse.size()) {
        int nextPos = parse.find(',', lastPos + 1);
        std::string seq = parse.substr(lastPos + 2, nextPos - lastPos - 2);
        lastPos = nextPos;
        sequences.push_back(seq);
    }
    
    for (std::string sequence : sequences) {
        int posR, posG, posB;
        int potR, potG, potB;
        posR = sequence.find("red");
        posG = sequence.find("green");
        posB = sequence.find("blue");
        if (posR != std::string::npos) {
            potR = atoi((sequence.substr(0, posR - 1)).c_str());
            r = std::max(r, potR);
        }
        if (posG != std::string::npos) {
            potG = atoi((sequence.substr(0, posG - 1)).c_str());
            g = std::max(g, potG);
        }
        if (posB != std::string::npos) {
            potB = atoi((sequence.substr(0, posB - 1)).c_str());
            b = std::max(b, potB);
        }
    }
}

int main()
{
    std::ifstream f("input_p1");
    std::ofstream o("output_p1");
    std::string line;
    int sumIDs = 0;
    // GameConfig init = GameConfig(12, 13, 14);
    if (f.is_open())
    {
        while (getline(f, line))
        {
            int lineID;
            int totalR = 0, totalG = 0, totalB = 0;
            evalLine(line, lineID, totalR, totalG, totalB);
            if (totalR > 12 || totalG > 13 || totalB > 14) {
                sumIDs += lineID;
                std::cout << lineID << " -> " << totalR << ", " << totalG << ", " << totalB << std::endl;
            }
        }
        f.close();
    }
    o << sumIDs << std::endl;
    o.close();
}