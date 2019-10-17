
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
__insert__,__unique_insert__,__remove__,__total_remove__,__search__,__quantity__,__prefix__.

##### what those methods does?

__insert__ :
    will put the string into the trie without checking if the trie already contains the same string

__unique_insert__ :
    will put the string into the trie checking if the trie already contains the same string and evenctually
    will not insert the string if is already stored.
    

