#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ifstream file("day2.txt");
    std::string in; 
    int cur = 0, last = 0, safeCount = 0, unsafeCount = 1;
    bool isSafe = true, up = false;

    while(std::getline(file, in)) {
        std::stringstream s(in);

        isSafe = true;
        up = false;
        unsafeCount = 1;

        s >> last >> cur;

        if(cur > last) {
            up = true;
        }

        do {
            if((cur < last && up) || (cur > last && !up) || abs(cur - last) > 3 || abs(cur - last) < 1) {
                isSafe = false; 
                break;
            }
            last = cur;
        } while(s >> cur);

        if(isSafe) {
            safeCount++;
        }
    }


    printf("%d\n", safeCount);

    file.close();

    return 0;
}