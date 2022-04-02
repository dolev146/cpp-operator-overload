#include "Matrix.hpp"
namespace zich
{

    Matrix::Matrix(const vector<double> dataTemp, const int rowTemp, const int colTemp)
    {
        if (rowTemp <= 0 || colTemp <= 0)
        {
            throw runtime_error("The size must be positive");
        }

        this->data = dataTemp;
        row = rowTemp;
        col = colTemp;
    }
    Matrix Matrix::operator+(const Matrix &matrix)
    {
        if (this->row != matrix.row || this->col != matrix.col)
        {
            throw runtime_error("The matrices should be the same size");
        }

        size_t length = (size_t)(row * col);
        vector<double> dataTemp;
        dataTemp.resize(length);
        for (size_t i = 0; i < length; i++)
        {
            dataTemp[i] = this->data[i] + matrix.data[i];
        }
        return Matrix(dataTemp, row, col);
    }
    Matrix Matrix::operator+(const double b)
    {
        return *this;
    }
    Matrix Matrix::operator+(const int b)
    {
        return *this;
    }
    Matrix &Matrix::operator++()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                data[(size_t)(i * col + j)] += 1;
            }
        }
        return *this;
    }
    Matrix Matrix::operator++(const int flag)
    {
        Matrix copy = *this;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                data[(size_t)(i * col + j)] += 1;
            }
        }
        return copy;
    }
    Matrix &Matrix::operator+=(const Matrix &matrix)
    {
        if (this->row != matrix.row || this->col != matrix.col)
        {
            throw runtime_error("The matrices should be the same size");
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                data[(size_t)(i * col + j)] += matrix.data[(size_t)(i * col + j)];
            }
        }
        return *this;
    }

    Matrix Matrix::operator-(const Matrix &matrix)
    {
        if (this->row != matrix.row || this->col != matrix.col)
        {
            throw runtime_error("The matrices should be the same size");
        }
        size_t length = (size_t)(row * col);
        vector<double> dataTemp;
        dataTemp.resize(length);
        for (size_t i = 0; i < length; i++)
        {
            dataTemp[i] = this->data[i] - matrix.data[i];
        }
        return Matrix(dataTemp, row, col);
    }
    Matrix &Matrix::operator--()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                data[(size_t)(i * col + j)] -= 1;
            }
        }
        return *this;
    }
    Matrix Matrix::operator--(const int flag)
    {
        Matrix copy = *this;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                data[(size_t)(i * col + j)] -= 1;
            }
        }
        return copy;
    }
    Matrix &Matrix::operator-=(const Matrix &matrix)
    {
        if (this->row != matrix.row || this->col != matrix.col)
        {
            throw runtime_error("The matrices should be the same size");
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                data[(size_t)(i * col + j)] -= matrix.data[(size_t)(i * col + j)];
            }
        }
        return *this;
    }
    double Matrix::multiplication(const int thisRow, const Matrix &matrix, const int thisCol)
    {
        double sum = 0;
        for (int i = 0; i < this->col; i++)
        {
            sum += this->data[(size_t)(this->col * thisRow + i)] * matrix.data[(size_t)(matrix.col * i + thisCol)];
        }
        return sum;
    }
    Matrix Matrix::operator*(const Matrix &matrix)
    {
        // if (this->col != matrix.row)
        // {
        //     throw runtime_error("The sizes of the matrices do not match");
        // }
        // vector<double> n;
        // Matrix newMatrix(n, row, matrix.col);
        // for (int i = 0; i < newMatrix.row; i++)
        // {
        //     for (int j = 0; j < newMatrix.col; j++)
        //     {
        //         newMatrix.data[(size_t)(i * newMatrix.col + j)] = multiplication(i, matrix, j);
        //     }
        // }
        return matrix;
    }
    Matrix Matrix::operator*(const double a)
    {
        Matrix newMatrix = *this;
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                newMatrix.data[(size_t)(col)*i + j] *= a;
            }
        }
        return newMatrix;
    }
    Matrix &Matrix::operator*=(const Matrix &matrix)
    {
        *this = (*this * matrix);
        return *this;
    }
    Matrix &Matrix::operator*=(const double a)
    {
        *this = (*this * a);
        return *this;
    }
    double Matrix::sumMat() const
    {
        double sum = 0;
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                sum += data[(size_t)(i * (this->col) + j)];
            }
        }
        return sum;
    }

    bool Matrix::operator>(const Matrix &b)
    {
        return (*this).sumMat() > b.sumMat();
    }
    bool Matrix::operator<(const Matrix &b)
    {
        return (*this).sumMat() < b.sumMat();
    }
    bool Matrix::operator!=(const Matrix &matrix)
    {
        if (this->row != matrix.row || this->col != matrix.col)
        {
            return false;
        }
        size_t size = (size_t)(row * col);
        for (size_t i = 0; i < size; i++)
        {
            if (this->data[i] != matrix.data[i])
            {
                return true;
            }
        }
        return false;
    }
    bool Matrix::operator==(const Matrix &matrix)
    {

        return true;
    }
    bool Matrix::operator>=(const Matrix &matrix)
    {
        return ((*this) > matrix) || ((*this) == matrix);
    }
    bool Matrix::operator<=(const Matrix &matrix)
    {
        return ((*this) < matrix) || ((*this) == matrix);
    }

    ostream &operator<<(ostream &os, const Matrix &matrix)
    {
        for (int i = 0; i < matrix.row; i++)
        {
            os << '[';
            for (int j = 0; j < matrix.col; j++)
            {
                os << matrix.data[(size_t)(matrix.col * i + j)] << " ";
            }
            os << "]" << endl;
        }
        return os;
    }
    // istream &operator>>(istream &os, Matrix &mat)
    // {

    // }
    Matrix operator*(const double a, Matrix &matrix)
    {
        return matrix * a;
    }

    Matrix operator-(Matrix &a)
    {
        return a *= -1;
    }

}