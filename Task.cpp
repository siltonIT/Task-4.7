#include "Matrix.h"

int main() {
	std::cout << "Write row size: " << std::endl;
	size_t row_size = 0;
	std::cin >> row_size;

	std::cout << "Write column size: " << std::endl;
	size_t col_size = 0;
	std::cin >> col_size;
	
	std::cout << "Write matix: " << std::endl;
	Matrix my_matrix(col_size, row_size);
	std::cin >> my_matrix;

	std::cout << solve(my_matrix);
}

Matrix solve(Matrix my_matrix) {
	Matrix res = my_matrix;
	for(size_t i = 0; i < 3; ++i)
		res += my_matrix.put_up_pow(2);

	return res;
}
