#include "string.h"
#include <cstring>
#include <iostream>
#pragma warning (disable: 4996)

void String::copy(const String& other)
{
	size = other.size;
	text = new char[size + 1];
	strcpy(text, other.text);
}

void String::free()
{
	delete[] text;
}

String::String()
{
	size = 0;
	text = new char[1];
	text[0] = '\0';
}

String::String(const char* data)
{
	size = strlen(data);
	text = new char[size + 1];
	strcpy(text, data);
}

String::String(const String& other)
{
	copy(other);
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

String::~String()
{
	free();
}

size_t String::getSize() const
{
	return size;
}

const char* String::getText() const
{
	return text;
}

void String::setName(const char* data)
{
	delete[] text;
	size = strlen(data);
	text = new char[size + 1];
	strcpy(text, data);
}

void String::concat(const String& other)
{
	size = size + other.size;
	char* temp = new char[size + 1];
	strcpy(temp, text);
	strcat(temp, other.text);

	delete[] text;
	text = temp;
}

String& String::operator+=(const String& other)
{
	concat(other.text);
	return *this;
}

bool String::operator==(const String& other) {
	return strcmp(text, other.text) == 0 && size == other.size;
}

std::ostream& operator<<(std::ostream& out, const String& obj)
{
	out << obj.text;
	return out;
}

std::istream& operator>>(std::istream& in, String& obj)
{
	char buffer[1024];
	in >> buffer;
	obj.free();
	obj.size = strlen(buffer);
	obj.text = new char[obj.size + 1];
	strcpy(obj.text, buffer);

	return in;
}

String operator+(const String& lhs, const String& rhs)
{
	String temp(lhs);
	temp += rhs;
	return temp;
}

void String::clear() {
	free();
	size = 0;
}
