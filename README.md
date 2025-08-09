To run:

g++ test.cpp assignment5.cpp -o test.exe
./test.exe

=============================================================================================
=============================================================================================
Changes to docs:

**commented out Solutions.h

=============================================================================================
=============================================================================================
Dev notes|
=============================================================================================
TASK1:|
=======

Need to learn about ifstream:

-Make sure the vector is std::string, not int!
    -  std::vector<std::string> words_vector *is the same* as WordVec words_vector;

-Must include <ifstream>
-Use is_open() to check if the file was opened!

- std::istream_iterator<std::string> begin_iter(inputfile);
    - We must build the iterator from the stream, not the file name!
    - Also, we must do the same this for end_iter!

- We want to use the function, we should save the vector that's returned in a WordVec, 
so that we can use them.

**if you want to print it directly:
for (std::istream_iterator<std::string> it(inputfile), end; it != end; ++it) {
    std::cout << *it << '\n';
}

=============================================================================================
TASK2:|
=======
What we are doing here:
-Taking the vector that was created in task1
-Count how many times each word appears
-Saving it in a map<string, int>
-Return the map!


the wVec is the one that has to be used int he for_each algo!


=============================================================================================
TASK3:|
=======

the functor operator() will have the same functionality as the lambda
    -it will take the words 
    -increments ++wMap[words]


=============================================================================================
TASK4:|
=======


