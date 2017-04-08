CXX = g++
CXXFLAGS = -Wall -g

main: main.o Grade.o median.o Student_info.o
	$(CXX) $(CXXFLAGS) -o main main.o Grade.o median.o Student_info.o

main.o: main.cpp Grade.h Student_info.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Student_info.o: Student_info.h Grade.h
median.o: median.h
Grade.o: Grade.h median.h