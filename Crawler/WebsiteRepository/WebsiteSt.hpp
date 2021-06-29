#ifndef WebsiteSt_hpp
#define WebsiteSt_hpp

#include <bits/stdc++.h>
#include "Website.hpp"

class WebsiteSt
{
    

public:
    
    std::vector<Website> getAll() const;
    oid add(const Website& website);
    void update(const Website& website);
    
};


#endif 