/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Dolev Dublon
 *
 * Date: 2022-03
 */

#include "doctest.h"
#include "Matrix.hpp"
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;
using namespace zich;

TEST_CASE("1")
{
    // identity check
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat(identity, 3, 3);
    Matrix mat2(identity, 3, 3);
    CHECK((mat == mat2));
}

TEST_CASE("+ operator for integer")
{
    // check + operator for adding intiger
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat(identity, 3, 3);
    mat = mat + int(1);
    std::vector<double> identity2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix mat2(identity2, 3, 3);
    CHECK((mat == mat2));
}
TEST_CASE("+ operator for double")
{
    // check + operator for adding intiger
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat(identity, 3, 3);
    mat = mat + double(1.3);
    std::vector<double> identity2 = {2.3, 0, 0, 0, 2, 0, 0, 0, 2.3};
    Matrix mat2(identity2, 3, 3);
    CHECK((mat == mat2));
}
TEST_CASE("+ operator for matrix")
{
    // check + operator for adding matrix
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat(identity, 3, 3);
    mat = mat + mat;
    std::vector<double> identity2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix mat2(identity2, 3, 3);
    CHECK((mat == mat2));
}
TEST_CASE("++ operator")
{
    // check ++ operator
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat(identity, 3, 3);
    mat++;
    std::vector<double> identity2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix mat2(identity2, 3, 3);
    CHECK((mat == mat2));
}
TEST_CASE("* operator int")
{
    // check * operator int
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat(identity, 3, 3);
    mat = mat * int(2);
    std::vector<double> identity2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix mat2(identity2, 3, 3);
    CHECK((mat == mat2));
}

TEST_CASE("check * operator double")
{
    // check * operator double
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat(identity, 3, 3);
    mat = mat * double(2.5);
    std::vector<double> identity2 = {2.5, 0, 0, 0, 2.5, 0, 0, 0, 2.5};
    Matrix mat2(identity2, 3, 3);
    CHECK((mat == mat2));
}

TEST_CASE("check * operator matrices")
{
    // check * operator matrices
    std::vector<double> identity2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix mat2(identity2, 3, 3);
    std::vector<double> identity3 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix mat3(identity3, 3, 3);
    Matrix mat6(identity3, 3, 3);
    mat6 = mat2 * mat3;
    std::vector<double> identity6 = {6, 0, 0, 0, 6, 0, 0, 0, 6};
    Matrix check_mat6(identity6, 3, 3);
    CHECK((mat2 * mat3 == check_mat6));
}

TEST_CASE("- operator for integer")
{
    // check - operator for adding intiger
    std::vector<double> identity2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix mat2(identity2, 3, 3);
    mat2 = mat2 - int(1);
    std::vector<double> identity1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat1(identity1, 3, 3);
    CHECK((mat1 == mat2));
}

TEST_CASE("check - operator for double")
{
    // check - operator for double
    std::vector<double> identity2 = {2.3, 0, 0, 0, 2.3, 0, 0, 0, 2.3};
    Matrix mat2(identity2, 3, 3);
    mat2 = mat2 - double(1.3);
    std::vector<double> identity1 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat1(identity1, 3, 3);
    CHECK((mat1 == mat2));
}

TEST_CASE("check - operator for subtract matrix")
{
    // check - operator for subtract matrix
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat(identity, 3, 3);
    mat = mat - mat;
    std::vector<double> zero = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    Matrix mat2(zero, 3, 3);
    CHECK((mat == mat2));
}

TEST_CASE("check -- operator")
{
    // check -- operator
    std::vector<double> identity2 = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix mat2(identity2, 3, 3);
    mat2--;
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat(identity, 3, 3);
    CHECK((mat == mat2));
}

TEST_CASE("check throw for size that doesnt match the cols number and rows number")
{
    // check throw for size that doesnt match the cols number and rows number
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    CHECK_THROWS(Matrix mat(identity, 4, 4));
}

TEST_CASE("check throw for size negative integer")
{
    // check throw for size negative integer
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    CHECK_THROWS(Matrix mat(identity, -4, 4));
}
TEST_CASE("check throw for size negative integer")
{
    // check throw for size negative integer
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    CHECK_THROWS(Matrix mat(identity, 4, -4));
}
TEST_CASE("// check throw for size negative integer")
{
    // check throw for size negative integer
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    CHECK_THROWS(Matrix mat(identity, -4, -4));
}
TEST_CASE("// check * operator matrices that is not defined")
{
    // check * operator matrices that is not defined because rows number in
    std::vector<double> vec1 = {2, 0, 0, 0, 2, 0, 0, 0, 2, 1, 2, 3};
    Matrix mat1(vec1, 3, 4);
    std::vector<double> vec2 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix mat2(vec2, 3, 3);
    CHECK_THROWS(mat1 * mat2);
}

TEST_CASE("// check * operator matrices for differant row numbers")
{
    // check * operator matrices for differant row numbers
    std::vector<double> vec2 = {2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0};
    Matrix mat2(vec2, 4, 3);
    std::vector<double> vec3 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix mat3(vec3, 3, 3);
    Matrix mat6(vec3, 3, 3);
    mat6 = mat2 * mat3;
    std::vector<double> vec6 = {6, 0, 0, 0, 6, 0, 0, 0, 6, 0, 0, 0};
    Matrix check_mat6(vec6, 4, 3);
    CHECK((mat6 == check_mat6));
}
TEST_CASE("// check + operator matrices that is not same size")
{
    // check + operator matrices that is not same size
    std::vector<double> vec1 = {2, 0, 0, 0, 2, 0, 0, 0, 2, 1, 2, 3};
    Matrix mat1(vec1, 3, 4);
    std::vector<double> vec2 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix mat2(vec2, 3, 3);
    CHECK_THROWS(mat1 + mat2);
}
TEST_CASE("// check - operator matrices that is not same size")
{
    // check - operator matrices that is not same size
    std::vector<double> vec1 = {2, 0, 0, 0, 2, 0, 0, 0, 2, 1, 2, 3};
    Matrix mat1(vec1, 3, 4);
    std::vector<double> vec2 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix mat2(vec2, 3, 3);
    CHECK_THROWS(mat1 - mat2);
}

TEST_CASE("// check + operator matrices that is not same size")
{
    // check + operator matrices that is not same size
    std::vector<double> vec1 = {2, 0, 0, 0, 2, 0, 0, 0, 2, 1, 2, 3};
    Matrix mat1(vec1, 4, 3);
    std::vector<double> vec2 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix mat2(vec2, 3, 3);
    CHECK_THROWS(mat1 + mat2);
}

TEST_CASE("// check - operator matrices that is not same size")
{
    // check - operator matrices that is not same size
    std::vector<double> vec1 = {2, 0, 0, 0, 2, 0, 0, 0, 2, 1, 2, 3};
    Matrix mat1(vec1, 4, 3);
    std::vector<double> vec2 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    Matrix mat2(vec2, 3, 3);
    CHECK_THROWS(mat1 - mat2);
}