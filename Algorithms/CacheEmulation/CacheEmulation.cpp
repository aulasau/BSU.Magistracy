﻿/** 
Необходимо проэмулировать работу k-way полностью ассоциативного кэша размера cacheSize и с размером кэш-линии lineSize.

Для выполнения эмуляции будем:

Обрабатывать адреса памяти один за одним, при этом считая, что каждый раз у нас запрашивается только один байт из памяти по данному адресу.
Изначально весь кэш пустует.
Если случается CACHE_MISS и необходимо вытеснить одну из линий в кэше, то будем вытеснять самую давно не используемую линию. 
Т.е. в момент записи линии и в момент CACHE_HIT ее внутренний счетчик времени выставляется в текущий момент.
Для определения номера кэш-линии необходимо разделить address на lineSize без остатка.
Для определения номера набора в кэше необходимо вычислить остаток от деления номера кэш-линии на количество кэш-линий в одном банке памяти в кэше.

Входные данные
В первой строке записаны четыре целых числа cacheSize, associativity, lineSize и n 
(2^15 ≤ cacheSize ≤ 2^24, associativity = {4,6,8,12,16}, lineSize = {64,128}, 1 ≤ n ≤ 100000).

Вторая строка содержит n целых чисел, последовательность адресов, к которым выполняется обращение.

Гарантируется:

cacheSize = associativity·2^k, для некоторого натурального k.
Все адреса в памяти из диапазона [0;2^30 - 1].

Выходные данные
Выведите два числа, количество обращений к памяти, которые завершились CACHE_HIT и CACHE_MISS соответственно.

Примеры
входные данные
32768 4 64 10
34593 3456994 54588 3458348 45688 54588 3458348 3458348 1 1000000
выходные данные
3 7
входные данные
32768 8 128 10
1 2 3 4 5 10000 10001 10002 10003 10004
выходные данные
8 2
*/

#include <iostream>
#include <vector>

using namespace std;



int main() {
	long long cacheSize;
	int associativity;
	int line_size;
	int n;
	
		
	cin >> cacheSize >> associativity >> line_size >> n;

}