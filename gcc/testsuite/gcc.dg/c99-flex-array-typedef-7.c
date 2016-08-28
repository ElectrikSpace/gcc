/* Initialization of a flexible array member with a string constant
   must be diagnosed.  PR 37481.  */
/* { dg-do compile } */
/* { dg-options "-std=iso9899:1999 -pedantic-errors" } */

typedef char T[];
struct s { int a; T b; };

struct s a = { 0, "" }; /* { dg-error "initialization of a flexible array member" } */
/* { dg-message "near init" "near init" { target *-*-* } 9 } */
struct s b = { 0, { 0 } }; /* { dg-error "initialization of a flexible array member" } */
/* { dg-message "near init" "near init" { target *-*-* } 11 } */
struct s c = { 0, { } }; /* { dg-error "ISO C forbids empty initializer braces" } */
struct s d = { .b = "" }; /* { dg-error "initialization of a flexible array member" } */
/* { dg-message "near init" "near init" { target *-*-* } 14 } */
struct s e = { .b = { 0 } }; /* { dg-error "initialization of a flexible array member" } */
/* { dg-message "near init" "near init" { target *-*-* } 16 } */
struct s f = { .b = { } }; /* { dg-error "ISO C forbids empty initializer braces" } */
