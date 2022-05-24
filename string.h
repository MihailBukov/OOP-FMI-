#pragma once
#include<iostream>

class String
{
private:
	char* text;
	size_t size;
public:
	String();
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();

	void setName(const char*);
	size_t getSize() const;

	const char* getText() const;
	void concat(const String&);

	String& operator+=(const String&);
	bool operator==(const String&);
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend std::istream& operator>>(std::istream&, String&);
	void clear();
private:
	void copy(const String&);
	void free();
};
