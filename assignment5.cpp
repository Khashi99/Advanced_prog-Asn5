#include "assignment5.h"
#include <fstream>
#include <iterator>
#include <stdexcept>

//TASK1
WordVec read_words_into_vector(const std::string& inFileName){
    
    WordVec words_vector;

    //To open the file
    std::ifstream inputfile(inFileName);

    if(!inputfile.is_open()){throw std::runtime_error("File not opened correctly. Please check the file name!");}

    std::istream_iterator<std::string> begin_iter(inputfile);
    std::istream_iterator<std::string> end_iter;

    std::copy(begin_iter, end_iter, std::back_inserter(words_vector));

    return words_vector;
}   


//TASK2
WordMap map_and_count_words_using_lambda(const WordVec& wVec){
    WordMap wMap; 
    std::for_each(wVec.begin(),wVec.end(),[&](const std::string& word){++wMap[word];});
    return wMap;
}


//TASK3
WordMap map_and_count_words_using_functor(const WordVec& wVec){
    struct WordCountFunctor{
    private:
        WordMap wMap;
    public:
        void operator()(const std::string& word){
            ++wMap[word];
        }
        WordMap getMap(){
            return wMap;
        }
    };
    WordCountFunctor wcf;
    wcf = std::for_each(wVec.begin(), wVec.end(), wcf);
    return wcf.getMap();
}


//TASK4

