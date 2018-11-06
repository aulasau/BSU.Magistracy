/**
Задан массив A из n положительных чисел ai (1 ≤ ai ≤ 10 ^ 9). Необходимо уметь выполнять 4 вида запросов:

1 p v — присвоить p-му элементу массива значение v.
2 l r (l ≤ r) — прибавить единицу ко всем числам на отрезке [l..r].
3 l r (l ≤ r) — найти сумму четных чисел на отрезке [l..r].
4 l r (l ≤ r) — найти сумму нечетных чисел на отрезке [l..r].
Входные данные
Первая строка входных данных содержит два числа n и q (1 ≤ n, q ≤ 105) — размер массива и количество запросов.

Каждая из следующий q строк - запрос одного из 4 описанных выше видов.

Выходные данные
Для каждого запроса 3 и 4 вида выведите одно число — ответ на запрос.
Примеры
входные данные
4 9
1 2 3 4
3 1 4
2 1 3
4 1 4
3 1 4
1 4 10
3 1 3
3 2 4
4 1 3
4 2 4
выходные данные
6
3
10
6
14
3
3
входные данные
5 2
1 2 3 4 5
3 1 5
4 1 5
выходные данные
6
9
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct Operations {
	int number;
	int l;
	int r;
};



void build(int tree[], int a[], int v, int tleft, int tright) {
	if (tleft == tright)
		tree[v] = a[tleft];
	else {
		int tm = (tleft + tright) / 2;
		build(tree, a, v * 2, tleft, tm);
		build(tree, a, v * 2 + 1, tm + 1, tright);
	}
}

void update(int tree[], int v, int tleft, int tright, int l, int r, int add) {
	if (l > r)
		return;
	if (l == tleft && tright == r)
		tree[v] += add;
	else {
		int tm = (tleft + tright) / 2;
		update(tree, v * 2, tleft, tm, l, min(r, tm), add);
		update(tree, v * 2 + 1, tm + 1, tright, max(l, tm + 1), r, add);
	}
}

void set_new_value(int tree[], int v, int tleft, int tright, int pos, int new_val) {
	if (tleft == tright)
		tree[v] = new_val;
	else {
		int tm = (tleft + tright) / 2;
		if (pos <= tm)
			set_new_value(tree, v * 2, tleft, tm, pos, new_val);
		else
			set_new_value(tree, v * 2 + 1, tm + 1, tright, pos, new_val);
		tree[v] = tree[v * 2] + tree[v * 2 + 1];
	}
}

int get(int tree[], int v, int tleft, int tright, int pos) {
	if (tleft == tright)
		return tree[v];
	int tm = (tleft + tright) / 2;
	if (pos <= tm)
		return tree[v] + get(tree, v * 2, tleft, tm, pos);
	else
		return tree[v] + get(tree, v * 2 + 1, tm + 1, tright, pos);
}


int main()
{
	int n, q;
	cin >> n >> q;
	int * arr = new int[n];

	int tree_scope = 4 * n + 4;
	int * tree = new int[tree_scope];
	
	Operations *operations = new Operations[q];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		tree[i] = tree[i + 1] = tree[i + 2] = tree[i + 3] = 0;
	}

	for (int i = 0; i < n; i++) {
		cout << i << ": " << arr[i] << endl;
	}

	
	build(arr, tree, 1, 0, tree_scope);

	for (int i = 0; i < tree_scope; i++) {
		cout << i << ": " << tree[i] << endl;
	}

	/*for (int i = 0; i < q; ++) {
		cin >> operations[i].number >> operations[i].l >> operations[i].r;
	}*/

    
}
