#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stdexcept>

void trie::clear() 
{
    head.childrens.clear();
}

void trie::insert(std::string str)
{str+="\n";

    node* parent = &head;
    node tmp;

    for ( char & c : str )
    {
        tmp.value = c;
        if ( is_there(parent->childrens,tmp) && c != '\n' )
        {
            parent = find(parent->childrens,tmp);
        } 
        else
        {
            tmp.parent = parent;
            parent->childrens.emplace_back(tmp);
            parent = find(parent->childrens,tmp);
        }
    }
}

void trie::unique_insert(std::string str)
{str+="\n";

    node* parent = &head;
    node tmp;

    for ( char & c : str )
    {

        tmp.value = c;
        if ( is_there(parent->childrens,tmp) )
        {
            parent = find(parent->childrens,tmp);
        } 
        else
        {
            tmp.parent = parent;
            parent->childrens.emplace_back(tmp);
            parent = find(parent->childrens,tmp);
        }
    }
}

bool trie::search(std::string str)
{str+="\n";
    
    node * parent = &head;
    node tmp;

    for ( char & c : str )
    {
        tmp.value = c;
        if ( is_there(parent->childrens,tmp) )
        {
            parent = find(parent->childrens,tmp);
        }
        else 
        {
            return false;
        }
    }

    return true;
}

int trie::quantity(std::string str)
{
    node * parent = &head;
    node tmp;

    for ( char & c : str )
    {
        tmp.value = c;
        if ( is_there(parent->childrens, tmp))
        {
            parent = find(parent->childrens, tmp);
        }
        else
        {
            return 0;
        }
    }

    return (int)std::count_if(parent->childrens.begin(),parent->childrens.end(),[](node & n){return n.value == '\n' ; });
}

void trie::remove(std::string str)
{str+="\n";
    node * parent = &head;
    node tmp;

    for ( char & c : str )
    {
        tmp.value = c;
        if ( is_there(parent->childrens, tmp))
        {
            parent = find(parent->childrens, tmp);
        }
        else
        {
            return;
        }
    }

    char b;
    while ( parent->childrens.size() < 1 && parent != &head ) 
    {
        b = parent->value;
        parent = parent->parent;
        parent->childrens.erase(std::find_if(parent->childrens.begin(),parent->childrens.end(),[&b](node & n){return n.value == b;}));
    }
}

void trie::total_remove(std::string str)
{
    while ( this->search(str))
    {
        this->remove(str);
    }
}

std::vector<std::string> trie::collect(std::vector<node> & vec)
{
    std::vector<std::string> res, tmp;
    std::string str;

    for ( node & n : vec )
    {
        tmp.clear();
        str.clear();

        if ( n.value != '\n')
        {
            tmp = collect(n.childrens);
            for ( auto & s : tmp )
            {
                s.insert(s.begin(),n.value);
                res.emplace_back(s);
            }
        }
        else
        {
            res.emplace_back("\n");
        }
        
    }
    return res;
};

std::vector<std::string> trie::prefix(std::string str)
{
    std::vector<std::string> res;
    node * parent = &head;
    node tmp;

    for ( char & c : str )
    {
        tmp.value = c;
        if ( is_there(parent->childrens, tmp))
        {
            parent = find(parent->childrens, tmp);
        }
        else 
        {
            return res;
        }
    }

    res = collect(parent->childrens);
    for ( auto & s : res )
    { 
        s = str + s;
    }
    return res;
}

bool trie::is_there( std::vector<node> & vec, node & n)
{
    for ( node & nn : vec )
    {
        if ( n.value == nn.value )
        {
            return true;
        }
    }
    return false;
};

trie::node* trie::find(std::vector<node> & vec , node & n)
{
    for ( node & nn : vec )
    {
        if ( n.value == nn.value )
        {
            return &nn;
        }
    }

    return &n;
};
