/*
Copyright (c) 2013 Muhammad Asif Fayyaz

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef __CJSON_WRAPPER_H__
#define __CJSON_WRAPPER_H__

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
