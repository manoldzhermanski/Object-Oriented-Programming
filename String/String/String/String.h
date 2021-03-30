#pragma once
#include <cstring>
#include <iostream>
#include <cassert>

class String
{
public:
	String();
	String(const size_t capacity, const char* str);
	String(const String& other);
	String& operator= (const String& other);
	~String();

	void setCapacity(const size_t capacity);
	void setSize(const size_t size);
	void setStr(const char* str);

	size_t getCapacity()const;
	size_t getSize()const;
	char* getStr()const;
	size_t getLength()const;

	String operator+ (const String& other);
	String operator+= (const String& other);
	bool operator== (const String& other) const;
	bool operator!= (const String& other);
	char operator[] (const size_t index)const;
	char& operator[] (const size_t index);

	friend std::ostream& operator<< (std::ostream& out, const String& s);

	void add(const char c);
	void insertAt(const size_t index, const char c);
	void deleteAt(const size_t index);
	void trimStart();
	void trimStart(const size_t numberCharacters);
	void trimEnd();
	void trimEnd(const size_t numberCharacters);
private:
	char* str;
	size_t capacity;
	size_t size;
};

