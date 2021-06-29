#ifndef DocumentStr_hpp
#define DocumentStr_hpp

#include "Document.hpp"
#include <unordered_map>
#include <string>
#include <vector>


class DocumentStore 
{
    
private:
    
    std::unordered_map<std::string,Document> all ;
    
public:
        
    std::vector<Document> getAll() const;
    void save(const Document& document);
    std::size_t count() const;
};


#endif 