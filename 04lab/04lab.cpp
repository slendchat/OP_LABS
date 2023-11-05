#include <iostream>

using namespace std;

struct matr
{
    int** matrix;
    int sizex;
    int sizey;
};

int **createMatrix(int x, int y)
{
    

    int** matrix = new int*[x];
    for (int i = 0; i < x; ++i) {
        matrix[i] = new int[y];
    }
    
    return matrix;
}

void fullFillMatrix(matr *matrix)
{
    for (int i = 0; i < matrix->sizex; i++)
    {
        for (int j = 0; j < matrix->sizey; j++)
        {
            int val;
            cout<<"Type val at ["<<i<<"]["<<j<<"]\n";
            cin>>val;
            matrix->matrix[i][j]=val;
        }
        
    }
}

void matrixPrint(matr *matrix)
{
    for (int i = 0; i < matrix->sizex; i++) {
        for (int j = 0; j < matrix->sizey; j++) {
            cout << matrix->matrix[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

void matrixPrintIntersection(matr *matrix,matr *matrixIntersection)
{
    for (int i = 0; i < matrixIntersection->sizex; i++) {
        for (int j = 0; j < matrixIntersection->sizey; j++) {
            if (matrixIntersection->matrix[i][j])
            {
                cout<<matrix->matrix[i][j]<<' ';
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

matr findMatrixIntersection(matr *matrix1,matr *matrix2)
{
    int maxSizeX =  (matrix1->sizex<matrix2->sizex)? matrix1->sizex:matrix1->sizex;
    int maxSizeY =  (matrix1->sizey<matrix2->sizey)? matrix1->sizey:matrix1->sizey;

    matr interMatrix;
    interMatrix.sizex = maxSizeX;
    interMatrix.sizey = maxSizeY;

    interMatrix.matrix = createMatrix(maxSizeX,maxSizeY);
    for (int i = 0; i < maxSizeX; i++)
    {
        for (int j = 0; j < maxSizeY; j++)
        {
            interMatrix.matrix[i][j] = (matrix1->matrix[i][j]==matrix2->matrix[i][j])?1:0;            
        }
        
    }
    return interMatrix;
}

int main()
{
    cout<<"Write first matrix size then second matrix size (rows,columns)\n";
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    matr matrix1;
    matrix1.sizex=x1;
    matrix1.sizey=y1;
    matr matrix2;
    matrix2.sizex=x2;
    matrix2.sizey=y2;
    matrix1.matrix = createMatrix(x1,y1);
    matrix2.matrix = createMatrix(x2,y2);

    fullFillMatrix(&matrix1);
    fullFillMatrix(&matrix2);

    matr matrixIntersection = findMatrixIntersection(&matrix1,&matrix2);

    matrixPrint(&matrix1);
    matrixPrint(&matrix2); 
    matrixPrint(&matrixIntersection);

    matrixPrintIntersection(&matrix1,&matrixIntersection);
}