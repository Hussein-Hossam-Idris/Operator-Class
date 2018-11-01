#include <iostream>
#include "Matrix.h"
///#include "Matrix.cpp"

using namespace std;

int main()
{
    /*int num1[]={1,2,3,4,5,6,7,8,9,10};
    int num2[]={11,22,33,44,55,66,77,88,99,100};
    int num3[]={12,23,34,45,56,67,78,89,91,200};*/

    matrix mat_1;
    matrix mat_2;

    cin >> mat_1;
    cout << mat_1;
    cin >> mat_2;
    cout << mat_2;
   // cout << mat_1;
    cout << mat_1*mat_2 << endl;


   // mat_2 = mat_1;

    //cout << mat_1;
//    cout << mat_2;

    //cout << mat_1.transpose()  << endl;
//    cout<<"a"<<endl;
//    cout << mat_1.isSquare()   << endl;
//    cout<<"b"<<endl;
//    cout << mat_1.isIdentity() << endl;
//    cout << mat_1.isSymetric() << endl;
////
//    cout << "is mat_1 equal to mat_2?: " << (mat_1 == mat_2) << endl;
//    cout << "is mat_1 not equal to mat_2?: " << (mat_1 != mat_2) << endl;

    return 0;
}
