#include<iostream>
using namespace std;
class Matrix{
    private:
        int row, col;
        int** data;
    public:
        Matrix();
        Matrix(Matrix& mat);
        Matrix(int row, int col, int num[]);

        void initMat(int row, int col);
        Matrix operator+  (Matrix mat); // Add if same dimensions
        Matrix operator-  (Matrix mat); // Sub if same dimensions
        Matrix operator*  (Matrix mat); // Multi if col1 == row2
        Matrix operator+  (int scalar);  // Add a scalar
        Matrix operator-  (int scalar);  // Subtract a scalar
        Matrix operator*  (int scalar);  // Multiple by scalar
        Matrix operator+= (Matrix mat); // mat1 changes & return
        Matrix operator-= (Matrix mat); // mat1 changes + return new

        Matrix operator+= (int scalar);   // change mat & return new matrix
        Matrix operator-= (int scalar);   // change mat & return new matrix
        Matrix operator= (const Matrix& mat);   // change mat & return new matrix

        void   operator++ ();   	// Add 1 to each element ++mat
        void   operator-- ();    	// Sub 1 from each element --mat
        friend istream& operator>> (istream& in, Matrix& mat);

        friend ostream& operator<< (ostream& out, const Matrix& mat);
        bool   operator== (Matrix mat);	// True if identical
        bool   operator!= (Matrix mat); 	// True if not same
        bool   isSquare   ();  // True if square matrix
        bool   isSymmetric ();  // True if square and symmetric
        bool   isIdentity ();  // True if square and identity
        void transpose();
        int getCol() const;
        int getRow() const;
        int at(int i, int j) const;
        void set(int i, int j, int val);

        ~Matrix();
};
