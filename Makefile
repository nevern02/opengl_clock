OBJS = Clock.o main.cpp
LIBS = -lGL -lGLU -lglut
CC = g++ 
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

OpenGLClock : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) $(LIBS) -o OpenGLClock

Clock.o : Clock.h Clock.cpp
	$(CC) $(CFLAGS) Clock.cpp $(LIBS)

clean:
	\rm *.o OpenGLClock
