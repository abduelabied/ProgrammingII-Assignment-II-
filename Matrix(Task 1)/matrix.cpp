
#include "matrix.h"
#include<cassert>
Matrix::Matrix(){
    this->row = 0;
    this->col = 0;
}

Matrix::Matrix(Matrix& mat){
    this->col = mat.getCol();
    this->row = mat.getRow();
    this->data = new int*[this->row];
    for(int i = 0; i < this->row; ++i){
        this->data[i] = new int[this->col];
        for(int j = 0; j < this->col; ++j){
            this->data[i][j] = mat.at(i, j);
        }
    }
}

Matrix::Matrix(int row, int col, int num[]){
    this->row = row;
    this->col = col;
    this->data = new int*[this->row];
    for(int i = 0; i < this->row; ++i){
        this->data[i] = new int[this->col];
        for(int j = 0; j < this->col; ++j){
            this->data[i][j] = num[i*col+j];
        }
    }
}

void Matrix::initMat(int row, int col){
    this->row = row;
    this->col = col;
    this->data = new int*[this->row];
    for(int i = 0; i < this->row; ++i){
        this->data[i] = new int[this->col];
        for(int j = 0; j < this->col; ++j){
            this->data[i][j] = 0;
        }
    }
}

Matrix Matrix::operator=(const Matrix& mat){
    this->col = mat.getCol();
    this->row = mat.getRow();
    this->data = new int*[this->row];
    for(int i = 0; i < this->row; ++i){
        this->data[i] = new int[this->col];
        for(int j = 0; j < this->col; ++j){
            this->data[i][j] = mat.at(i, j);
        }
    }
}

Matrix Matrix::operator+(Matrix mat){
    assert(this->col == mat.getCol() && this->row == mat.getRow());
    Matrix newMat(mat);
    for(int i = 0; i < this->row; ++i){
        for(int j = 0; j < this->col; ++j){
            newMat.set(i, j, this->data[i][j] + mat.at(i, j));
        }
    }
    return newMat;
}
Matrix Matrix::operator-(Matrix mat){
    assert(this->col == mat.getCol() && this->row == mat.getRow());
    Matrix newMat(mat);
    for(int i=0; i < this->row; i++){
        for(int j=0; j < this->col; ++j){
            newMat.set(i, j, this->data[i][j] - mat.at(i,j));
        }
    }
    return newMat;
}
Matrix Matrix::operator*(Matrix mat){
    assert(this->col == mat.getRow() && this->row == mat.getCol());
    Matrix newMat(mat);
    for(int i=0; i < this->row; ++i){
        for(int j=0; j < mat.col; ++j){
                for(int k=0; k<this->col; ++k){
            newMat.set(i,j,this->data[i][k] * mat.at(k,j));
        }
    }
    }
    return newMat;
}
Matrix Matrix::operator+ (int scalar){
    for(int i=0; i<this->row; ++i){
        for(int j=0; j<this->col; ++j){
                this->data[i][j]+= scalar;
        }
    }
    return *this;
}
Matrix Matrix::operator- (int scalar){
    for(int i=0; i<this->row; ++i){
        for(int j=0; j<this->col; ++j){
                this->data[i][j]-= scalar;
        }
    }
    return *this;
}
Matrix Matrix::operator* (int scalar){
    for(int i=0; i<this->row; ++i){
        for(int j=0; j<this->col; ++j){
                this->data[i][j]*= scalar;
        }
    }
    return *this;
}


