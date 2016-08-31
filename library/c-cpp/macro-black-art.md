#MACRO Black Arts

## Convert MACRO or its value into const string

```c
#define XSTR(macro) STR(macro)
#define STR(macro)  #macro

#define VALUE       23

/*
 * STR(VALUE)   ->  "VALUE"
 * XSTR(VALUE)  ->  "23"
 *
 */
```

[Source](https://gcc.gnu.org/onlinedocs/cpp/Stringification.html)
