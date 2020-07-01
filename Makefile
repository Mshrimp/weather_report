
TARGET = report

CC = gcc
CFLAGS = -Wall


INCLUDE = -I./cjson -I./weather

SOURCE = main.c	\
		 cjson/cJSON.c	\
		 weather/weather.c

OBJECTS = $(SOURCE:.c=.o)

$(TARGET):$(OBJECTS)
	$(CC) $^ -o $@

%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


clean:
	@rm $(TARGET) $(OBJECTS) -rf
