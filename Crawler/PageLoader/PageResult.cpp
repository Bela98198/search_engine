#include "PageResult.hpp"

PageResult::PageResult(const std::string& url, const std::string& body, statusType status, errorType error) 
{
    this->url = url;
    this->body = body;
    this->status = status;
    this->error = error;
}


const std::string& PageResult::getUrl() const 
{
    return this->url;
}

const std::string& PageResult::getBody() const 
{
    return this->body;
}

Page::statusType PageResult::getStatus() const
{
    return this->status;
}

CURLcode  PageResult::isError() const 
{
    return this->error;
}


