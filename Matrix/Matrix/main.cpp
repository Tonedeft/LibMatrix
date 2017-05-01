// Matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"


int main()
{
	Matrix<2, 2> mat2x2;
	mat2x2.set(0, 0, 5);
	mat2x2.set(0, 1, 6);
	mat2x2.set(1, 0, 7);
	mat2x2.set(1, 1, 8);
	mat2x2(0, 0) = 10;

	Matrix<2, 2> mat2x2_2;
	mat2x2_2.set(0, 0, 1);
	mat2x2_2.set(0, 1, 2);
	mat2x2_2.set(1, 0, 3);
	mat2x2_2.set(1, 1, 4);
	mat2x2_2.print();

	Matrix<2, 2> mat2x2_3;
	mat2x2_3 = mat2x2 + mat2x2_2;
	mat2x2_3.print();

	mat2x2 = mat2x2_3;
	mat2x2.print();
	mat2x2 = mat2x2;
	mat2x2.print();

	mat2x2 += mat2x2_2;
	mat2x2.print();
	mat2x2 -= mat2x2_2;
	mat2x2.print();
	return 0;
}
