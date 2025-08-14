#include "assignment5.h"


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
//TASK6: counting string by length using three methods
//a)
size_t count_using_lambda(const WordVec& vec, int n){
    auto lambda = [n](const std::string& str){return str.size()==n;};
    int final_count = std::count_if(vec.begin(), vec.end(), lambda);
    return final_count;
}

//b)
struct functor_count{
    int n;
    bool operator()(const std::string& str){
        return str.size()==n;
    }
};
size_t count_using_Functor(const WordVec& vec, int n){
    int final_count2 = std::count_if(vec.begin(), vec.end(), functor_count{n});
    return final_count2;
}

//c)
bool free_func_count(const std::string& str, int n){
    return str.size()==n;
}
size_t count_using_Free_Func(const WordVec& vec, int n){
    auto unaryFreeFunc = std::bind(free_func_count,std::placeholders::_1, n);
    int final_count3 = std::count_if(vec.begin(), vec.end(), unaryFreeFunc);
    return final_count3;
}

//=====================================================================================
//TASK7:

//a)

struct MyComparator{
    bool operator()(const std::string& str1, const std::string& str2) const {
        if (str1.size()<str2.size()){
            return true;
        }    
        else if(str1.size()==str2.size() && 
        str1.compare(str2)<0){
            return true;
        }
        else {
            return false;
        }
    }   
};

/*
auto MyComparator = [](const std::string& str1, const std::string& str2) {
    if (str1.size()<str2.size()){   
        return true;
    }    
    else if(str1.size()==str2.size() && 
    str1.compare(str2)<0){
            return true;
        }
        else {
            return false;
        }
};
*/

void multisetUsingMyComparator(const WordVec& vec){
    //step 1:
    std::multiset<std::string, MyComparator> wordSet;
    std::copy(vec.begin(), vec.end(), std::inserter(wordSet, wordSet.end()));

    //step 2:
    std::copy(wordSet.begin(), wordSet.end(), std::ostream_iterator<std::string>(std::cout," "));
}



//=====================================================================================
//TASK8:
struct Fibo{
    long n1=-1;
    long n2=1;
    long operator()(){
        long next = n1+n2;
        n1=n2;
        n2=next;
        return next;
    }
};

std::vector<long> getnerate_Fibonacci(int n){
    std::vector<long> vec(n);
    std::generate_n(vec.begin(), n, Fibo());
    return vec;
}

//=====================================================================================
//TASK9:
bool areAnagrams(const std::string& s1, const std::string& s2){
    std::string news1;
    std::string news2;

    std::copy_if(s1.begin(), s1.end(), std::back_inserter(news1), isalpha);
    std::transform(news1.begin(), news1.end(), news1.begin(), tolower);

    std::copy_if(s2.begin(), s2.end(),  std::back_inserter(news2), isalpha);
    std::transform(news2.begin(), news2.end(), news2.begin(), tolower);

    if(news1.size()!=news2.size()){
        return false;
    }

    std::sort(news1.begin(), news1.end());
    std::sort(news2.begin(), news2.end());

    return news1==news2;
}