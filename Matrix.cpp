#include "Matrix.hpp"
namespace zich
{

    Matrix::Matrix(const vector<double> &dataTemp, const int rowTemp, const int colTemp)
    {
        if (rowTemp <= 0 || colTemp <= 0)
        {
            throw runtime_error("The size must be positive");
        }
        if (rowTemp * colTemp != dataTemp.size())
        {
            throw runtime_error("The size must match the size of the vector inserter");
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

        unsigned int length = (unsigned int)(row * col);
        vector<double> dataTemp;
        dataTemp.resize(length);
        for (unsigned int i = 0; i < length; i++)
        {
            dataTemp[i] = this->data[i] + matrix.data[i];
        }
        return Matrix(dataTemp, row, col);
    }
    Matrix &Matrix::operator++()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                data[(unsigned int)(i * col + j)] += 1;
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
                data[(unsigned int)(i * col + j)] += 1;
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
                data[(unsigned int)(i * col + j)] += matrix.data[(unsigned int)(i * col + j)];
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
        unsigned int length = (unsigned int)(row * col);
        vector<double> dataTemp;
        dataTemp.resize(length);
        for (unsigned int i = 0; i < length; i++)
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
                data[(unsigned int)(i * col + j)] -= 1;
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
                data[(unsigned int)(i * col + j)] -= 1;
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
                data[(unsigned int)(i * col + j)] -= matrix.data[(unsigned int)(i * col + j)];
            }
        }
        return *this;
    }

    double Matrix::multiplication(const int thisRow, const Matrix &matrix, const int thisCol)
    {
        double sum = 0;
        for (int i = 0; i < this->col; i++)
        {
            sum += this->data[(unsigned int)(this->col * thisRow + i)] * matrix.data[(unsigned int)(matrix.col * i + thisCol)];
        }
        return sum;
    }
    Matrix Matrix::operator*(const Matrix &matrix)
    {
        if (this->col != matrix.row)
        {
            throw runtime_error("The sizes of the matrices do not match");
        }
        vector<double> n;
        Matrix newMatrix(n, row, matrix.col);
        for (int i = 0; i < newMatrix.row; i++)
        {
            for (int j = 0; j < newMatrix.col; j++)
            {
                newMatrix.data[(unsigned int)(i * newMatrix.col + j)] = multiplication(i, matrix, j);
            }
        }
        return newMatrix;
    }
    Matrix Matrix::operator*(const double a)
    {
        Matrix newMatrix = *this;
        for (unsigned int i = 0; i < row; i++)
        {
            for (unsigned int j = 0; j < col; j++)
            {
                newMatrix.data[(unsigned int)(col)*i + j] *= a;
            }
        }
        return newMatrix;
    }
    Matrix &Matrix::operator*=(const Matrix &matrix)
    {
        *this = (*this * matrix);
        return *this;
    }
    Matrix &Matrix::operator*=(const double number)
    {
        *this = (*this * number);
        return *this;
    }
    double Matrix::sumMat() const
    {
        double sum = 0;
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                sum += data[(unsigned int)(i * (this->col) + j)];
            }
        }
        return sum;
    }
    bool Matrix::operator>(const Matrix &matrix)
    {
        return (*this).sumMat() > matrix.sumMat();
    }
    bool Matrix::operator<(const Matrix &matrix)
    {
        return (*this).sumMat() < matrix.sumMat();
    }
    bool Matrix::operator!=(const Matrix &matrix)
    {
        if (this->row != matrix.row || this->col != matrix.col)
        {
            return false;
        }
        unsigned int size = (unsigned int)(row * col);
        for (unsigned int i = 0; i < size; i++)
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
        return !((*this) != matrix);
    }
    bool Matrix::operator>=(const Matrix &matrix)
    {
        return ((*this) > matrix) || ((*this) == matrix);
    }
    bool Matrix::operator<=(const Matrix &matrix)
    {
        return ((*this) < matrix) || ((*this) == matrix);
    }

    ostream &operator<<(ostream &COUT, const Matrix &matrix)
    {
        for (int i = 0; i < matrix.row; i++)
        {
            COUT << '[';
            for (int j = 0; j < matrix.col; j++)
            {
                COUT << matrix.data[(unsigned int)(matrix.col * i + j)] << " ";
            }
            COUT << "]" << endl;
        }
        return COUT;
    }

    Matrix operator*(const double number, Matrix &matrix)
    {
        return matrix * number;
    }
    Matrix operator-(Matrix &matrix)
    {
        return matrix *= -1;
    }
    Matrix Matrix::operator-(const double number)
    {
        return *this;
    };
    Matrix Matrix::operator-(const int number)
    {
        return *this;
    };
    Matrix Matrix::operator+(const double number)
    {
        return *this;
    };
    Matrix Matrix::operator+(const int number)
    {
        return *this;
    };

    bool operator==(Matrix &matrix1, Matrix &matrix2){
        return true;
    };

    Matrix operator*(const Matrix &matrix1,const Matrix &matrix2){
        return matrix1;
    }

}