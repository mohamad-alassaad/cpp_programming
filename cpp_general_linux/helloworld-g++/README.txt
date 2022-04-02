g++ is the compiler
check the version $g++ --version 
for options and usage: $g++ --help
if not exist, install it: $sudo apt install build-essential
create the program: $ touch hello.cpp
edit the program $ vim hello.cpp
						
					#include <iotstream>
					using namespace std;
					int main()
							{
								//print output to user
								cout << "Hello World !" << endl;
								return 0;
							}
compile and run: $g++ hello.cpp 
this will create a.out file, which is the default output file.
run the output file from the command line $ ./a.out   (this should gives: Hello World!
if you want to save the executable (the binary) to specific file: $g++ hello.cpp -o output
run the binary (executable) $./output