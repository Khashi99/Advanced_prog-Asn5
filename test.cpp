#include "assignment5.h"
#include <iostream>
#include <cassert>
#include <iterator>
using namespace std;

// void task_7_test_driver()
// {
//    cout << "\nTask 7: Multiset using Custom Sorting Criteria" << endl;
//    std::vector<std::string> vec =
//    { "C", "BB", "A", "CC", "A", "B", "BB", "A", "D", "CC", "DDD", "AAA" };
//    multisetUsingMyComparator(vec);
//    cout << endl;
// }

void task_8_test_driver(int n)
{
    cout << "\nTask 8: Fibonacci Sequence" << endl;
    auto fibs = getnerate_Fibonacci(n);
    std::copy(fibs.begin(), fibs.end(), std::ostream_iterator<int>(cout, " "));
    assert(fibs[9] == 34);
    assert(fibs[14] == 377);
    cout << endl;
}

int main(){
    
    //Test TASK1
    // WordVec words = read_words_into_vector("words1.txt");
    // for(const auto& w:words){
    //     std::cout<<w<<std::endl;
    // }

    // std::cout<<std::endl;
    // std::cout<<std::endl;
    
    /*
    //Test TASK2
    WordMap map= map_and_count_words_using_lambda(words);
    for(const auto& [x,y]:map){
        std::cout<<x<<" "<<y<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<std::endl;

    //Test TASK3
    WordMap map2= map_and_count_words_using_functor(words);
    for(const auto& [x,y]:map2){
        std::cout<<x<<" "<<y<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<std::endl;

    //Test TASK4
    WordVec words2 = remove_duplicates(words);
    for(const auto& w:words2){
        std::cout<<w<<std::endl;
    }
    

    //Test TASK5
    if(is_palindrome("Hellooll5feH")){
        std::cout<<"This is a plain"<<std::endl;
    } else{
        std::cout<<"This is NOT a plain"<<std::endl;
    }
    */

    //TASK6
    // std::cout<<count_using_lambda(words,4)<<std::endl;
    // std::cout<<count_using_Functor(words,4)<<std::endl;
    // std::cout<<count_using_Free_Func(words,4)<<std::endl;


    //TASK7
    //multisetUsingMyComparator(words);


    // std::vector<long> Fib_vec = getnerate_Fibonacci(6);
    // for(const long& w:Fib_vec){
    //     std::cout<<w<<std::endl;
    // }

    // std::vector<long> Fib_vec1{1,2,3,5};
    // for(const long& w1:Fib_vec1){
    //     std::cout<<w1<<std::endl;
    // }

    task_8_test_driver(15);

    std::cout<<std::endl;
    std::cout<<std::endl;

    return 0;
}