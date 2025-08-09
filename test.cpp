#include "assignment5.h"
#include <iostream>
//using namespace std;

int main(){
    /*
    //Test TASK1
    WordVec words = read_words_into_vector("words1.txt");
    for(const auto& w:words){
        std::cout<<w<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<std::endl;

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
    */

    //Test TASK5
    if(is_palindrome("Hellooll5feH")){
        std::cout<<"This is a plain"<<std::endl;
    } else{
        std::cout<<"This is NOT a plain"<<std::endl;
    }


    return 0;
}