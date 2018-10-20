#include <iostream>
#include <vector>

using namespace std;

struct MatrixSizeStruct {
	int min_i;
	int min_j;
	int size;
};

vector<int> generate_input(int n, int seed) {
	vector<int> d(n * n);
	for (size_t i = 0; i < d.size(); ++i) {
		d[i] = seed;
		seed = ((long long)seed * 197 + 2017) & 987654;
	}
	return d;
}

long long get_hash(const vector<int>& d) {
	const long long MOD = 987654321054321LL;
	const long long MUL = 179;

	long long result_value = 0;
	for (size_t i = 0; i < d.size(); ++i)
		result_value = (result_value * MUL + d[i]) & MOD;
	return result_value;
}

void transpose(vector<int> &a, int size) {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < i; j++) {
			swap(a[i * size + j], a[j * size + i]);
		}
	}
}

vector<int> extract_submatrix(vector<int> a, MatrixSizeStruct m, int n) {
	vector<int> sub_m(m.size * m.size);
	for (int i = 0; i < m.size; i++) {
		for (int j = 0; j < m.size; j++) {
			sub_m[i * m.size + j] = a[(i + m.min_i) * n + j + m.min_j];
			//cout << sub_m[i * m.size + j] << " ";
		}
		//cout << endl;
	}
	return sub_m;
}

void print_vector_like_matrix(vector<int> v, int size) {
	for (int i = 0; i < size * size; i++) {
		if (i % size == 0) {
			cout << endl;
		}
		cout << v[i] << " ";
	}
	cout << endl;
}

void integrate_submatrix(vector<int> &m, vector<int> sub_m, MatrixSizeStruct sub_m_params, int n) {
	for (int i = 0; i < sub_m_params.size; i++) {
		for (int j = 0; j < sub_m_params.size; j++) {
			m[((i + sub_m_params.min_i) * n) + (j + sub_m_params.min_j)] = sub_m[i * sub_m_params.size + j];
		}
	}
}

int main()
{
	int n, seed;
	cin >> n >> seed;
	int k;
	cin >> k;
	MatrixSizeStruct* submatrix = new MatrixSizeStruct[k];
	for (int i = 0; i < k; i++) {
		cin >> submatrix[i].min_i >> submatrix[i].min_j >> submatrix[i].size;
	} 

	vector<int> result_matrix = generate_input(n, seed);
	vector<int> sub_m;
	for (int i = 0; i < k; i++) {
		//transpose(result_matrix, submatrix[i], n);
		sub_m = extract_submatrix(result_matrix, submatrix[i], n);
		transpose(sub_m, submatrix[i].size);
		//print_vector_like_matrix(sub_m, m_size.size);
		integrate_submatrix(result_matrix, sub_m, submatrix[i], n);
		sub_m.clear();
	}
	cout << get_hash(result_matrix);
	/*
	vector<int> test (4 * 4);
	for (int i = 0; i < 16; i++) {
		test[i] = i + 1;
	}

	print_vector_like_matrix(test, 4);

	cout << endl;

	MatrixSizeStruct m_size;
	m_size.min_i = 1;
	m_size.min_j = 1;
	m_size.size = 3;
	vector<int> sub_m = extract_submatrix(test, m_size, 4);
	transpose(sub_m, m_size.size);
	print_vector_like_matrix(sub_m, m_size.size);
	integrate_submatrix(test, sub_m, m_size, 4);
	print_vector_like_matrix(test, 4);*/
	
	return 0;
}