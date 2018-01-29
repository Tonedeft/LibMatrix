#pragma once
#include "Matrix.h"

template <int ROWS, int COLUMNS>
class AugmentedMatrix :
	public Matrix<ROWS,COLUMNS>
{
public:
	AugmentedMatrix() : Matrix()
	{
	}

	AugmentedMatrix(const AugmentedMatrix& rhs) : Matrix(rhs)
	{
	}

	virtual ~AugmentedMatrix()
	{
	}

	// TODO: I can make this perform integer arithmetic instead of double.  
	AugmentedMatrix gaussianElimination() const
	{
		AugmentedMatrix result = *this;

		for (int i = 0; i < COLUMNS - 1; ++i)
		{
			//std::cout << "i = " << i << std::endl;
			// Loop through rows i+1 through ROWS
			for (int j = i + 1; j < ROWS; ++j)
			{
				//std::cout << "j = " << j << std::endl;
				// Find multiplier between row i and j
				double multiplier = (double)result.mat[j][i] / (double)result.mat[i][i];
				//std::cout << "Multiplier = " << result.mat[j][i] << "/" << result.mat[i][i] << " = " << multiplier << std::endl;

				// Subtract mult * row i from row i+1
				for (int k = i; k < COLUMNS; ++k)
				{
					//std::cout << "k = " << k << std::endl;
					//std::cout << "result(j,k) - multiplier * result(i,k) = " << result(j, k) << " - " << multiplier << " * " << result(i, k) << std::endl;
					result(j, k) = (double)result(j, k) - multiplier * result(i, k);
				}
			}

		}
		

		/*for (int i = 0; i < COLUMNS-1; ++i)
		{
			for (int j = i+1; j < ROWS-1; ++j)
			{
				double multiplier = mat[j][i] / mat[i][i];
				// Subtract n * row i from row j where n = this[j][i] / this[i][i]
				for (int k = j; k < COLUMNS; ++k)
				{
					result(j, k) = result(j, k) - multiplier*mat[j][k];
				}
			}
		}*/
		return result;
	}

};

