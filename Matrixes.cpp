#include "Matrixes.hpp"
double Dense_matrix::operator()(unsigned int i, unsigned int j) const
{
    return matrix[cols*j+i];
}
unsigned int Dense_matrix::col(){
    return cols;
}
unsigned int Dense_matrix::row(){
   return rows;
}
void Dense_matrix::show(){
    for (unsigned int j =0; j<rows; j++){
        for(unsigned int i = 0; i<cols; i++){
            std::cout<<(*this)(i, j)<<" ";
        }
        std::cout<<std::endl;
    }
}
std::vector<double> Dense_matrix::operator* (const std::vector<double>& b) const{
    std::vector<double> x(this->rows);
    for (unsigned int j = 0; j<this->rows;j++){
        x[j] = 0;
        for(unsigned int i = 0; i<this->cols; i++)
        {
            x[j] += (*this)(i, j)*b[i];
        }
    }

    return x;
}
Dense_matrix Dense_matrix::operator+ (const Dense_matrix& b) const{
    std::vector<double> c(rows*cols);
    for (int i = 0; i<cols; i++){
        for (int j = 0; j<rows; j++){
            c[i*rows+j] = (*this)(j, i) + b(j, i);
        }
    }
    Dense_matrix C(c, this->rows, this->cols);
    return C;
};
Dense_matrix Dense_matrix::operator- (const Dense_matrix& b) const{
    std::vector<double> c(rows*cols);
    for (int i = 0; i<cols; i++){
        for (int j = 0; j<rows; j++){
            c[i*rows+j] = (*this)(j, i) - b(j, i);
        }
    }
    Dense_matrix C(c, this->rows, this->cols);
    return C;
}
Dense_matrix Dense_matrix::operator*(const double& a) const {
    std::vector<double> c(rows*cols);
    for (int i = 0; i<cols; i++){
        for (int j = 0; j<rows; j++){
            c[i*rows+j] = (*this)(j, i)*a;
        }
    }
    Dense_matrix C(c, this->rows, this->cols);
    return C;
}



std::vector<double> CSRMatrix::operator* (const std::vector<double>& b) const {
    std::vector<double> x(this->rows);
    for (unsigned int j = 0; j<this->rows;j++){
        x[j] = 0;
        for(unsigned int i = 0; i<this->cols; i++)
        {
            x[j] += (*this)(i, j)*b[i];
        }
    };
    return x;
}
double CSRMatrix::operator()(unsigned int i, unsigned int j) const{
    double x;
    bool flag = true;
    unsigned int row_end, row_start;
    row_start = row[i];
    row_end = row[i+1];
    for (unsigned k = row_start; k<= row_end; k++){
        if (col[k]==j && flag){
            x = values[j];
            flag = false;
        }
    }
    if(flag){
        x = 0;
    }
    return x;
}
CSRMatrix CSRMatrix::operator* (const double& a) const{
    std::vector<double> tmp(values.size());
    for (int i=0; i< values.size();i++){
        tmp[i] = values[i] * a;
    }
    CSRMatrix C(tmp, row, col, cols, rows);
    return C;
}