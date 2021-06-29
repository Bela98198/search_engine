#include "PageLoader.hpp"

#include <bits/stdc++.h>
#include <curl/curl.h>

PageResult  PageLoader::load(const std::string& url) 
{
    CURL* curl = curl_easy_init();
    CURLcode requestResult = CURLE_NO_CONNECTION_AVAILABLE;
    
    std::string data;
    PageResult::statusType responseCode = 0;
    std::string effectiveUrl;
    if(curl) 
    {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
        
        struct curl_slist* list = NULL;
        list = curl_slist_append(list, "Accept: text/html");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
        
        
        requestResult = curl_easy_perform(curl);
        
    
        if(requestResult != CURLE_OK) 

        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(requestResult));
        } 
        else 

        {
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &responseCode);
            
            char* url = nullptr;
        
            curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &url);

            
            if (url != nullptr) 
            {
                effectiveUrl.append(url);
            }
            
        }
        
        //cleanup
        curl_easy_cleanup(curl);
    }
    return PageResult (effectiveUrl, data, responseCode, requestResult);
}
