#ifndef PageResult_hpp
#define PageResult_hpp

#include <string>
#include <curl/curl.h>

class Page 
{
    
public:
    typedef long statusType;

private:
    
    std::string url;
    std::string body;
    statusType status;
    CURLcode  error;

public:
    
    PageResult(const std::string& url, const std::string& body, statusType status, errorType error);
    
    CURLcode isError() const;
    const std::string& getBody() const;
    const std::string& getUrl() const;
    statusType getStatus() const;
    
};

#endif