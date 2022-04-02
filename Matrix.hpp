#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
namespace zich
{
    class Matrix
    {
    private:
        vector<double> data;
        int row;
        int col;
        double multiplication(const int raw, const Matrix &b, const int col);
        double sumMat() const;

    public:
        Matrix(const vector<double> dataTemp, const int rowTemp, const int colTemp);
        Matrix operator+(const Matrix &b);
        Matrix operator+(const double b);
        Matrix operator+(const int b);
        Matrix &operator++();
        Matrix operator++(const int flag);
        Matrix &operator+=(const Matrix &b);

        Matrix operator-(const Matrix &b);
        Matrix &operator--();
        Matrix operator--(const int flag);
        Matrix &operator-=(const Matrix &b);

        Matrix operator*(const Matrix &b);
        Matrix operator*(const double a);
        Matrix &operator*=(const Matrix &b);
        Matrix &operator*=(const double a);

        bool operator>(const Matrix &b);
        bool operator<(const Matrix &b);
        bool operator!=(const Matrix &b);
        bool operator==(const Matrix &b);
        bool operator>=(const Matrix &b);
        bool operator<=(const Matrix &b);

        friend ostream &operator<<(ostream &os, const Matrix &a);
        // friend istream &operator>>(istream &os, Matrix &mat);
        friend Matrix operator*(const double a, Matrix &b);
        friend Matrix operator-(Matrix &a);
    };

};