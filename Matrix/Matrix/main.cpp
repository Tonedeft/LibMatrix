// Matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"
#include "AugmentedMatrix.h"

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

int test_gauss()
{
	AugmentedMatrix<3, 4> A;
	A(0, 0) = 1;
	A(0, 1) = 2;
	A(0, 2) = 1;
	A(0, 3) = 1;
	A(1, 0) = 3;
	A(1, 1) = 1;
	A(1, 2) = 4;
	A(1, 3) = 0;
	A(2, 0) = 2;
	A(2, 1) = 2;
	A(2, 2) = 3;
	A(2, 3) = 2;
	A.print();
	A.gaussianElimination().print();


	AugmentedMatrix<3, 4> B;
	B(0, 0) = 1;
	B(0, 1) = 1;
	B(0, 2) = 1;
	B(0, 3) = 1;
	B(1, 0) = 4;
	B(1, 1) = 3;
	B(1, 2) = 5;
	B(1, 3) = 7;
	B(2, 0) = 2;
	B(2, 1) = 1;
	B(2, 2) = 3;
	B(2, 3) = 5;
	B.print();
	B.gaussianElimination().print();

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
	test_gauss();
	return 0;
}
