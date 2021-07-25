# Lexical-Analyzer in C++

## Introduction

Lexical Analysis is the first phase of compiler used for specifying `patter-action language` called `Lex`. Its main task is to read the input character and produce as output a sequence of `tokens` that the parser uses for syntax analysis.

In this project, Lexical Analyzer reads the input from the `input.txt` file and display all the tokens in input file in the `Output` File.


![image](https://user-images.githubusercontent.com/58816552/126887075-a9666d5d-c81f-4eae-a690-2eda8967f7dd.png)


## Tokens, Patterns & Lexemes

`Tokens` are the sequence of characters that can be treated as a unit/single logical entity.

`Pattern` are the set of rules for formation of tokens from input character.

`Lexemes` are a sequence of char in source program matched by a pattern for a token.
 e.g., Pascal statement const pi = 3.1416;
the substring pi is a lexeme from the token “identifier”

When talking about lexical analysis, we use the terms "token," "pattern," and "lexeme" with specific meanings. 

### Examples of Tokens

![toekn (1)](https://user-images.githubusercontent.com/58816552/126888680-06cf04ad-b97c-433b-a334-5c4f6d9557e2.png)

## Task of Lexical Analyzer

1. Generating a sequence of tokens.
2. Striping out comments and whitespace.
3. Making copy of source program with error message marked in it.


