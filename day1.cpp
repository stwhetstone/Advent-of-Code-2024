#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

int main() {
    std::ifstream file("day1.txt");

    std::vector<int> left;
    std::vector<int> right;
    std::unordered_map<int, int> rightCount;

    std::string s = "";
    char c = ' ';
    int side = 0, tmp = 0, dist = 0, likeness = 0;

    while(file.get(c)) {
        if((c == ' ' && file.peek() != ' ') || c == '\n' || file.peek() == EOF) {
            tmp = stoi(s);
            if(side == 0) {
                left.push_back(tmp);
                side = 1;
            } else if(side == 1){ 
                right.push_back(tmp);
                rightCount[tmp] += 1;
                side = 0;
            }
            s = "";
        }
        if(c != '\n' && c != ' ') {
            s += c;
        }
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    for(int i = 0; i < left.size(); i++) {
        dist += abs(left[i] - right[i]);

        likeness += left[i] * rightCount[left[i]];
    }


    printf("%d %d\n", dist, likeness);

    file.close();

    return 0;
}