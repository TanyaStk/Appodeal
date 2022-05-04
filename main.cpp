#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::string fname = R"(C:\Users\tasik\CLionProjects\Appodeal\AppodealStack.csv)";
    std::fstream file(fname, std::ios::in);
    std::string line, word;
    int total_cost{0};
    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (line.find("Plane") != -1 || line.find("Train") != -1) {
                std::string str_cost = line.substr(line.find_first_of("£") + 2);
                std::stringstream ss(str_cost);
                std::vector<std::string> row;
                while (std::getline(ss, word, ',')) {
                    if (isdigit(word[0])) {
                        if (word.find('"') != -1) {
                            word.erase(word.end() - 1);
                            row[row.size() - 1] += word;
                        } else {
                            row.push_back(word);
                        }
                    }
                }
                for (const auto &elem: row) {
                    total_cost += std::stoi(elem);
                }
            }
        }
    }
    std::cout << "Total cost: " << total_cost;
    return 0;
}
