#include <fstream>
#include <vector>
#include <unordered_map>

int main() {
    std::ifstream file("day1.txt");

    std::vector<int> left;
    std::vector<int> right;
    std::unordered_map<int, int> rightFrequency;

    int l = 0, r = 0, dist = 0, similarity = 0;

    while(file >> l >> r) {
        left.push_back(l);
        right.push_back(r);
        rightFrequency[r] += 1;
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    for(int i = 0; i < left.size(); i++) {
        dist += abs(left[i] - right[i]);

        similarity += left[i] * rightFrequency[left[i]];
    }

    printf("%d %d\n", dist, similarity);

    file.close();

    return 0;
}