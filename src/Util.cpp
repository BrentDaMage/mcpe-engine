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