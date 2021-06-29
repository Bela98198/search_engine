#ifndef Parser_hpp
#define Parser_hpp

#include <bits/stdc++.h>
#include <gumbo.h>

class Parser 
{
    
private:
    web::uri url;
    
    std::string html;
    std::vector<std::string> urls;
    std::string title;
    std::string description;
    std::string allText;
    
private:
    void extractUrls(GumboNode* node);
    
    std::string extractCleanText(GumboNode* node) const;
    std::string extractTitle(const GumboNode* root) const;
    
    void extractDescription(GumboNode* node);

public:
    Parser(const std::string& url, const std::string& html);
    
    void parse();

    const std::vector<std::string>& getUrls() const;

    const std::string& getTitle() const;
    const std::string& getDescription() const;
    const std::string& getAllText() const;
   
};

#endif 