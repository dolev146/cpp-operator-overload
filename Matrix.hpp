#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
namespace zich
{
    class Matrix
    {
    private:
        vector<double> vec;
        int row;
        int column;
        double multiplication(const int, const Matrix &matrix, const int);
        double sumMat() const;

    public:
        Matrix(const vector<double> &vec, const int row, const int column);
        Matrix operator+(const Matrix &matrix);
        Matrix operator+(const double);
        Matrix operator+(const int);
        Matrix &operator++();
        Matrix operator++(const int);
        Matrix &operator+=(const Matrix &matrix);

        Matrix operator-(const Matrix &matrix);
        Matrix operator-(const double);
        Matrix operator-(const int);
        Matrix &operator--();
        Matrix operator--(const int);
        Matrix &operator-=(const Matrix &matrix);

        Matrix operator*(const Matrix &matrix);
        Matrix operator*(const double);
        Matrix &operator*=(const Matrix &matrix);
        Matrix &operator*=(const double);

        bool operator>(const Matrix &matrix);
        bool operator<(const Matrix &matrix);
        bool operator!=(const Matrix &matrix);
        bool operator==(const Matrix &matrix);
        bool operator>=(const Matrix &matrix);
        bool operator<=(const Matrix &matrix);

        friend ostream &operator<<(ostream &COUT, const Matrix &matrix);
        friend Matrix operator*(const double, Matrix &matrix);
        friend Matrix operator-(Matrix &matrix);
        friend bool operator==(Matrix &matrix1, Matrix &matrix2);
        friend Matrix operator*(const Matrix &matrix1,const Matrix &matrix2);
    };

};