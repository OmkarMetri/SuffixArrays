# SuffixArray
Construction of suffix tree and pattern matching

## data.txt:
First line indicates no of test cases
Subsequent lines indicate the pattern to be searched.

## Execution commands:
$ make -f makefile

$ ./SuffixArray < data.txt

### Unique inputs:
1. whitespace with a new line character is also an input.
2. "re e" <-- Only occurence of it at index 254, i.e, it is treated as lone pattern even though separated by whitespace.

