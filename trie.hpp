#pragma once
#include <iostream>
#include <vector>
#include <string>


struct trie
{
    protected:
        struct node
        {
            node * parent;
            char value;
            std::vector<node> childrens;
        };
        node head;

    public:
        void                                clear();                               
        void                                insert(std::string);                   
        void                                remove(std::string);                   
        bool                                search(std::string);                   
        std::vector<std::string>            prefix(std::string);                   
        void                                unique_insert(std::string);            
        void                                total_remove(std::string);             
        int                                 quantity(std::string);               

    protected:
        static node* find(std::vector<node> & vec , node & n);
        static bool is_there( std::vector<node> & vec, node & n);
        static std::vector<std::string> collect(std::vector<node> & vec);
};


