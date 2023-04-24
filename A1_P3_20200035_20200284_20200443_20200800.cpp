// =============================================================
// Student: Ahmed Salman Fahmin
// StudentID: 20200035
// =============================================================
// Student: Abdelrahamn Ramdan AboElela
// StudentID: 20200284
// =============================================================
// Student: Mohamed Refaat Mohamed
// StudentID: 20200443
// =============================================================
// Student: Adel Tarek Mouneer
// StudentID: 20200800
// =============================================================

#include <iostream>
#include <./A1_P3_20200035_20200284_20200443_20200800>
#include<bits/stdc++.h>
using namespace std;


template <class T>
Matrix<T>::Matrix(int r, int c)
{
    rows = r;
    cols = c;
    matrix = new T* [rows];
    for(int i =0; i < rows; i++)
        matrix[i] = new T[cols];
}
template <class T>
Matrix<T>::Matrix(Matrix& mat)
{
    rows = mat.rows;
    cols = mat.cols;
    matrix = new T*[rows];
    for(int i =0; i < rows; i++)
        matrix[i] = new T[cols];
    for(int i =0; i < rows; i++)
    {
        for(int j =0; j < cols; j++)
            matrix[i][j] = mat.matrix[i][j];

    }
}

template <class T>
Matrix<T> Matrix<T>::transpose()
{
    Matrix<T> trans(cols, rows);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            trans.matrix[j][i]= matrix[i][j];
        }

;
    }
    return trans;
}

template <class T>
Matrix<T> Matrix<T>::operator+(Matrix<T>& mat)
{
    Matrix<T> addition(rows, cols);
    try
    {
        
        if(mat.cols==cols && mat.rows==rows)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    addition.matrix[i][j]= matrix[i][j] + mat.matrix[i][j];
                }

            }

        }else
        {
            throw -1; 
        }
    }
    catch(int)
    {
        cout << "Cannot Perform This Operation" << endl;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    addition.matrix[i][j]= NULL;
                }

            }
    }
    return addition;
}
template <class T>
Matrix<T> Matrix<T>::operator-(Matrix<T>& mat)
{
    Matrix<T> subtraction(rows, cols);
    try
    {
        
        if(mat.cols==cols && mat.rows==rows)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    subtraction.matrix[i][j]= matrix[i][j] - mat.matrix[i][j];
                }

            }

        }else
        {
            throw -1; 
        }
    }
    catch(int)
    {
        cout << "Cannot Perform This Operation" << endl;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    subtraction.matrix[i][j]= NULL;
                }

            }
    }
    return subtraction;
}

template <class T>
Matrix<T> Matrix<T>::operator*(Matrix<T>& mat)
{
    Matrix<T> multiplication(rows, mat.cols);
    try
    {
        
        if(cols==mat.rows )
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < mat.cols; j++)
                {
                        multiplication.matrix[i][j] =0;
                        for(int k =0; k < mat.rows;k++)
                        {
                            multiplication.matrix[i][j]+= matrix[i][k] * mat.matrix[k][j];

                        }
                }

            }

        }else
        {
            throw -1; 
        }
    }
    catch(int)
    {
        cout << "Cannot Perform This Operation" << endl;
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    multiplication.matrix[i][j]= NULL;
                }

            }
    }
    return multiplication;
}


template <class T>
Matrix<T>::~Matrix()
{
    for(int i = 0; i < rows; i++)
        delete [] matrix[i];
    delete [] matrix;
}


int main()
{
    int arrRows1;
    int arrCols1;
    int arrRows2;
    int arrCols2;
    int option;
    cout << "Enter Number of Rows for Array 1: ";
    cin >> arrRows1;
    cout << "Enter Number of Columnss for Array 1: ";
    cin >> arrCols1;
    cout << "Enter Number of Rows for Array 2: ";
    cin >> arrRows2;
    cout << "Enter Number of Columns for Array 2: ";
    cin >> arrCols2;
    Matrix<int> x1(arrRows1, arrCols1);
    Matrix<int> x2(arrRows2, arrCols2);
    cout << "Enter Data for Array 1: " << endl;
    cin >> x1;
    cout << "Array 1 that has been Submitted:" << endl;
    cout << x1 << endl;
    cout << "Enter Data for Array 1: " << endl;
    cin >> x2;
    cout << "Array 2 that has been Submitted:" << endl;
    cout << x2 << endl;
    while (1)          // menu of phone directory
    {
        cout<<"Choose one of the following options"<<endl;
        cout<<"1- Perform Matrix Addition"<<endl;
        cout<<"2- Perform Matrix Subtraction"<<endl;
        cout<<"3- Perform Matrix Multiplication"<<endl;
        cout<<"4- Matrix Transpose"<<endl;
        cout<<"5. Exit form this program"<<endl;
        cout << "option: ";
        cin>>option;
        if(option == 1)
            cout << x1+x2 << endl;
        else if(option == 2)
            cout << x1-x2 << endl;
        else if(option == 3)
            cout << x1*x2 << endl;
        else if(option == 4)
            cout << "Array 1 Transposed: \n" << x1.transpose() << endl
                << "Array 2 Transposed: \n" << x2.transpose() << endl;
        else if(option == 5)
            exit(0);
        else
            cout << "Invalid Option" << endl;

    }


    return 0;
}