Matrix Matrix::operator+= (Matrix mat){
    assert(this->col == mat.getCol() && this->row == mat.getRow());
    for( int i=0; i< this->row; ++i){
        for(int j=0; j<this->col; ++j){
            this->data[i][j]+=mat.at(i,j);
        }
    }
    return *this;
}
Matrix Matrix::operator-= (Matrix mat){
    assert(this->col == mat.getCol() && this->row == mat.getRow());
    for( int i=0; i< this->row; ++i){
        for(int j=0; j<this->col; ++j){
            this->data[i][j]-=mat.at(i,j);
        }
    }
    return *this;

}
Matrix Matrix::operator+= (int scalar){
    for(int i=0; i<this->row; ++i){
        for(int j=0; j<this->col; ++j){
            this->data[i][j]+=scalar;
        }
    }
    return *this;

}
Matrix Matrix::operator-= (int scalar){
    for(int i=0; i<this->row; ++i){
        for(int j=0; j<this->col; ++j){
            this->data[i][j]-=scalar;
        }
    }
    return *this;

}
void Matrix::operator++ (){
    for(int i=0; i<this->row; ++i){
        for(int j=0; j<this->col; ++j){
            this->data[i][j]++;
        }
    }
}
void Matrix::operator-- (){
    for(int i=0; i<this->row; ++i){
        for(int j=0; j<this->col; ++j){
            this->data[i][j]--;
        }
    }
}
bool Matrix :: operator== (Matrix mat){
    assert(this->col == mat.getCol() && this->row == mat.getRow());
    bool z= true;
    for(int i = 0; i < this->row; ++i){
        for(int j =0; j < this->col; ++j){
            if(mat.at(i,j) != this->data[i][j]){
                z=false;
                break;
            }
        }
    }
    return z;
}
bool Matrix::operator!=(Matrix mat){
    assert(this->col == mat.getCol() && this->row == mat.getRow());
    bool z=true;
    for(int i=0; i < this->row; ++i ){
        for(int j=0; j < this->col; ++j){
            if(mat.at(i,j) == this->data[i][j]){
                z=false;
                break;
            }
        }
    }
    return z;
}
bool Matrix::isSquare   (){
    if(this->row == this->col){
            return true;
    }
    else if(this->row != this->col){
        return false;
    }

}
bool Matrix::isIdentity(){
    bool z=true;
    if(this->row == this->col){
        for(int i=0; i<this->row; ++i){
            for(int j=0; j<this->col; ++j){
                if((this->data[i][j] != 1) && (this->data[j][i] != 0)){
                    z=false;
                }
            }
        }
    }
    else if(this->row != this->col){
        z=false;
        cout<<"YOUR MATRIX IS NOT SQUARED"<<endl;
    }
    return z;
}
bool Matrix::isSymmetric (){
    bool z=true;
    if(this->row == this->col){
        for(int i=0; i<this->row; ++i){
            for(int j=0; j<this->col; ++j){
                if(this->data[i][j] != this->data[j][i] ){
                    z=false;
                }
            }
        }
    }
    else if(this->row != this->col){
        z=false;
        cout<<"YOUR MATRIX IS NOT SQUARED"<<endl;
    }
    return z;
}
    void Matrix ::transpose(){
        Matrix m;
        m.initMat(this->col,this->row);
        for(int i=0; i<this->row; ++i){
                for(int j=0; j<this->col; ++j){
                    m.set(j,i,this->data[i][j]);
        }
            delete[]this->data[i];
        }
        delete[]this->data;
        this->col=m.getCol();
        this->row=m.getRow();
        this->data = new int*[this->row];
        for(int i=0; i<this->row; ++i){
                this->data[i] = new int[this->row];
        for(int j=0; j<this->col; ++j){
            this->data[i][j] = m.at(i,j);
        }
        }
        }

ostream& operator<<(ostream& out, const Matrix& mat){
    for(int i=0; i<mat.getRow(); i++)
    {
        for(int j=0; j<mat.getCol(); j++)
        {
            out<<" "<<mat.at(i, j);
        }
        out<<endl;
    }
    return out;
}
istream& operator>> (istream& in, Matrix& mat){
    int r,c;
    cin>>r>>c;
    mat.initMat(r, c);

    for(int i=0; i<r;i++){
        for(int j=0; j<c; ++j){
            int x;
            cin>>x;
            mat.set(i,j,x);


        }
    }
    return in;
}

Matrix::~Matrix(){
    for(int i = 0; i < this->row; ++i){
        delete[] this->data[i];
    }
    delete[] this->data;
}

int Matrix::getCol()const{
    return this->col;
}

int Matrix::getRow()const{
    return this->row;
}

int Matrix::at(int i, int j)const{
    return this->data[i][j];
}
void Matrix::set(int i, int j, int val){
    this->data[i][j] = val;
}
