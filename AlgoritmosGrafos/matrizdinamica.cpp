#include "matrizdinamica.h"
// Codigo Extraido de http://mauricioavilesc.blogspot.com/2015/08/matriz-dinamica-en-c.html

MatrizDinamica::MatrizDinamica()
{

}

template <typename E>
class DynamicMatrix
{
private:
    int rows;
    int columns;
    E** matrix;

public:
    DynamicMatrix(int pRows, int pColumns) throw(runtime_error) {
        if (pRows <= 0 || pColumns <= 0) {
            throw runtime_error("Number of rows and columns must be greater than zero.");
        }
        rows = pRows;
        columns = pColumns;
        matrix = new E*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new E[columns];
        }
    }

    ~DynamicMatrix() {
        for (int i = 0; i < rows; i++) {
            delete [] matrix[i];
        }
        delete [] matrix;
    }

    E getValue(int pRow, int pColumn) throw(runtime_error) {
        if (pRow < 0 || pRow >= rows) {
            throw runtime_error("Invalid row.");
        }
        if (pColumn < 0 || pColumn >= columns) {
            throw runtime_error("Invalid column.");
        }
        return matrix[pRow][pColumn];
    }

    void setValue(int pRow, int pColumn, E value) throw(runtime_error) {
        if (pRow < 0 || pRow >= rows) {
            throw runtime_error("Invalid row.");
        }
        if (pColumn < 0 || pColumn >= columns) {
            throw runtime_error("Invalid column.");
        }
        matrix[pRow][pColumn] = value;
    }
    int getRows() {
        return rows;
    }
    int getColumns() {
        return columns;
    }
};

