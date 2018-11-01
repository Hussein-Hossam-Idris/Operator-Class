#include "Matrix.h"
#include <iostream>
#include <iomanip>

using namespace std;
///default constructor
matrix::matrix()
{}

///parametarized constructor
matrix::matrix(int r,int c,int num[])
{
    row=r;
    col = c;
    data = new int*[row];
    for(int i=0; i<row ; i++){data[i]=new int[col];}
    for(int i = 0 ; i<r ; i++){
        for(int j = 0 ; j<c; j++){
             data[i][j]=num[i * col + j];
        }
    }
}
///this is called when using the transpose function
matrix :: matrix (int r , int c , int **temp){
    //cout<<"inside transpose \n";
    data = new int *[r];
    for(int i = 0 ; i < r ; ++i)    data[i] = new int [c];

    row = r  , col = c;
    for(int i = 0 ; i<r ; ++i)
        for(int j = 0 ; j<c ; ++j   )       /// passing double pointer to data
            data[i][j] = temp[i][j];

}
///takes two objects and adds thier matrecies
matrix matrix :: operator+= (matrix omat){
    for(int i = 0 ; i<this->row ; i++){
        for(int j = 0 ; j<this->col ; j++){
            omat.data[i][j]= this->data[i][j] + omat.data[i][j];
        }
    }
    return omat;
}
///takes two objects and subtracts their matrecies
matrix matrix :: operator-= (matrix& omat){
    for(int i = 0 ; i<this->row ; i++){
        for(int j = 0 ; j<this->col ; j++){
            omat.data[i][j]= this->data[i][j]-omat.data[i][j];
        }
    }
    return omat;
}
///adds a anumberr to every element in an object's matrix
matrix matrix :: operator+= (int scalar){
    for(int i = 0 ; i<this->row ; i++){
        for(int j = 0 ; j<this->col ; j++){
            this->data[i][j]= this->data[i][j]+scalar;

        }
    }
    return *this;
}
///subtracts a number from every element in the object's matrix
matrix matrix :: operator-= (int scalar){
    for(int i = 0 ; i<this->row ; i++){
        for(int j = 0 ; j<this->col ; j++){
            this->data[i][j]= this->data[i][j]-scalar;

        }
    }
    return *this;
}
///adds 1 to every element in matrix
matrix matrix :: operator++ (){     /// ++a ,
    *this +=1;
    return *this;
}
///subtracts 1 from every element in matrix
matrix matrix :: operator-- (){
    *this-=1;
    return *this;
}
///allows the user to input a matrix created from an object
istream& operator>>(istream& in,matrix& omat){
    cin>>omat.row>>omat.col;
    omat.data = new int*[omat.row];
    for(int i=0; i<omat.row ; i++){omat.data[i]=new int[omat.col];}
    for(int i = 0 ; i<omat.row ; i++){
        for(int j = 0 ; j<omat.col; j++){
             cin>>omat.data[i][j];
        }
    }
    return in;

}
///allows the user to print the elements in an object's matrix
ostream& operator<< (ostream& out, matrix mat){
        for(int i = 0; i < mat.row; i++){
            for(int j = 0; j < mat.col; j++){
                cout << setw(5) << mat.data[i][j];
            }
            cout << endl;
        }
        return out;
    }

///returns true if 2 matecies are equal to each other
bool matrix :: operator== (matrix mat2){
        if (this->row == mat2.row && this->col == mat2.col){ /// to make sure that the two matrices have the same size.
            int condition = 0;
            for (int i = 0; i < this->row; i++){
                for (int j = 0; j < this->col; j++){
                    if (this->data[i][j] == mat2.data[i][j]){
                        condition++;
                    }
                }
            }
            if (condition != 0){
                return true;
            }
            else{
                return false;
            }

        }
        else {
            return false;
        }
    }

///makes sure 2 matrecies are not equal
bool matrix :: operator!= (matrix mat2){
        if (this->row == mat2.row && this->col == mat2.col){
            int condition = 0;
            for (int i = 0; i < this->row; i++){
                for (int j = 0; j < this->col; j++){
                    if (this->data[i][j] == mat2.data[i][j]){
                        condition++;
                    }
                }
            }
            if (condition != 0){
                return false;
            }
            else {
                return true;
            }
        }
        else{
            return true;
        }
    }
