/*
Copyright (c) 2009-2013 Dave Gamble
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

#include <stdio.h>
#include <string>
#include "cJSON_wrapper.h"
#include "exception.h"

using namespace std;

struct mydata
{
	void print(){printf("string: %s, integer=%d, double=%f, bool=%d, array=[%s,%s]\n", s.c_str(), i, d, b, a[0].c_str(), a[1].c_str());}
	string  s;
	int     i;
	double  d;
	bool    b;
	string  a[2];
};

void doit(char* text)
{
    const char *ep;  cJSON *json;
    json = cJSON_Parse(text, &ep);
	if (!json) {printf("Error before: [%s]\n",ep);}
	else
	{
		try
		{
			struct mydata data;
			data.s = cJSON_GetRequiredStringObjectItem(json, "string");
			data.i = cJSON_GetRequiredIntObjectItem(json, "integer", 0);
			data.d = cJSON_GetRequiredDoubleObjectItem(json, "integer", 0.0);
			data.b = cJSON_GetRequiredBoolObjectItem(json, "bool");
			cJSON* arrayobj = cJSON_GetObjectItem(json, "array");
			data.a[0] = cJSON_GetRequiredStringArrayItem(arrayobj, 0);
			data.a[1] = cJSON_GetRequiredStringArrayItem(arrayobj, 1);

			data.print();
		}
		catch(json_exception &e)
		{
			printf("Error Parsing: %s\n", e.what());
		}
		cJSON_Delete(json);
	}

}


int main (int argc, const char * argv[]) {
	
	/* a bunch of json: */
	char text[]="{\n\"string\": \"hello world..\", \n\"integer\": 100, \n\"double\": 100.001, \n\"bool\": true\n, \n\"array\": [\"item1\",\"item2\"]}";	
	char text_int_invalidtype[]="{\n\"string\": \"hello world..\", \n\"integer\": \"100\", \n\"double\": 100.001, \n\"bool\": true\n, \n\"array\": [\"item1\",\"item2\"]}";	
	char text_int_missing[]="{\n\"string\": \"hello world..\", \n\"double\": 100.001, \n\"bool\": true\n, \n\"array\": [\"item1\",\"item2\"]}";	

	/* Process each json textblock by parsing, then rebuilding: */
	printf("\ntest1...............\n");
	doit(text);
	printf("\ntest2...............\n");
	doit(text_int_invalidtype);
	printf("\ntest3...............\n");
	doit(text_int_missing);
	
	printf("\nFinish...............\n");
	return 0;
}
