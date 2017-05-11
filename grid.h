#ifndef _GRID_H_
#define _GRID_H_
#include <iostream>

/*******************************************************************************
 *
*******************************************************************************/
template <typename T>
class Grid {
	public:
		Grid(T default_value = 0);
		T& elem(int i, int j);
		void show();
		void grow(int new_n_rows, int new_n_cols);
		int max_occupied_i(int column);
	private:

		T *data;
		int row_size;
		int col_size;
		int n_rows;
		int n_cols;
		T default_value;
};
/*******************************************************************************
 *
*******************************************************************************/
template <typename T>
int Grid<T>::max_occupied_i(int column)
{
	int last_occupied_i = -1;
	for(int i = 0; i < n_rows; ++i)
	{
		if(elem(i,column) != default_value){
			last_occupied_i = i;
		}
	}
	return last_occupied_i;
}


/*******************************************************************************
 *
*******************************************************************************/
template<typename T>
Grid<T>::Grid(T _default_value)
{
	data = new T[4];
	n_rows = 0;
	col_size = 0;

	n_cols = 0;
	row_size = 0;
	default_value = _default_value;


}


/*******************************************************************************
 *
*******************************************************************************/
template<typename T>
T& Grid<T>::elem(int i, int j)
{
	if(i >= n_rows || j >= row_size){
		grow(
				(i >= n_rows ? i+1 : n_rows),
				(j >= n_cols ? j+1 : n_cols)
			);
	}

	if(!(i < n_rows && j < row_size)){
		throw std::exception();
	}

	return data[i * row_size + j];
}

/*******************************************************************************
 *
*******************************************************************************/
template<typename T>
void Grid<T>::show()
{
	for(int i = 0; i < n_rows; ++i){
		for(int j = 0; j < row_size; ++j){
			std::cout << elem(i,j) << " ";
		}
		std::cout << std::endl;
	}
}


/*******************************************************************************
 *
*******************************************************************************/
template<typename T>
void Grid<T>::grow(int new_n_rows, int new_n_cols)
{
	int new_row_size = new_n_cols;

	T *new_data = new T[new_n_rows * new_n_cols];
	for(int i = 0; i < new_n_rows; ++i){
		for(int j = 0; j < new_row_size; ++j){
			new_data[i * new_row_size + j] = (j < row_size && i < col_size ? elem(i,j) : default_value);
		}
	}

	n_rows = new_n_rows;
	n_cols = new_n_cols;

	row_size = n_cols;
	col_size = n_rows;

	delete data;
	data = new_data;
}

#ifdef TEST
int main(void)
{
	Grid<int> g;
	g.elem(0,0) = 33;
	g.elem(2,1) = 55;
	g.show();
	g.grow(4,4);
	g.show();
	g.grow(5,5);
	g.elem(0,4) = 99;
	g.show();
	g.elem(6,6) = 88;
	g.show();
	return 0;
}
#endif

#endif
