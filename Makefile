CC=gcc
CFLAGS=-c -Wall
LDFLAGS= -lm
SOURCES=test_cJSON.c cJSON.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=test_cJSON

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o test_cJSON
