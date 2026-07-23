*This project has been created as part of the 42 curriculum by iscarval and ferde-so.*

# Push Swap

## Description

`push_swap` is...

The main goal of this project is...

### Files

- `main.c` - the main function that gets the parameters.
- `flag_parser.c` - functions to parse the flags.
- `printer` - functions to print characters on the standard output.
- `stack_creation.c` - functions to create nodes and stacks, and to clear them.
- `stack_utils.c` - auxiliar functions to validade the parameters.
- `stack_debug.c` - auxiliar functions to validade the stacks.
- `logic.c` - the logic functions that call the other functions.
- `operation_push.c` - push operations.
- `operation_swap.c` - swap operations.
- `operation_rotate.c` - rotate operations.
- `operation_reverse_rotate.c` - reverse rotate operations.
- `algorithm_small.c` - functions for sorting short stacks.
- `algorithm_simple` - functions to sort by the simple algorithm.
- `algorithm_medium` - functions to sort by the medium algorithm.
- `algorithm_complex` - functions to sort by the complex algorithm.

### Functions

...

## Instructions

After cloning or downloading the repository, compile and use the program like this:

1. Open a terminal in the `push_swap` directory.
2. Run `make` to build the program.

Example:

```sh
make
```

To clean build files:

```sh
make clean
```

To remove compiled objects and the executable:

```sh
make fclean
```

To rebuild everything from scratch:

```sh
make re
```

One example of how to run the program with parameters:

```sh
./push_swap 5 200 0 4 -50 25
```

Where `5 200 0 4 -50 25` is any sequence of integers.

Other option:

```
./push_swap 100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
```

```
./push_swap --medium -347 -343 -238 333 342 430 -244 133 -483 -450 -406 55 -479 -33 -368 -12 304 252 414 -434 -196 -237 -101 -361 -315 490 106 6 -84 -221 -121 444 336 -338 407 142 -140 -297 -451 -325 391 257 -73 472 326 -272 144 -372 -416 412 268 -152 182 147 149 23 63 416 285 -10 -253 5 389 -290 -71 -51 -296 162 348 -119 163 487 421 282 78 377 -280 -488 101 -37 -189 -285 254 -427 363 226 228 -356 224 -75 122 180 -45 48 -108 382 88 -6 284 -447 334 366 -425 -449 -142 185 37 -262 -468 380 -216 265 -24 174 435 396 216 47 -182 337 -86 49 -91 35 339 291 52 -494 -417 87 -173 -443 -134 -261 56 -42 -419 12 80 -302 500 139 -210 -222 130 -69 199 -176 379 -44 -163 411 431 -255 196 -392 279 300 -459 -215 290 393 315 -467 375 305 246 83 10 190 198 154 -170 -433 -232 232 -199 -9 -83 217 -429 -444 -257 -41 -168 -50 172 109 453 137 -337 369 211 -498 -345 -275 -402 419 136 -370 -258 -14 -362 -477 364 -268 -70 179 -380 223 102 -104 -2 -437 107 256 497 -482 475 354 -271 -201 -375 86 -484 -287 427 255 368 341 485 -424 192 -397 359 -151 124 288 -445 295 -113 -311 372 100 -155 -500 -114 443 367 145 -126 325 376 95 230 -52 68 397 181 -323 465 -478 370 383 128 -138 -212 140 299 -164 450 -144 165 -469 -159 392 405 -172 -147 125 -492 -68 156 -379 479 64 229 -348 -252 -180 -465 103 -439 119 1 75 455 -486 -239 24 | wc -l
```

## Resources

References used during development...

AI usage...

## Algorithms 

> A detailed explanation and justification of the algorithms selected for this project must also be included.
