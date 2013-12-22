#include <cstdio> // easier than iostream for formatted output
#include <iostream>
#include <iterator>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
typedef std::map<std::string, std::size_t> WordCountMapType;

WordCountMapType wordsInFile(const char * const fileName)   // for each word
{                                                           // in file, return
    std::ifstream file(fileName);                           // # of
    WordCountMapType wordCounts;                            // occurrences
    for (std::string word; file >> word; ) {
        ++wordCounts[word];
    }
    return wordCounts;
}

struct Ptr2Pair2ndGT {                                                                  // compare 2nd
    template<typename It>                                                               // components of
    bool operator()(It it1, It it2) const { return it1->second > it2->second; }         // pointed-to pairs
};

template<typename MapIt>                                            // print n most
void showCommonWords(MapIt begin, MapIt end, const std::size_t n)   // common words
{                                                                   // in [begin, end)
    typedef std::vector<MapIt> TempContainerType;
    typedef typename TempContainerType::iterator IterType;
    TempContainerType wordIters;
    wordIters.reserve(std::distance(begin, end));
    for (MapIt i = begin; i != end; ++i) wordIters.push_back(i);
    IterType sortedRangeEnd = wordIters.begin() + n;
    std::partial_sort(wordIters.begin(), sortedRangeEnd, wordIters.end(), Ptr2Pair2ndGT());
    for (IterType it = wordIters.begin();
        it != sortedRangeEnd;
        ++it) {
                std::printf(" %-10s%10u\n", (*it)->first.c_str(), (*it)->second);
    }
}


int main(int argc, const char** argv)                   // take list of file names on command line,
{                                                       // print 20 most common words within
    WordCountMapType wordCounts;
    for (int argNum = 1; argNum < argc; ++argNum) {
        const WordCountMapType results =                // copy map returned by
        wordsInFile(argv[argNum]);                      // wordsInFile (modulo
                                                        // compiler optimization)
    for ( WordCountMapType::const_iterator i = results.begin();
          i != results.end();
          ++i) {
                wordCounts[i->first] += i->second;
    }
}
std::cout << wordCounts.size() << " words found. Most common:\n" ;
const std::size_t maxWordsToShow = 20;
showCommonWords( wordCounts.begin(), wordCounts.end(),
std::min(wordCounts.size(), maxWordsToShow));
}
