#ifndef __CJSON_WRAPPER_HPP__
#define __CJSON_WRAPPER_HPP__

#include <cstdlib>
#include <string>

#include "cJSON.h"

extern cJSON *cJSON_GetRequiredObjectItem(cJSON *object,const char *item);
extern std::string cJSON_GetRequiredStringArrayItem(cJSON *array,int item);
extern int cJSON_GetRequiredIntObjectItem(cJSON *object,const char *item, int minval);
extern bool cJSON_GetRequiredBoolObjectItem(cJSON *object,const char *item);
extern double cJSON_GetRequiredDoubleObjectItem(cJSON *object,const char *item, double minval);
extern double cJSON_GetOptionalDoubleObjectItem(cJSON *object,const char *item, double minval);
extern std::string cJSON_GetRequiredStringObjectItem(cJSON *object,const char *item);
extern std::string cJSON_GetOptionalStringObjectItem(cJSON *object,const char *item);

inline
std::string
json_payload(cJSON* root)
{
    char* out = NULL;
    std::string p;

    try
    {
        out = cJSON_Print(root);
        p.assign(out);
        free(out);
        out=NULL;
    }
    catch(...)
    {
        if(NULL != out)
        {
            free(out);
            out=NULL;
        }
    }

    return p;
}

#endif //__CJSON_WRAPPER_H__
