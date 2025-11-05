#pragma once

#include <string>

class Util
{
public:
	static const std::string EMPTY_STRING;

public:
    static bool isValidPath(const std::string& path);
    // Returns the name of a file, without its extension
    static std::string getFileName(const std::string& path);
};