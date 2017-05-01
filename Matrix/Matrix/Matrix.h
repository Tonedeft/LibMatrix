#pragma once

#include <iostream>

typedef int MYTYPE;

template <int ROWS, int COLUMNS>
class Matrix
{

private:
	// TODO: Array of arrays? Would allow for double indexing.
	MYTYPE mat[ROWS][COLUMNS] = {};

public:
	Matrix() : mat()
	{
		memset(mat, 0, sizeof(mat));
	}
	Matrix(const Matrix& rhs) : mat()
	{
		memcpy(mat, rhs.mat, sizeof(mat));
	}
	virtual ~Matrix()
	{

	}

	// Setters
	void set(int row, int col, MYTYPE val)
	{
		// TODO: Validate valid row and column
		mat[row][col] = val;
	}
	MYTYPE& operator()(int row, int col)
	{
		// TODO: Validate valid row and column
		return mat[row][col];
	}

	void zero()
	{
		memset(mat, 0, sizeof(mat));
	}
	// TODO: Need Square Matrix to define "identity()"
	// TODO: Need symmetric matrix

	// Arithmetic operators
	Matrix& operator=(const Matrix& rhs)
	{
		// TODO: Ensure &rhs != this?
		memcpy(mat, rhs.mat, sizeof(mat));
		return *this;
	}
	Matrix& operator+=(const Matrix& rhs)
	{
		for (int i = 0; i < ROWS; ++i)
		{
			for (int j = 0; j < COLUMNS; ++j)
			{
				mat[i][j] += rhs.mat[i][j];
			}
		}
		return *this;
	}
	Matrix& operator-=(const Matrix& rhs)
	{
		for (int i = 0; i < ROWS; ++i)
		{
			for (int j = 0; j < COLUMNS; ++j)
			{
				mat[i][j] -= rhs.mat[i][j];
			}
		}
		return *this;
	}

	void print() const
	{
		printf("[");
		for (int i = 0; i < ROWS; ++i)
		{
			printf("[");
			for (int j = 0; j < COLUMNS; ++j)
			{
				printf("%3d, ", mat[i][j]);
			}
			printf("],\n ");
		}
		printf("]\n");
	}

	// Friend operators
	template <int ROWS, int COLUMNS>
	friend Matrix<ROWS, COLUMNS> operator+(const Matrix<ROWS, COLUMNS>& lhs, const Matrix<ROWS, COLUMNS>& rhs);
	template <int ROWS, int COLUMNS>
	friend Matrix<ROWS, COLUMNS> operator-(const Matrix<ROWS, COLUMNS>& lhs, const Matrix<ROWS, COLUMNS>& rhs);
	template <int ROWS, int MID, int COLUMNS>
	friend Matrix<ROWS, COLUMNS> operator*(const Matrix<ROWS, MID>& lhs, const Matrix<MID, COLUMNS>& rhs);
};

template <int ROWS, int COLUMNS>
Matrix<ROWS, COLUMNS> operator+(const Matrix<ROWS, COLUMNS>& lhs, const Matrix<ROWS, COLUMNS>& rhs)
{
	Matrix<ROWS, COLUMNS> result(lhs);
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLUMNS; ++j)
		{
			result.mat[i][j] += rhs.mat[i][j];
		}
	}
	return result;
}
template <int ROWS, int COLUMNS>
Matrix<ROWS, COLUMNS> operator-(const Matrix<ROWS, COLUMNS>& lhs, const Matrix<ROWS, COLUMNS>& rhs)
{
	Matrix<ROWS, COLUMNS> result(lhs);
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLUMNS; ++j)
		{
			result.mat[i][j] -= rhs.mat[i][j];
		}
	}
	return result;
}
template <int ROWS, int MID, int COLUMNS>
Matrix<ROWS, COLUMNS> operator*(const Matrix<ROWS, MID>& lhs, const Matrix<MID, COLUMNS>& rhs)
{
	Matrix<ROWS, COLUMNS> result;
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLUMNS; ++j)
		{
			MYTYPE rowaccum = 0;
			for (int k = 0; k < MID; ++k)
			{
				rowaccum += lhs.mat[i][k] * rhs.mat[k][j];
			}
			result.mat[i][j] = rowaccum;
		}
	}
	return result;
}