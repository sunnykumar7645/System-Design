Compile the c++ using  command
g++ -c file/files_name
then you will get object file corresponding to that filename with extension .o
then put them into static archive file
ar rcs library_name.a object file 









2. Create a Static Archive (.a file)
Now, you can create a static archive using the ar (archiver) tool. Here's how you do it:

Compile each .cpp file into an object file (.o):

bash
Copy code
g++ -c file1.cpp  # Creates file1.o
g++ -c file2.cpp  # Creates file2.o
Create a static archive .a file using ar:

bash
Copy code
ar rcs libmylibrary.a file1.o file2.o
This creates a static library libmylibrary.a, which contains the object files file1.o and file2.o.

r: Insert files into the archive.
c: Create the archive if it doesn't exist.
s: Create an index for faster linking.
3. Use the Static Library in Your Program
Now, you can use the static library libmylibrary.a in your main program.
4. Link the Static Library
When compiling your program, you need to specify the path to the static archive (libmylibrary.a) and tell the linker to link it. Here's how you do it:

bash
Copy code
g++ main.cpp -L. -lmylibrary -o my_program
Explanation:

-L.: Tells the compiler to look in the current directory (.) for the static library.
-lmylibrary: Tells the linker to link the libmylibrary.a file (you don't need to include the lib prefix or .a suffix when specifying the library).
-o my_program: Specifies the output executable file (my_program).
5. Run the Program
Finally, run the program:

bash
Copy code
./my_program