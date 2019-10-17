
# Trie

```
Is a kind of ordered tree data structure used to store a 
dynamic set or associative array where the keys are usually strings.
Unlike a binary search tree, no node in the tree stores the key associated with that node.
instead, its position in the tree defines the key with which it is associated.
All the descendants of a node have a common prefix of the string associated
with that node, and the root is associated with the empty string.
Keys tend to be associated with leaves, though some inner nodes
may correspond to keys of interest.
```
~ Wikipedia

---

### User Guide

##### how can i use this?

Just include "trie.hpp" in your project. this file will contain a class named _trie_.
_trie_ class will have the following methods:
_insert_,_unique_insert_,_remove_,_total_remove_,_search_,_quantity_,_prefix_.

##### what those methods does?

_insert_ :
    will put the string into the trie without checking if the trie already contains the same string.

_unique_insert_ :
    will put the string into the trie checking if the trie already contains the same string and evenctually
    will not insert the string if is already stored.
    
_remove_ :
    will remove the string once, if that string will be found, otherwise does nothing.

_total_remove_:
    removes the strings every times it will be found, if will be found no string matching, does nothing.
    
_search_:
    returns true if is there any string matching the string passed, otherwise return false.
    
_quantity_:
    returns how many strings matching the passed string the trie actually contains.
    
_prefix_:
    returns an _std::vector<std::string>_ rappresenting every string starting with the passed prefix.
    
---

eMail: francescodero@outlook.it
Telegram: @fDero

