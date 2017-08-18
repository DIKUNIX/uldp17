# Unix-Like Data Processing 2017

## Challenges

[Jon Bentley](https://en.wikipedia.org/wiki/Jon_Bentley_(computer_scientist)),
a renowned computer scientist, known for the [k-d tree data
structure](https://en.wikipedia.org/wiki/K-d_tree), [once
asked](http://dl.acm.org/citation.cfm?id=315644) [Donald
Knuth](https://en.wikipedia.org/wiki/Donald_Knuth), another renowned computer
scientist, known for his foundational volumes on [The Art of Computer
Programming](https://en.wikipedia.org/wiki/The_Art_of_Computer_Programming), to
write a program that: Reads a file, determines the _n_ most frequently used
words in that file, and prints a sorted list of those words, along with their
frequencies.

Knuth's [original program](http://dl.acm.org/citation.cfm?id=315654) used a
fancy data structure, and required more than 10 "pages" of Pascal. [Doug
McIlroy](https://en.wikipedia.org/wiki/Douglas_McIlroy), one of the Unix
pioneers [responded](http://dl.acm.org/citation.cfm?id=315654) with the
following 6-stage shell pipeline:

```
tr -cs A-Za-z '\n' | \
  tr A-Z a-z | \
  sort | \
  uniq -c | \
  sort -rn | \
  sed ${1}q
```

We encourage you present us with similar challenges in our
[Issues](https://github.com/DIKUNIX/uldp17/issues). In our experience, these
can make for great exercises in our notes.
