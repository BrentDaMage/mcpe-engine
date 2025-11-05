#include "Util.hpp"

const std::string Util::EMPTY_STRING = "";

bool Util::isValidPath(const std::string& path)
{
    for (int i = 0; i < path.size(); i++)
    {
        switch (path.at(i))
        {
        case '\n':
        case '\r':
            return false;
        }
    }

    return true;
}

std::string Util::getFileName(const std::string& path)
{
    size_t namePos = 0;
    size_t nameSize = std::string::npos;

    size_t lastOf = path.find_last_of("/\\");
    if (lastOf != std::string::npos)
        namePos = lastOf + 1;
    
    size_t dotPos = path.rfind('.');
    if (dotPos != std::string::npos && dotPos > namePos)
        nameSize = dotPos - namePos;

    return path.substr(namePos, nameSize);
}