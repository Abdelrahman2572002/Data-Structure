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
using namespace std;

template <class T>

class Matrix
{
    private:
        T** matrix;
        int cols, rows;                                  //two dimensional matrix
    public:
        Matrix(int r, int c);
        Matrix(Matrix&);                            //copy constructor
        ~Matrix();                                //Destructor
        Matrix<T>transpose();                   //gets the transpose of the matrix

        Matrix<T>operator+( Matrix& mat);     //overloading the operator+
        Matrix<T>operator-( Matrix& mat);     //overloading the operator-
        Matrix<T>operator*( Matrix& mat);     //overloading the operator*

        friend istream& operator>>(istream& in, Matrix<T>& mat)
        {
            for (int i = 0; i < mat.rows; i++)
            {
                for (int j = 0; j < mat.cols; j++)
                {
                    cout << "Enter Value for the cell " << i << ", " << j << ": ";
                    in >> mat.matrix[i][j];

                }
            }
            return in;
        }

        friend ostream& operator<<(ostream& out,  Matrix<T> mat)
        {
            for (int i = 0; i < mat.rows; i++)
            {
                for (int j = 0; j < mat.cols; j++)
                    out << mat.matrix[i][j] << " ";

                out << endl;
            }
            return out;
        }
        void setDimensions(int r, int c);
        int getRows();
        int getCols();




};