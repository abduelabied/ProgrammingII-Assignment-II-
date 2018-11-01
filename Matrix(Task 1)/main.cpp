#include "matrix.h"
#include <bits/stdc++.h>

int main(){
    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {13,233,3,4,5,6};
    int data3 [] = {10,100,10,100,10,100,10,100};
    int data4 [] = {1,2,3,2,3,1,3,1,2};
    Matrix mat4(3,3,data4);
    Matrix mat1(4, 2,data1);
    Matrix mat2(2, 3,data2);
    Matrix mat3(4, 2,data3);
   // cout<<mat1<<endl;
    //mat1.transpose();
    cout<<mat1.isSymmetric()<<endl;
    cout<<(mat1 == mat3)<<endl;
    bool z;
    z = (mat1 != mat3);
    cout<<z<<endl;
    mat1 += 4;
    mat1 += mat3;
    cout<<mat1<<endl;
   ++mat1;
   cout<<mat1<<endl;
   /* Matrix mat;
    cin >> mat;
    cout<<mat;*/
    //mat.transpose();
    //cout << mat;
    //cout<< (mat1* mat3);
    //Matrix z = mat;
    //cout << z;
    return 0;
}
