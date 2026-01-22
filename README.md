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

### Linked lists

This is typically a project where using linked lists is more convenient than using an array of strings. Here are the reasons:

* Dynamic size allocation.
With the linked lists you can allocate the exact size of you dictionnary, meaning you have exactly as many nodes allocated as there are, in our case, lines in your dictionnary.
If you were to use an array of strings, you'd either have to read the file once, get the number of line then allocate, or you'd have to allocate something way bigger than what 
you actually need, then (because we want to something clean) reallocate it after cleaning every empty array. Wherease with linked lists, you can parse and allocate on the fly.
AND THAT'S NOT ALL! The structured data that comes with linked lists makes the codebase so much clearer.
