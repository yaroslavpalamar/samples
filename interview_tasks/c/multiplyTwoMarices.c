#include <stdio.h>
#include <string.h>

#define R_C_SIZE 40

// Current function multiplies matrixes with size ROW_COLUMN_SIZE

void multiplyMatrices (int mat1[][R_C_SIZE], int mat2[][R_C_SIZE],
			int res[][R_C_SIZE], 
			int rowSize1, int colSize2)
{
	if (colSize2!=rowSize1) {
		printf("return because row size of first matrix not equal to column size of second matrix");
		return;
	}
	int iR, iC, iRC;
	for (iR=0; iR < rowSize1; iR++) {
		for (iC=0; iC<colSize2; iC++) {
			res[iR][iC]=0;
			for (iRC=0; iRC < rowSize1; ++iRC) {
				res[iR][iC] += mat1[iR][iRC]*mat2[iRC][iC];
			}
		}
	}
}

void printMatrix (int res[][R_C_SIZE], int rowSize, int colSize)
{
	int iR, iC;

        for (iR = 0; iR<rowSize;iR++) {
                for (iC = 0; iC < colSize; iC++)
                        printf("%d ", res[iR][iC]);
                printf("\n");
        }
	
}


int 
main(int argc, char** argv)
{
	int mat1[][R_C_SIZE] = {{1,1,1,1},
				{1,1,1,1},
				{1,1,1,1},
				{1,1,1,1}};
	
	int mat2[R_C_SIZE][R_C_SIZE];
        memcpy (mat2, mat1, sizeof(mat1));
	//memset (mat2, 0, sizeof(mat2));

	int mat3[][R_C_SIZE] = {  {1,1,1,1},
                                  {2,2,2,2},
                                  {3,3,3,3},
                                  {4,4,4,4}};
	int res[R_C_SIZE][R_C_SIZE];
	const int ACTUAL_RC_IZE = 4;
	multiplyMatrices(mat1, mat3, res, ACTUAL_RC_IZE, ACTUAL_RC_IZE);
	printf("Multiply two matrices below: \n");
	printf("Matrix1: \n");
	printMatrix(mat1, ACTUAL_RC_IZE, ACTUAL_RC_IZE);
	printf("Matrix2: \n");
	printMatrix(mat3, ACTUAL_RC_IZE, ACTUAL_RC_IZE);

	printf("Result of matrix multiplications is \n");
	printMatrix(res, ACTUAL_RC_IZE, ACTUAL_RC_IZE);
	
	return 0;
}

