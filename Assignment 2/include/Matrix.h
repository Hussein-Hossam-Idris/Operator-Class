#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <iomanip>

using namespace std;

class matrix
{
    public:
        matrix();
        matrix(int r, int c, int num[]);
        //friend void enterMatrix();
        matrix operator+= (matrix omat); // mat1 changes & return
                                                       // new matrix with the sum
        matrix operator-= (matrix& omat); // mat1 changes + return new
                                                       // matrix with difference
        matrix operator+= (int scalar);   // change mat & return new matrix
        matrix operator-= (int scalar);   // change mat & return new matrix
        matrix operator++ ();            // Add 1 to each element ++mat
        matrix operator-- ();
        friend istream& operator>>(istream& in, matrix& omat);

        ///------------------------------------------

        friend ostream& operator<< (ostream& out, matrix mat);

        bool   operator== (matrix mat2);	// True if identical
        bool   operator!= (matrix mat2); 	// True if not same
        bool   isSquare   ();               // True if square matrix
        bool   isSymetric ();               // True if square and symmetric
        bool   isIdentity ();               // True if square and identity
        matrix transpose();

        ///------------------------------------------
        matrix operator+  (matrix mat2);
        matrix operator-  (matrix mat2);
        matrix operator*  (matrix mat2);
        matrix operator+  (int scalar);
        matrix operator-  (int scalar);
        matrix operator*  (int scalar);
        matrix (int r , int c , int **temp);



        virtual ~matrix();

    private:
        int** data;
        //int** mMat2;
        //int** mMat3;
        int row,col;
};

#endif // MATRIX_H
