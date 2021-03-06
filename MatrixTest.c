#include <stdlib.h>
#include <stdio.h>

#include "Matrix.h"

int main() {
    Matrix* matrix = newMatrix(3, 3, (double []){
        1,2,3,
        4,5,6,
        7,8,9
    });
    Matrix* matrix2 = newMatrix(3, 1, (double []){
        1,
        2,
        3,
    });

    Matrix* res;

    res = newMatrix_mlt(matrix, matrix2);
    Matrix_show(res);
    deleteMatrix(res);

    Matrix_changeComponents(matrix, (double []){
        1,2,3,
        4,5,6,
        7,8,9
    });
    Matrix_changeComponents(matrix2, (double []){
        4,
        5,
        6
    });
    res = newMatrix_mlt(matrix, matrix2);Matrix_show(res);deleteMatrix(res);

    Matrix_changeComponents(matrix, (double []){
        1,2,3,
        4,5,6,
        7,8,9
    });
    Matrix_changeComponents(matrix2, (double []){
        7,
        8,
        9
    });
    res = newMatrix_mlt(matrix, matrix2);Matrix_show(res);deleteMatrix(res);

    deleteMatrix(matrix2);
    matrix2 = newMatrix(3, 3, (double []){
        1,4,7,
        2,5,8,
        3,6,9
    });
    res = newMatrix_mlt(matrix, matrix2);Matrix_show(res);deleteMatrix(res);

    deleteMatrix(matrix2);
    deleteMatrix(matrix);
    return 0;
}