///returns true if rows of matrix equals the columns
bool matrix :: isSquare(){

    if (this->row == this->col){
            return true;
        }
        else{
            return false;
        }
}
/// returns true if the matrix is symmetric
bool matrix :: isSymetric(){

    if (isSquare()){
            if (*this == transpose()){
                return true;
            }
            else{
                return false;
            }
        }
}

///returns true if the matrix is an identity matrix
bool matrix :: isIdentity(){

    if (isSquare()){//checks if square
        for (int i = 0; i < this->row ; i++){
            for (int j = 0; j < this->col ; j++){//loops through the whole matrix
                    if(i == j){
                        if (this->data[i][j] != 1){//checks that main diagonal is all ones
                            return false;
                        }
                    }
                    if (i != j){
                        if (this->data[i][j]!= 0){//checks that all the other elements are zeros
                            return false;
                        }
                    }
            }

        }
    return true;
    }
    else{
        return false;
    }

}

///gets the transpose of the matrix
matrix matrix :: transpose(){
    cout<<"transposing \n ";
//    int temp[] = {};
    int ** temp = new int *[this->col];
    for(int i = 0 ; i < this->col  ; ++i)
        temp[i] = new int[this->row];
//    temp  = this->data;
//    matrix trans;
//    matrix(this->row, this->col, temp);
    for (int i = 0; i < this->row; i++){
            for(int j = 0; j < this->col; j++){
                    //cout<<"a"<<endl;

                temp[j][i] = this->data[j][i];
            }
        }
        for(int i = 0 ; i < this->col ; ++i){
        for(int j = 0 ; j < this->row ; ++j)
        cout<<temp[i][j]<<" ";

            cout<<endl;
        }
        matrix trans(this->col , this-> row , temp);
        return trans;


}
///adds the elements of 2 matrices
matrix matrix :: operator+  (matrix mat2)
{
    if ( ( this-> row == mat2.row ) && (this -> col == mat2.col) )
    {
        for(int i=0; i< this->row ; i++)
        {
            for(int j=0 ; j<this->col; j++ )
            {
                this -> data[i][j]=data[i][j]+mat2.data[i][j];

            }
        }

    }
    return *this;
}

///subtracts the elements of two matrices
matrix matrix ::operator-  ( matrix mat2)
{
    if (( this -> row== mat2.row ) && ( this-> col == mat2.col))
    {
        for(int i=0; i< this-> row ; i++)
        {
            for(int j=0 ; j<this-> col; j++ )
            {
                this-> data[i][j]=this-> data[i][j]-mat2.data[i][j];

            }
        }

    }
    return *this;
}
///gets the product of 2 matrices
matrix matrix :: operator*  ( matrix mat2)
{
    if ( this -> col== mat2.row )
    {
        for(int i=0; i< this -> row ; i++)
        {
            for(int j=0 ; j<this -> col; j++ )
            {
                for(int k=0; k< mat2.row; k++){
                mat2.data[i][j]+=this ->data[i][j]*mat2.data[i][j];} // Here to find the row and columns of the output we see row of mat1 and col of mat2

            }
        }

    }
        return mat2;
}

///adds a number to each element in a matrix
matrix matrix :: operator+  ( int scalar){

        for(int i=0; i< this->row ; i++)
        {
            for(int j=0 ; j<this->col; j++ )
            {
                this-> data[i][j]=this->data[i][j]+ scalar;

            }
        }
    return *this;
    }

///subtracts a number from every element of the matrix
matrix matrix ::operator-  ( int scalar){
     for(int i=0; i< this -> row ; i++)
        {
            for(int j=0 ; j<this ->col; j++ )
            {
                this -> data[i][j]=this -> data[i][j]- scalar;

            }
        }
return *this;

}

///gets the product of a each element in the matrix and a number
 matrix matrix :: operator*  ( int scalar){
     for(int i=0; i< this ->row ; i++)
        {
            for(int j=0 ; j<this -> col; j++ )
            {
                this -> data[i][j]=this ->data[i][j]* scalar;

            }
                }
return *this;
}


matrix::~matrix()
{
    //dtor
}
