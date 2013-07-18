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
