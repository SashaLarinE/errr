#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<std::vector<int>> random_permutation(const std::vector<std::vector<int>>& matrix) {
    std::vector<std::vector<int>> permuted_matrix = matrix;

    std::vector<int> flattened_matrix;
    for (const auto& row : matrix) {
        flattened_matrix.insert(flattened_matrix.end(), row.begin(), row.end());
    }

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(flattened_matrix.begin(), flattened_matrix.end(), g);

    auto it = flattened_matrix.begin();
    for (auto& row : permuted_matrix) {
        for (auto& element : row) {
            element = *it;
            ++it;
        }
    }

    return permuted_matrix;
}

int main() {
    std::vector<std::vector<int>> matrix = { {1, 2, 3},
                                            {4, 5, 6},
                                            {7, 8, 9} };

    std::vector<std::vector<int>> permuted_matrix = random_permutation(matrix);

    for (const auto& row : permuted_matrix) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
