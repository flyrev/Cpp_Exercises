#include <iostream> // I/O
#include <algorithm> // Yeah
#include "CppUTest/CommandLineTestRunner.h" // For actually running tests
#include <CppUTest/TestHarness.h> // Fetching tests from current file and feeding them to the test runner

using namespace std;

int main(int argc, char **argv) {
	cout << "Exercise 1" << endl;

	// Deal with command line parameters here.
	for (int i=1; i<argc; i++ ) {
		string arg = string(argv[i]); 
	}

	/************* RUN ALL THE TESTS ***********/
	// Two dummy checks to verify that the test framework itself is working:
	CHECK(true);
	LONGS_EQUAL(1, 1);

	// This line assures no parameters are sent to the rest runner (which is convenient if you are passing arguments of your own to the program - it won't conflict with the test runner). It will therefore just run every test it has harnessed. If you want to pass everything on from the program, change the arguments to
 	//return CommandLineTestRunner::RunAllTests(argv, argv);
	return CommandLineTestRunner::RunAllTests(1, argv);  
	/***************** END RUN ALL TESTS *******/
}


// Creating an example test group called "Example":
TEST_GROUP(Example) {

}; // Do not forget the semicolon

// Creating a test in the "Example" group called "exampleTest"
TEST(Example, exampleTest) {
	int a=2;
	int b=3;
	CHECK(a != b); // Verify that a is in fact not equal to b here. Remember that the exclamation mark should be on the left side of =, otherwise it becomes "set a to the inverted value of b". :)
}
