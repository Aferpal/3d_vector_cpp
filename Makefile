ifeq ($(OS),Windows_NT)
    include Makefilewin
else
    include Makefilelin
endif

B_CLASSES=./src/basicClasses
TEST_FOLDER=./src/test

test: $(B_CLASSES)/Point.h Point.o Point3DTest.o
	g++ -o ./output/$@ Point.o Point3DTest.o
Point.o: $(B_CLASSES)/Point.cpp
	g++ -c $(B_CLASSES)/Point.cpp
Point3DTest.o: $(TEST_FOLDER)/Point3DTest.cpp
	g++ -c $(TEST_FOLDER)/Point3DTest.cpp
