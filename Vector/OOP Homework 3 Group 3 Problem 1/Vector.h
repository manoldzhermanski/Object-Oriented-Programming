#pragma once
#include <cassert>
#include <iostream>
template <class T>
class Vector
{
public:
	typedef T* iterator;

	Vector();
	Vector(const size_t capacity);
	Vector(const Vector<T>& other);
	Vector<T>& operator= (const Vector<T>& other);
	~Vector();

	T operator[](const size_t i) const;
	T& operator[] (const size_t i);
	iterator begin();

	Vector<T> operator+ (const Vector<T>& other);
	Vector<T> operator+= (const Vector<T>& other);
	Vector<T> operator- (const Vector<T>& other);
	Vector<T> operator-= (const Vector<T>& other);

	void push_back(const T& data);
	void push_front(const T& data);

	void pop_back();
	void pop_front();
	void pop_by_data(const T& data);

	size_t getSize() const;
	size_t getCapacity()const;

	template <typename E>
	friend std::ostream& operator<<(std::ostream&, Vector<E>);

private:
	T* content;
	size_t size;
	size_t capacity;
	bool isPresent(const Vector<T> v, T element);
	void removeElement(const Vector<T>& content, T element);
};

template <typename T>
std::ostream& operator<<(std::ostream& out, Vector<T> v) {
	out << "{ ";
	for (size_t i = 0; i < v.size; i++) {
		out << v[i] << " ";
	}
	out << "}";
	return out;
}


template<class T>
inline Vector<T>::Vector()
{
	capacity = 0;
	size = 0;
	content = nullptr;
}

template<class T>
inline Vector<T>::Vector(const size_t capacity)
{
	this->capacity = capacity;
	this->size = 0;
	content = new T[this->capacity];
}

template<class T>
inline Vector<T>::Vector(const Vector<T>& other)
{
	this->capacity = other.capacity;
	this->size = other.size;
	this->content = new T[other.capacity];
	for (size_t i = 0; i < size; i++) {
		this->content[i] = other.content[i];
	}
}

template<class T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other) {
		delete this->content;
		this->size = other.size;
		this->capacity = other.capacity;
		this->content = new T[other.capacity];
		for (size_t i = 0; i < other.size; i++) {
			this->content[i] = other.content[i];
		}
	}
	return *this;
}

template<class T>
inline Vector<T>::~Vector()
{
	delete[] content;
}

template<class T>
inline T Vector<T>::operator[](const size_t i)const
{
	assert(i >= 0 || i < this.size);
	return content[i];
}

template<class T>
inline T& Vector<T>::operator[](const size_t i)
{
	assert(i >= 0 || i < this->size);
	return this->content[i];
}

template<class T>
typename Vector<T>::iterator Vector<T>::begin()
{
	return this->content;
}

template<class T>
inline Vector<T> Vector<T>::operator+(const Vector<T>& other)
{
	Vector<T> buffer;
	buffer.capacity = this->capacity + other.capacity;
	buffer.size = this->size + other.size;
	buffer.content = new T[capacity];
	int countInsertions = 0;
	for (size_t i = 0; i < this->size; i++) {
		buffer.content[i] = this->content[i];
		countInsertions++;
	}
	for (size_t i = 0; i < other.size; i++) {
		buffer.content[countInsertions + i] = other.content[i];
	}

	return buffer;
}

template<class T>
inline Vector<T> Vector<T>::operator+=(const Vector<T>& other)
{
	*this = *this + other;
	return *this;
}

template<class T>
inline Vector<T> Vector<T>::operator-(const Vector<T>& other)
{
	Vector<T> buffer(this->capacity);
	for (size_t i = 0; i < other.size; i++) {
		T data = other.content[i];
		if (!isPresent(*this, data)) {
			continue;
		}
		for (size_t j = 0; j < this->size; j++) {
			if (this->content[j] == data) {
				continue;
			}
			else {
				buffer.push_back(this->content[j]);
			}
		}
	}
	return buffer;
}

template<class T>
inline Vector<T> Vector<T>::operator-=(const Vector<T>& other)
{
	*this = *this - other;
	return *this;
}

template<class T>
inline void Vector<T>::push_back(const T& data)
{
	if (this->size == this->capacity) {
		T* buffer = new T[this->capacity + 1];
		for (size_t i = 0; i < this->size; i++) {
			buffer[i] = this->content[i];
		}
		buffer[this->size] = data;
		this->size++;
		this->capacity++;
		this->content = buffer;
	}
	else {
		T* buffer = new T[capacity];
		for (size_t i = 0; i < this->size; i++) {
			buffer[i] = this->content[i];
		}
		buffer[this->size] = data;
		this->size++;
		this->content = buffer;
	}
}

template<class T>
inline void Vector<T>::push_front(const T& data)
{
	if (this->size == this->capacity) {
		T* buffer = new T[this->capacity + 1];
		buffer[0] = data;
		for (size_t i = 0; i < this->size; i++) {
			buffer[i + 1] = this->content[i];
		}
		this->size++;
		this->capacity++;
		this->content = buffer;
	}
	else {
		T* buffer = new T[this->capacity];
		buffer[0] = data;
		for (size_t i = 0; i < this->size; i++) {
			buffer[i + 1] = this->content[i];
		}
		this->size++;
		this->content = buffer;
	}
}

template<class T>
inline void Vector<T>::pop_back()
{
	assert(this->size != 0);
	T* buffer = new T[this->capacity];
	for (size_t i = 0; i < this->size - 1; i++) {
		buffer[i] = this->content[i];
	}
	size--;
	this->content = buffer;
}

template<class T>
inline void Vector<T>::pop_front()
{
	assert(this->size != 0);
	T* buffer = new T[this->capacity];
	for (size_t i = 0; i < this->size; i++) {
		buffer[i] = this->content[i + 1];
	}
	size--;
	this->content = buffer;
}

template<class T>
inline void Vector<T>::pop_by_data(const T& data)
{
	assert(this->size != 0);
	T* buffer = new T[this->capacity];
	int continueAdding = 0;
	for (size_t i = 0; i < this->size; i++) {
		if (this->content[i] == data) {
			this->size--;
			break;
		}
		else {
			buffer[i] = this->content[i];
			continueAdding++;
		}
	}

	for (size_t i = continueAdding; i < this->size; i++) {
		buffer[i] = this->content[i + 1];
	}

	this->content = buffer;
}

template<class T>
inline size_t Vector<T>::getCapacity() const
{
	return this->capacity;
}

template<class T>
inline bool Vector<T>::isPresent(const Vector<T> v, T element)
{

	for (size_t i = 0; i < v.size; i++) {
		if (v.content[i] == element) {
			return true;
		}
	}
	return false;
}

template<class T>
inline void Vector<T>::removeElement(const Vector<T>& content, T element)
{
	for (size_t i = 0, j = 0; i < content.size; i++)
		if (content.content[i] != element)
			content.content[j++] = content.content[i];
}

template<class T>
inline size_t Vector<T>::getSize()const
{
	return this->size;
}
