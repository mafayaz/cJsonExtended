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

#include <string>

#include "cJSON_wrapper.h"
#include "exception.h"


using namespace std;

cJSON *cJSON_GetRequiredObjectItem(cJSON *object,const char *item)
{
    cJSON* obj = cJSON_GetObjectItem(object, item);
    if(!obj) throw json_exception(string("Required Field [")+item+string("] is missing"));
    return obj;
}
string cJSON_GetRequiredStringArrayItem(cJSON *array,int item)
{
    cJSON* obj = cJSON_GetArrayItem(array, item);
    if(!obj) throw json_exception(string("Required Array Item is missing"));
    if (cJSON_String != obj->type) throw json_exception(string("Array Item has invalid type"));
    return obj->valuestring;
}
int cJSON_GetRequiredIntObjectItem(cJSON *object,const char *item, int minval)
{
    cJSON* obj = cJSON_GetObjectItem(object, item);
    if(!obj) throw json_exception(string("Required Field [")+item+string("] is missing"));
    if (cJSON_Number != obj->type) throw json_exception(string("Field [")+item+string("] has invalid type"));
    if(obj->valueint < minval) throw json_exception(string("Field [")+item+string("] has invalid value"));
    return obj->valueint;
}
bool cJSON_GetRequiredBoolObjectItem(cJSON *object,const char *item)
{
    cJSON* obj = cJSON_GetObjectItem(object, item);
    if(!obj) throw json_exception(string("Required Field [")+item+string("] is missing"));
    if(cJSON_False == obj->type) return false;
    if(cJSON_True == obj->type) return true;
    throw json_exception(string("Field [")+item+string("] has invalid value"));
}
double cJSON_GetRequiredDoubleObjectItem(cJSON *object,const char *item, double minval)
{
    cJSON* obj = cJSON_GetObjectItem(object, item);
    if(!obj) throw json_exception(string("Required Field [")+item+string("] is missing"));
    if (cJSON_Number != obj->type) throw json_exception(string("Field [")+item+string("] has invalid type"));
    if(obj->valuedouble < minval) throw json_exception(string("Field [")+item+string("] has invalid value"));
    return obj->valuedouble;
}
double cJSON_GetOptionalDoubleObjectItem(cJSON *object,const char *item, double minval)
{
    cJSON* obj = cJSON_GetObjectItem(object, item);
    if(!obj) return -1.0;
    if (cJSON_Number != obj->type) throw json_exception(string("Field [")+item+string("] has invalid type"));
    if(obj->valuedouble < minval) throw json_exception(string("Field [")+item+string("] has invalid value"));
    return obj->valuedouble;
}
string cJSON_GetRequiredStringObjectItem(cJSON *object,const char *item)
{
    cJSON* obj = cJSON_GetObjectItem(object, item);
    if(!obj) throw json_exception(string("Required Field [")+item+string("] is missing"));
    if (cJSON_String != obj->type) throw json_exception(string("Field [")+item+string("] has invalid type"));
    return obj->valuestring;
}
string cJSON_GetOptionalStringObjectItem(cJSON *object,const char *item)
{
    cJSON* obj = cJSON_GetObjectItem(object, item);
    if(!obj) return "";
    if (cJSON_String != obj->type) throw json_exception(string("Field [")+item+string("] has invalid type"));
    return obj->valuestring;
}
