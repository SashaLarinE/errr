#include <iostream>
#include <vector>

class Matrix {
public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows, std::vector<int>(cols, 0));
    }

    ~Matrix() {}

    int& operator()(int row, int col) {
        return data[row][col];
    }

    Matrix operator+(const Matrix& other) {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result(i, j) = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result(i, j) += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    friend void printMatrix(const Matrix& matrix);

private:
    int rows;
    int cols;
    std::vector<std::vector<int>> data;
};

void printMatrix(const Matrix& matrix) {
    for (int i = 0; i < matrix.rows; ++i) {
        for (int j = 0; j < matrix.cols; ++j) {
            std::cout << matrix.data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    Matrix mat1(2, 2);
    mat1(0, 0) = 1;
    mat1(0, 1) = 2;
    mat1(1, 0) = 3;
    mat1(1, 1) = 4;

    Matrix mat2(2, 2);
    mat2(0, 0) = 5;
    mat2(0, 1) = 6;
    mat2(1, 0) = 7;
    mat2(1, 1) = 8;

    std::cout << "Matrix 1:" << std::endl;
    printMatrix(mat1);

    std::cout << "\nMatrix 2:" << std::endl;
    printMatrix(mat2);

    Matrix sum = mat1 + mat2;
    std::cout << "\nSum of matrices:" << std::endl;
    printMatrix(sum);

    Matrix product = mat1 * mat2;
    std::cout << "\nProduct of matrices:" << std::endl;
    printMatrix(product);

    return 0;
}
