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


```
./push_swap -374 144 -417 -488 291 332 -318 -287 -306 82 -223 357 -18 101 303 -34 461 422 -133 438 -201 339 343 -383 -403 -156 -36 290 37 292 -497 -486 -344 11 347 199 -26 -323 324 -184 -92 406 156 -214 -118 -472 -102 146 17 380 -376 244 96 -158 -481 71 166 -134 -233 -182 -173 451 -424 285 -176 216 52 -168 335 -94 -215 130 399 -69 39 90 -237 -397 219 -144 -274 -290 168 -136 -191 -59 320 271 -236 -430 -188 136 -467 187 364 -457 311 197 -75 432 204 31 372 143 -357 -440 -142 304 417 225 153 102 -151 -217 454 -29 -370 -22 -299 -369 -245 -366 293 151 13 91 -243 30 472 -355 -285 475 428 330 38 -211 -469 -105 -454 -13 -412 238 59 -88 -473 154 -433 315 407 202 -448 -490 114 249 251 124 -248 -103 -85 450 45 312 184 -277 -375 286 -324 381 -43 110 175 -164 -109 -25 108 405 492 -66 167 -220 -316 205 231 103 214 483 -328 -97 436 322 268 159 391 353 -121 -74 135 361 190 19 440 477 8 -314 -128 81 489 -20 -480 158 198 -384 208 -343 -141 -466 -179 -218 -187 494 -14 410 385 -200 443 359 -33 396 152 -166 -269 250 370 334 -198 278 388 -447 439 -250 376 495 -222 317 56 186 309 171 310 149 493 418 265 183 -495 160 206 7 79 180 -120 -93 69 211 -419 -192 296 470 -230 344 275 237 281 466 305 -139 390 -386 -434 -79 -57 -162 89 -37 86 -19 0 212 195 393 -213 -48 349 -110 -51 97 -399 -317 424 -425 2 -27 -415 -12 117 -178 -7 -265 10 -80 -461 367 430 -342 -172 -60 131 -298 -261 345 -137 -346 -500 445 1 -313 -138 -104 -341 -281 -390 -326 -203 -82 302 68 -257 323 331 -303 -398 -181 -235 -478 62 -333 -491 245 252 -354 20 -119 -71 -320 -127 -143 453 -332 -89 379 92 -401 -76 40 480 325 288 -315 -379 328 -492 254 -487 -275 -55 411 -286 -422 398 365 -310 401 300 -371 -125 127 458 -463 -44 193 277 -474 196 -361 18 119 24 120 12 456 -276 481 -130 276 49 427 354 29 -167 -155 -296 -442 -445 -389 316 -426 -418 104 132 375 191 298 378 -336 350 -254 239 60 -146 185 21 346 6 -393 246 -409 -263 169 106 -363 181 -301 -284 240 -485 -405 397 421 -238 382 435 200 318 -72 297 -322 389 5 -365 217 -309 -206 -70 -247 46 355 -193 55 -67 -107 -352 126 178 448 -450 140 -443 -335 54 473 487 43 -58 262 155 -126 465 -307 431 -329 -229 -177 -255 -244 -431 -131 -253 -61 234 -292 | wc -l
```
## Resources

References used during development...

AI usage...

## Algorithms 

> A detailed explanation and justification of the algorithms selected for this project must also be included.
