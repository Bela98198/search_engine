#ifndef Website_hpp
#define Website_hpp

#include <bits/stdc++.h>

class Website 
{

private:
    
    
    int id;
    std::string domain;
    std::string homepage;
    time_t lastCrawlingTime;
    
public:
        

    Website(int id, const std::string& domain, const std::string& homepage, time_t time);
    
    const std::string& getDomain() const;
    const std::string& getHomepage() const;
    time_t getLastCrawlingTime() const;
    
    int getId() const;
};


