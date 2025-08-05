#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;

template<typename T>
T* cpp_realloc(T* mass, int * len, int add_bytes) {
	*len += add_bytes;
	T* upd_mass = new T[*len];
	for (int i = 0; i < *len - add_bytes; i++) {
		upd_mass[i] = mass[i];
	}
	delete[] mass;
	return upd_mass;
}




template<class T>
class CQueue {
private:

	T* queue;
	int cur_pos = 0;
	int len;

	void upd_queue() {
		queue = cpp_realloc(queue, &len, 1);
	}

public:
	CQueue() : len(1) {
		queue = new T[1];
	}

	CQueue(int ln) : len(ln) {
		queue = new T[len];
	}

	int get_len() {
		return len;
	}

	int get_pos() {
		return cur_pos;
	}

	T* get_obj(int i) {
		return queue + i;
	}

	void add_person(T obj) {
		if (cur_pos == len) {
			upd_queue();
		}
		*(queue + cur_pos) = obj;
		cur_pos++;
	}

	void next() {
		len--;
		cur_pos--;
		T* upd_queue = new T[len];
		for (int i = 0; i < len; i++) {
			*(upd_queue + i) = *(queue + i + 1);
		}
		delete[] queue;
		queue = upd_queue;
	}

};