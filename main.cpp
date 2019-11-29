//eMail:        francescodero@outlook.it
//Telegram:     @fDero 

#include "trie.hpp"

int main()
{
    trie t;
    t.insert("computer");
    t.insert("compton");
    t.insert("cat");
    t.insert("dog");
    t.insert("thunder");
    t.insert("tunnel");
    t.insert("rope");  

    auto k = t.prefix("co");
    
    for ( auto & kk : k ) std::cout << kk << std::endl;   
}
