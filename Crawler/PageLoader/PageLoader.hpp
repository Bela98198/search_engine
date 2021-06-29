#ifndef PageLoader_hpp
#define PageLoader_hpp

#include <string>
#include "PageResult.hpp"

class PageLoader
{
public:

    static Page load(const std::string& url);

private:

    static size_t getData(char* buffer, size_t size, size_t itemCount, void* dest);

};


#endif 