#include "mat.hpp"
#include <array>
#include "doctest.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

namespace ariel
{
    string mat(int column, int row, char c, char r)
    {
        // test student3!
        int const min = 33;
        int const max = 126;

        // to check if the input numbers is legal- positive ones~~
        // we check if one of them if smaller that 0!
        if (row < 0 || column < 0)
        {
            // we check if the rows number is negative!
            if (row < 0 && column > 0)
            {
                std::__throw_invalid_argument("The row should be a positive number");
            }
            // if the row number not negative so we check the column!
            else if (row > 0 && column < 0)
            {
                std::__throw_invalid_argument("The column should be a positive number");
            }
            // else there's no one positive so both are negative
            else
            {
                std::__throw_invalid_argument("Both the row and column should be positive numbers!");
            }
        }
        // we check if the row and the column numbers are odd or even!
        if (row % 2 == 0 || column % 2 == 0)
        {
            // it thre is one of the numbers even so we first check
            // if the row number mod 2 is equall to 0 !
            if (row % 2 == 0 && column % 2 != 0)
            {
                std::__throw_invalid_argument("The row should be an odd number!");
            }
            // else it the row umber is an odd one so we check the column number
            else if (row % 2 != 0 && column % 2 == 0)
            {
                std::__throw_invalid_argument("The column should be an odd number!");
            }
            // else - if there's no one odd so both are even!
            else
            {
                std::__throw_invalid_argument("Both the row and column should be odd numbers!");
            }
        }
        // we check if the symbol are legal ones!- less than min!
        if (r < min || c < min)
        {
            if (r < min && c > min)
            {
                std::__throw_invalid_argument("Invalid symbol!! row symbol less than the min");
            }
            else if (r > min && c < min)
            {
                std::__throw_invalid_argument("Invalid symbol!! column symbol less than the min");
            }
            else
            {
                std::__throw_invalid_argument("Invalid symbol!! column and row symbol less than the min");
            }
        }
        // we check if the symbil are legal ones! - more than max!
        if (r > max || c > max)
        {
            if (r > max && c < max)
            {
                std::__throw_invalid_argument("Invalid symbol!! row symbol more than the max");
            }
            else if (r < max && c > max)
            {
                std::__throw_invalid_argument("Invalid symbol!! column symbol more than the max");
            }
            else
            {
                std::__throw_invalid_argument("Invalid symbol!! column and row symbol more than the max");
            }
        }

        // We start to fill the matrix1
        // [ 0 0 0 0 0 ]
        // [ 0 1 1 1 0 ]
        // [ 0 0 0 0 0 ]
        // to fill the first row.
        // we need start row point and start column point
        // more than that we need a end row point and end column point
        int StartRow = 0;                                        // in the row 0 and column j=0- euqall to zero
        int EndRow = row - 1;                                    // in the column 0 and row i ! equall to row-1
        int Startcolumn = 0;                                     // in the row i and column 0 ! equall to zero
        int Endcolumn = column - 1;                              // in th end of the matrix1 that row=i, column=j ! equall to column-1
        int cover = 0;                                           // cover is the frame that changes all the times
        vector<vector<char>> matrix1(row, vector<char>(column)); // we build a matrix1 with rows and column!
        cover = (row + 1) / 2;
        while (cover > 0)
        {
            for (int i = Startcolumn; i <= Endcolumn; i++)
            {
                for (int j = StartRow; j <= EndRow; j++)
                {
                    matrix1[StartRow][i] = c;
                    matrix1[j][Startcolumn] = c;
                    matrix1[EndRow][i] = c;
                    matrix1[j][Endcolumn] = c;
                }
            }
            StartRow = StartRow + 2;
            Startcolumn += 2;
            Endcolumn -= 2;
            EndRow -= 2;
            cover--;

            for (int i = 0; i < row - 1; i++)
            {
                for (int j = 0; j < column - 1; j++)
                {
                    if (matrix1[i][j] != c)
                    {
                        matrix1[i][j] = r;
                    }
                }
            }
        }
        string matrix;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                matrix += matrix1[i][j];
            }
            matrix += "\n";
        }

        return matrix;
    }

};