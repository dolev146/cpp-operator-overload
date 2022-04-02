#include "Matrix.hpp"
namespace zich
{

    Matrix::Matrix(const vector<double> &vec, const int row, const int column)
    {
        if (row <= 0 || column <= 0)
        {
            throw runtime_error("The size must be positive");
        }
        if (row * column != vec.size())
        {
            throw runtime_error("The size must match the size of the vector inserter");
        }

        this->vec = vec;
        this->row = row;
        this->column = column;
    }
    Matrix Matrix::operator+(const Matrix &matrix)
    {
        if (this->row != matrix.row || this->column != matrix.column)
        {
            throw runtime_error("The matrices should be the same size");
        }

        unsigned int length = (unsigned int)(row * column);
        vector<double> dataTemp;
        dataTemp.resize(length);
        for (unsigned int i = 0; i < length; i++)
        {
            dataTemp[i] = this->vec[i] + matrix.vec[i];
        }
        return Matrix(dataTemp, row, this->column);
    }
    Matrix &Matrix::operator++()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                vec[(unsigned int)(i * column + j)] += 1;
            }
        }
        return *this;
    }
    Matrix Matrix::operator++(const int flag)
    {
        Matrix copy = *this;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                vec[(unsigned int)(i * column + j)] += 1;
            }
        }
        return copy;
    }
    Matrix &Matrix::operator+=(const Matrix &matrix)
    {
        if (this->row != matrix.row || this->column != matrix.column)
        {
            throw runtime_error("The matrices should be the same size");
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                vec[(unsigned int)(i * column + j)] += matrix.vec[(unsigned int)(i * column + j)];
            }
        }
        return *this;
    }

    Matrix Matrix::operator-(const Matrix &matrix)
    {
        if (this->row != matrix.row || this->column != matrix.column)
        {
            throw runtime_error("The matrices should be the same size");
        }
        unsigned int length = (unsigned int)(row * column);
        vector<double> dataTemp;
        dataTemp.resize(length);
        for (unsigned int i = 0; i < length; i++)
        {
            dataTemp[i] = this->vec[i] - matrix.vec[i];
        }
        return Matrix(dataTemp, row, column);
    }
    Matrix &Matrix::operator--()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                vec[(unsigned int)(i * column + j)] -= 1;
            }
        }
        return *this;
    }
    Matrix Matrix::operator--(const int flag)
    {
        Matrix copy = *this;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                vec[(unsigned int)(i * column + j)] -= 1;
            }
        }
        return copy;
    }
    Matrix &Matrix::operator-=(const Matrix &matrix)
    {
        if (this->row != matrix.row || this->column != matrix.column)
        {
            throw runtime_error("The matrices should be the same size");
        }
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                vec[(unsigned int)(i * column + j)] -= matrix.vec[(unsigned int)(i * column + j)];
            }
        }
        return *this;
    }

    double Matrix::multiplication(const int thisRow, const Matrix &matrix, const int thisCol)
    {
        double sum = 0;
        for (int i = 0; i < this->column; i++)
        {
            sum += this->vec[(unsigned int)(this->column * thisRow + i)] * matrix.vec[(unsigned int)(matrix.column * i + thisCol)];
        }
        return sum;
    }
    Matrix Matrix::operator*(const Matrix &matrix)
    {
        if (this->column != matrix.row)
        {
            throw runtime_error("The sizes of the matrices do not match");
        }
        vector<double> n;
        Matrix newMatrix(n, row, matrix.column);
        for (int i = 0; i < newMatrix.row; i++)
        {
            for (int j = 0; j < newMatrix.column; j++)
            {
                newMatrix.vec[(unsigned int)(i * newMatrix.column + j)] = multiplication(i, matrix, j);
            }
        }
        return newMatrix;
    }
    Matrix Matrix::operator*(const double a)
    {
        Matrix newMatrix = *this;
        for (unsigned int i = 0; i < row; i++)
        {
            for (unsigned int j = 0; j < column; j++)
            {
                newMatrix.vec[(unsigned int)(column)*i + j] *= a;
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
            for (int j = 0; j < this->column; j++)
            {
                sum += vec[(unsigned int)(i * (this->column) + j)];
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
        if (this->row != matrix.row || this->column != matrix.column)
        {
            return false;
        }
        unsigned int size = (unsigned int)(row * column);
        for (unsigned int i = 0; i < size; i++)
        {
            if (this->vec[i] != matrix.vec[i])
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
            for (int j = 0; j < matrix.column; j++)
            {
                COUT << matrix.vec[(unsigned int)(matrix.column * i + j)] << " ";
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