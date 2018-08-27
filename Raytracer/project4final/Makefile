CC = g++
CFLAGS = -g
#all of your c files that you're using
SRC = rt.cpp vector.cpp object.cpp sphere.cpp light.cpp plane.cpp box.cpp
CSRC = crt.cpp vector.cpp object.cpp sphere.cpp light.cpp plane.cpp box.cpp
#refers to the target directory
TARGET = rt
CTARGET = crt

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) -lm
#for creative project
creative:
	$(CC) $(CFLAGS) $(CSRC) -o $(CTARGET) -lm

clean:
	rm -f *.o $(TARGET)

