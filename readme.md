This is a wordle solver project. In it, you can find two sh files.
compile_for_use.sh: Compiles the program if you want to use it to solve your wordle puzzle.
compile_for_test.sh: Compiles the program to find the frequency for the number of words needed to solve the wordle. Note that the executable takes around 40 min to run and outputs a lot of stuff into the console (so that you know it is working).

When you use the solver, enter the colours wordle gives you as a 5 letter string with bs for black, ys for yellow, and gs for green.
For example, put bbgyg for black-black-green-yellow-green.
If you decide not to put the recommended word, put the word you typed in, followed by the answer given as one continuous string of 10 letters with no spaces or other characters in between (5 for the word you typed and 5 for the colours).
For example, if you put hello and the response is bbgyg, put hellobbgyg.

This project was inspired by [3b1b's video](https://www.youtube.com/watch?v=v68zYyaEmEA).

STATISTICS
104 words took 2 guesses
930 words took 3 guesses
989 words took 4 guesses
227 words took 5 guesses
49 words took 6 guesses
12 words took 7 guesses
4 words took 8 guesses
Average: 3.67 guesses per word