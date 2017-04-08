CXX = g++
CXXFLAGS = -Wall -g

main: main.o grade.o median.o Student_info.o
	$(CXX) $(CXXFLAGS) -o main main.o grade.o median.o Student_info.o

main.o: main.cpp grade.h Student_info.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Student_info.o: Student_info.h
median.o: median.h
grade.o: grade.h median.h Student_info.h