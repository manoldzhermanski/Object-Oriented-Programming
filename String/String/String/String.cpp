#include "String.h"

String::String()
{
	setCapacity(0);
	setSize(0);
	setStr(nullptr);
}

String::String(const size_t capacity, const char* str)
{
	setCapacity(capacity);
	setSize(std::strlen(str));
	setStr(str);
}

String::String(const String& other)
{
	setCapacity(other.getCapacity());
	setSize(other.getSize());
	setStr(other.getStr());
}

String& String::operator=(const String& other)
{
	setCapacity(other.getCapacity());
	setSize(other.getSize());
	setStr(other.getStr());
	return *this;
}

String::~String()
{
	delete[] this->str;
}

void String::setCapacity(const size_t capacity)
{
	if (capacity < 0) {
		this->capacity = 0;
	}
	else {
		this->capacity = capacity;
	}
}

size_t String::getCapacity() const
{
	return this->capacity;
}

void String::setSize(const size_t size)
{
	if (size < 0) {
		this->size = 0;
	}
	else {
		this->size = size;
	}
}

size_t String::getSize() const
{
	return this->size;
}

void String::setStr(const char* str)
{
	if (str != nullptr) {
		if (strlen(str) >= this->capacity) {
			this->capacity = strlen(str);
			this->str = new char[this->capacity + 1];
			for (size_t i = 0; i < strlen(str); i++) {
				this->str[i] = str[i];
			}
			this->str[strlen(str)] = '\0';
		}
		else {
			this->str = new char[this->capacity];
			for (size_t i = 0; i < strlen(str); i++) {
				this->str[i] = str[i];
			}
			this->str[strlen(str)] = '\0';
		}
	}
	else {
		this->str = new char[0];
	}
}

char* String::getStr() const
{
	return this->str;
}

size_t String::getLength() const
{
	return this->getSize();
}

String String::operator+(const String& other)
{
	String buffer;
	buffer.setCapacity(this->getCapacity() + other.getCapacity());
	buffer.setSize(this->getSize() + other.getSize());
	buffer.str = new char[this->getCapacity() + other.getCapacity() + 1];

	for (size_t i = 0; i < this->getSize(); i++) {
		buffer.str[i] = this->str[i];
	}
	for (size_t i = 0; i < other.getSize(); i++) {
		buffer[this->getSize() + i] = other.str[i];
	}
	buffer[this->getSize() + other.getSize()] = '\0';
	return buffer;
}

String String::operator+=(const String& other)
{
	*this = *this + other;
	return *this;
}

bool String::operator==(const String& other) const
{
	for (size_t i = 0; i < this->size; i++) {
		if (this->str[i] != other.str[i]) {
			return false;
		}
	}
	return true;
}

bool String::operator!=(const String& other)
{
	return !(*this == other);
}

char String::operator[](const size_t index) const
{
	assert(index >= 0 || index < this->size);
	return this->str[index];
}

char& String::operator[](const size_t index)
{
	assert(index >= 0 || index < this->size);
	return this->str[index];
}

void String::add(const char c)
{
	char* buffer = new char[this->getCapacity() + 1];
	for (size_t i = 0; i < this->getSize(); i++) {
		buffer[i] = this->str[i];
	}
	buffer[this->getSize()] = c;
	buffer[this->getSize() + 1] = '\0';
	this->size++;
	this->capacity++;
	this->str = buffer;

}

void String::insertAt(const size_t index, const char c)
{
	assert(index >= 0 || index < this->getCapacity());
	char* buffer = new char[this->getCapacity() + 1];
	size_t countInsertion = 0;
	for (size_t i = 0; i < this->getSize(); i++) {
		if (i == index) {
			buffer[i] = c;
			break;
		}
		else {
			buffer[i] = this->str[i];
		}
		countInsertion++;
	}
	for (size_t i = countInsertion; i < this->getSize(); i++) {
		buffer[i + 1] = this->str[i];
	}
	buffer[this->getSize()] = '\0';
	this->size++;
	this->capacity++;
	this->str = buffer;
}

void String::deleteAt(const size_t index)
{
	assert(index >= 0 || index < this->getCapacity());
	char* buffer = new char[this->getCapacity() + 1];
	size_t countInsertion = 0;
	for (size_t i = 0; i < this->getSize(); i++) {
		if (i == index) {
			break;
		}
		else {
			buffer[i] = this->str[i];
		}
		countInsertion++;
	}
	for (size_t i = countInsertion; i < this->getSize(); i++) {
		buffer[i] = this->str[i + 1];
	}
	buffer[this->getSize()] = '\0';
	this->size--;
	this->capacity--;
	this->str = buffer;
}

void String::trimStart()
{
	char* buffer = new char[this->getCapacity()];
	for (size_t i = 0; i < this->getSize(); i++) {
		buffer[i] = this->str[i + 1];
	}
	buffer[this->getSize()] = '\0';
	this->size--;
	this->capacity--;
	this->str = buffer;
}

void String::trimStart(const size_t numberCharacters)
{
	assert(numberCharacters >= 0 || numberCharacters < this->getCapacity());
	char* buffer = new char[this->getCapacity()];
	for (size_t i = 0; i < this->getSize(); i++) {
		buffer[i] = this->str[numberCharacters + i];
	}
	buffer[this->getSize()] = '\0';
	this->size--;
	this->capacity--;
	this->str = buffer;

}

void String::trimEnd()
{
	char* buffer = new char[this->getCapacity()];
	for (size_t i = 0; i < this->getSize() - 1; i++) {
		buffer[i] = this->str[i];
	}
	buffer[this->getSize() - 1] = '\0';
	this->size--;
	this->capacity--;
	this->str = buffer;
}

void String::trimEnd(const size_t numberCharacters)
{
	assert(numberCharacters >= 0 || numberCharacters < this->getCapacity());
	char* buffer = new char[this->getCapacity()];
	for (size_t i = 0; i < this->getSize() - numberCharacters; i++) {
		buffer[i] = this->str[i];
	}
	buffer[this->getSize() - numberCharacters] = '\0';
	this->size--;
	this->capacity--;
	this->str = buffer;

}

std::ostream& operator<<(std::ostream& out, const String& s)
{
	out << s.str;
	return out;
}
