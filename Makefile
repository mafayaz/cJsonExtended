
all: test_cJSON test
	
test_cJSON: test_cJSON.c cJSON.c
	gcc -Wall test_cJSON.c cJSON.c -o test_cJSON -lm

test: test.cpp cJSON_wrapper.cpp cJSON.c
	g++ -g -Wall test.cpp cJSON_wrapper.cpp cJSON.c -o test

clean:
	rm -f test_cJSON test
