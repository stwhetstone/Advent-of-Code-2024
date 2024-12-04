#include <iostream>
#include <fstream>
#include <regex>

int main() {
    std::ifstream file("day3.txt");
    std::string s, t;
    int sum = 0, i = 0;
    int nums[] = {0, 0};

    std::regex inst("mul\\([0-9]{1,3},[0-9]{1,3}\\)");
    std::regex numr("[0-9]{1,3}");
    std::smatch match;
    std::smatch nummatch;

    while(std::getline(file, s)) {
        while(std::regex_search(s, match, inst)) {
            t = match.str();
            i = 0;

            while(std::regex_search(t, nummatch, numr)) {
                nums[i] =  stoi(nummatch.str());
                i++;
                t = nummatch.suffix().str();
            }
            sum += nums[0] * nums[1];
            s = match.suffix().str();
        }
    }

    printf("%d\n", sum);


    return 0;
}