// Matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"

int test_multiply()
{
	Matrix<2, 1> A;
	Matrix<1, 2> B;

	A(0, 0) = 1;
	A(1, 0) = 2;
	B(0, 0) = 3;
	B(0, 1) = 4;
	A.print();
	B.print();

	Matrix<1, 1> BA = B*A;
	Matrix<2, 2> AB = A*B;
	(AB).print();
	(BA).print();

	return 0;
}

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

	test_multiply();
	return 0;
}
