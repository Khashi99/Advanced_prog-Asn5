#include "assignment5.h"
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <cctype>

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

//=====================================================================================
//TASK2
WordMap map_and_count_words_using_lambda(const WordVec& wVec){
    WordMap wMap; 
    std::for_each(wVec.begin(),wVec.end(),[&](const std::string& word){++wMap[word];});
    return wMap;
}

//=====================================================================================
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

//=====================================================================================
//TASK4
WordVec remove_duplicates(const WordVec& words_vector){
    WordVec removed_duplicates;
    removed_duplicates = words_vector;

    std::sort(removed_duplicates.begin(), removed_duplicates.end());
    auto it_to_new_end = std::unique(removed_duplicates.begin(), removed_duplicates.end());

    removed_duplicates.erase(it_to_new_end, removed_duplicates.end());

    return removed_duplicates;
}

//=====================================================================================
//TASK5 
// free funtion that returns true for true for non-apha chars
bool is_alphabetic(unsigned char c) {
    return !std::isalpha(c); 
}

bool is_palindrome(const std::string& phrase){
    std::string temp;

    std::remove_copy_if(phrase.begin(), phrase.end(), std::back_inserter(temp), is_alphabetic);

    std::transform(temp.begin(), temp.end(), temp.begin(), [](unsigned char c) { return std::tolower(c);});

    return std::equal(temp.begin(), temp.begin() + temp.size()/2, temp.rbegin());
}

//=====================================================================================
//TASK6

