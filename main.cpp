#include "macro.hpp"
#include "trie.hpp"
#include "methods.hpp"

call
{
    trie t;
    t.insert("fag");
    t.insert("fag");
    t.insert("fagioli");
    t.insert("fagiolini");
    t.insert("rag");
    t.insert("fango");
    t.insert("filo");  

    auto k = t.prefix("fa");
    
    for ( auto & kk : k ) std::cout << kk << std::endl;   
}
