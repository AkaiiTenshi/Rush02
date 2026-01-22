# Rush02 - Parsing a dictionnary to convert number into words

### Goal

The aim of this project is to read a dictionnary, and use it to process a given number,
and print it in words.

For example: 42 --> forty two.

---

### How ? 

In order to achieve this I used functions that are a part of the Piscine's curriculum mainly, and I tried 
to utilize notions that are seen in previous rushes or projects. 

I this implementation, you'll see a recursive function, an example of how usefull 'split' is, and also how 
linked lists are a very powerfull alternative to an array of strings (char **).

---

## Important Notions

### 1. Dynamic Size Without Reallocation **With linked lists:** You can
allocate memory on-the-fly as you parse each dictionary line. Each valid entry
becomes a new node, and you append it immediately without knowing the total
count upfront. **With arrays:** You face two bad choices:
- Read the file twice (once to count lines, once to parse) - wasteful
- Pre-allocate a huge array and waste memory - inefficient
- Need to realloc (implement something similar to realloc()) repeatedly as you parse - expensive O(n) copying 
(meaning the more you reallocate, the more time it takes, because you have to get the old pointers, and the new ones)

In this
  project , we parse line-by-line and reject
  invalid/duplicate entries on-the-fly. Linked lists handle this naturally with
  zero overhead.

### 2. Structured Data with Type Safety **With linked lists:** Each node is a
proper structure containing both the numeric key AND its word value together:
```c
typedef struct s_dict_pair { unsigned long    nbr;      // The number(e.g., 42) 
char            *value;    // The word (e.g., "forty two") struct
s_dict_pair *next; } t_dict_pair; 
``` 
This means:
- The compiler enforces type safety: nbr is always a number, value is always a
  string
- Related data stays together - you can't accidentally misalign them
- Code is self-documenting: entry->nbr and entry->value are crystal clear.With
  arrays: You either maintain parallel arrays (unsigned long keys[] and char
  *values[]) which can get out of sync, or you store everything as strings
  ("42:forty two") and parse repeatedly during lookups - both approaches are
  error-prone and inefficient.


---

Everything else in the codebase is just personnal preferences, I used a recursive function for my algorithm, didn't have to
but it was fun. There surely is an easier to approach method to solve the problem.
