#ifndef ARRAY_TPP
#define ARRAY_TPP

template <typename T>
Array<T>::Array(): arr(NULL), size(0) {}

template <typename T>
Array<T>::Array(int amount): arr(new T[amount]), size(amount) {}

template <typename T>
Array<T>::Array(const Array<T>& other): arr(new T[other.size]), size(other.size) {
	for (int i = 0; i < this->size; i++)
		this->arr[i] = other.arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other) {
		delete[] this->arr;
		this->arr = new T[other.size];
		this->size = other.size;
		for (int i = 0; i < this->size; i++)
			this->arr[i] = other.arr[i];
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](int idx) {
	if (idx >= this->size || idx < 0)
		throw IndexOutOfRange();
	return this->arr[idx];
} 

template <typename T>
Array<T>::~Array() {
	delete[] this->arr;
}

template <typename T>
int Array<T>::getSize() {
	return this->size;
}

#endif