ubongo-utils
============
ubongo-utils is a set of utilities for Ubongo, Ubongo Mini, Ubongo Duel
and Ubongo 3-D puzzle games designed by Grzegorz Rejchtman.
Ubongo Extreme (hexagonal tiles) or Ubongo Trigo (triangle tiles) is
not supported.  It runs on UNIX based operating systems including Linux.
All utilities are designed to be invoked on a command line.  

ubongo-utils currently provides the following programs:

* Solver
* Analyzer
* HTML converter

In the next three sections, I explain how to use those utility programs.


Solver
------
The 'Solver' utility solves a puzzle.  ubongo-utils provides a solver
command for each Ubongo variant.

* `ubongo-solve-orig`   (for Ubongo)
* `ubongo-solve-duel`   (for Ubongo Duel)
* `ubongo-solve-minib`  (for Ubongo Mini - blue tiles)
* `ubongo-solve-minig`  (for Ubongo Mini - green tiles)
* `ubongo-solve-minir`  (for Ubongo Mini - red tiles)
* `ubongo-solve-miniy`  (for Ubongo Mini - yellow tiles)
* `ubongo-solve-3d`     (for Ubongo 3-D)

Specifying shape of a board and pieces placed on it, 'Solver' outputs
its solutions.  The shape of a board is represented with a text file.
Here is an example:

    .###.
    #####
    ###.#
    ###.#

Each character '#' is a square printed on the board.  The actual board
corresponding with the text file above looks like:

<div class="example">
<img src="board1.png" alt="an image of a board">
</div>

To specify pieces placed on the board, upper letters ('A', 'B', 'C' ...)
are used.  An unique letter is assigned to each piece in an Ubongo
variant.

Ubongo:

<table>
<tr>
<td>A:<img src="orig-piece-A.png" alt="Ubongo A"></td>
<td>B:<img src="orig-piece-B.png" alt="Ubongo B"></td>
<td>C:<img src="orig-piece-C.png" alt="Ubongo C"></td>
<td>D:<img src="orig-piece-D.png" alt="Ubongo D"></td>
<td>E:<img src="orig-piece-E.png" alt="Ubongo E"></td>
<td>F:<img src="orig-piece-F.png" alt="Ubongo F"></td>
<td>G:<img src="orig-piece-G.png" alt="Ubongo G"></td>
<td>H:<img src="orig-piece-H.png" alt="Ubongo H"></td>
</tr>
<tr>
<td>I:<img src="orig-piece-I.png" alt="Ubongo I"></td>
<td>J:<img src="orig-piece-J.png" alt="Ubongo J"></td>
<td>K:<img src="orig-piece-K.png" alt="Ubongo K"></td>
<td>L:<img src="orig-piece-L.png" alt="Ubongo L"></td>
<td></td>
<td></td>
<td></td>
<td></td>
</tr>
</table>

Ubongo Duel:

<table>
<tr>
<td>A:<img src="duel-piece-A.png" alt="Duel A"></td>
<td>B:<img src="duel-piece-B.png" alt="Duel B"></td>
<td>C:<img src="duel-piece-C.png" alt="Duel C"></td>
<td>D:<img src="duel-piece-D.png" alt="Duel D"></td>
<td>E:<img src="duel-piece-E.png" alt="Duel E"></td>
<td>F:<img src="duel-piece-F.png" alt="Duel F"></td>
<td>G:<img src="duel-piece-G.png" alt="Duel G"></td>
<td>H:<img src="duel-piece-H.png" alt="Duel H"></td>
</tr>
<tr>
<td>I:<img src="duel-piece-I.png" alt="Duel I"></td>
<td>J:<img src="duel-piece-J.png" alt="Duel J"></td>
<td>K:<img src="duel-piece-K.png" alt="Duel K"></td>
<td>L:<img src="duel-piece-L.png" alt="Duel L"></td>
<td>M:<img src="duel-piece-M.png" alt="Duel M"></td>
<td>N:<img src="duel-piece-N.png" alt="Duel N"></td>
<td>O:<img src="duel-piece-O.png" alt="Duel O"></td>
<td>P:<img src="duel-piece-P.png" alt="Duel P"></td>
</tr>
<tr>
<td>Q:<img src="duel-piece-Q.png" alt="Duel Q"></td>
<td>R:<img src="duel-piece-R.png" alt="Duel R"></td>
<td>S:<img src="duel-piece-S.png" alt="Duel S"></td>
<td>T:<img src="duel-piece-T.png" alt="Duel T"></td>
<td>U:<img src="duel-piece-U.png" alt="Duel U"></td>
<td></td>
<td></td>
<td></td>
</tr>
</table>

Ubongo Mini - Blue Tiles:

<table>
<tr>
<td>A:<img src="minib-piece-A.png" alt="Mini Blue A"></td>
<td>B:<img src="minib-piece-B.png" alt="Mini Blue B"></td>
<td>C:<img src="minib-piece-C.png" alt="Mini Blue C"></td>
<td>D:<img src="minib-piece-D.png" alt="Mini Blue D"></td>
<td>E:<img src="minib-piece-E.png" alt="Mini Blue E"></td>
<td>F:<img src="minib-piece-F.png" alt="Mini Blue F"></td>
<td>G:<img src="minib-piece-G.png" alt="Mini Blue G"></td>
</tr>
</table>

Ubongo Mini - Green Tiles:

<table>
<tr>
<td>A:<img src="minig-piece-A.png" alt="Mini Green A"></td>
<td>B:<img src="minig-piece-B.png" alt="Mini Green B"></td>
<td>C:<img src="minig-piece-C.png" alt="Mini Green C"></td>
<td>D:<img src="minig-piece-D.png" alt="Mini Green D"></td>
<td>E:<img src="minig-piece-E.png" alt="Mini Green E"></td>
<td>F:<img src="minig-piece-F.png" alt="Mini Green F"></td>
<td>G:<img src="minig-piece-G.png" alt="Mini Green G"></td>
</tr>
</table>

Ubongo Mini - Red Tiles:

<table>
<tr>
<td>A:<img src="minir-piece-A.png" alt="Mini Red A"></td>
<td>B:<img src="minir-piece-B.png" alt="Mini Red B"></td>
<td>C:<img src="minir-piece-C.png" alt="Mini Red C"></td>
<td>D:<img src="minir-piece-D.png" alt="Mini Red D"></td>
<td>E:<img src="minir-piece-E.png" alt="Mini Red E"></td>
<td>F:<img src="minir-piece-F.png" alt="Mini Red F"></td>
<td>G:<img src="minir-piece-G.png" alt="Mini Red G"></td>
</tr>
</table>

Ubongo Mini - Yellow Tiles:

<table>
<tr>
<td>A:<img src="miniy-piece-A.png" alt="Mini Yellow A"></td>
<td>B:<img src="miniy-piece-B.png" alt="Mini Yellow B"></td>
<td>C:<img src="miniy-piece-C.png" alt="Mini Yellow C"></td>
<td>D:<img src="miniy-piece-D.png" alt="Mini Yellow D"></td>
<td>E:<img src="miniy-piece-E.png" alt="Mini Yellow E"></td>
<td>F:<img src="miniy-piece-F.png" alt="Mini Yellow F"></td>
<td>G:<img src="miniy-piece-G.png" alt="Mini Yellow G"></td>
</tr>
</table>

Ubongo 3-D:

<table>
<tr>
<td>A:<img src="3d-piece-A.png" alt="3-D A"></td>
<td>B:<img src="3d-piece-B.png" alt="3-D B"></td>
<td>C:<img src="3d-piece-C.png" alt="3-D C"></td>
<td>D:<img src="3d-piece-D.png" alt="3-D D"></td>
<td>E:<img src="3d-piece-E.png" alt="3-D E"></td>
<td>F:<img src="3d-piece-F.png" alt="3-D F"></td>
<td>G:<img src="3d-piece-G.png" alt="3-D G"></td>
<td>H:<img src="3d-piece-H.png" alt="3-D H"></td>
</tr>
<tr>
<td>I:<img src="3d-piece-I.png" alt="3-D I"></td>
<td>J:<img src="3d-piece-J.png" alt="3-D J"></td>
<td>K:<img src="3d-piece-K.png" alt="3-D K"></td>
<td>L:<img src="3d-piece-L.png" alt="3-D L"></td>
<td>M:<img src="3d-piece-M.png" alt="3-D M"></td>
<td>N:<img src="3d-piece-N.png" alt="3-D N"></td>
<td>O:<img src="3d-piece-O.png" alt="3-D O"></td>
<td>P:<img src="3d-piece-P.png" alt="3-D P"></td>
</tr>
</table>

Suppose that you'd like to solve a puzzle for Ubongo Duel, with the
board above saved as the text file 'board1.txt', and with the piece
'C', 'L' and 'R'.  Type the following line to execute the solver.

    $ ubongo-solve-duel board1.txt C L R

The 'Solver' program, the 'ubongo-solve-duel' command, will output
a solution:

    * C L R
    .LLC.
    LLRCC
    RLR.C
    RRR.C

It means that the solution looks like:

<div class="example">
<img src="solution1.png" alt="an image of a solution">
</div>

'Solver' program for Ubongo 3-D, 'ubongo-solve-3d' command, outputs
text data slightly different from other solver programs:

    FFOE
    .FFE
    ====
    FOOO
    .EEE

The lines before the horizontal rule '====' represents the second level
(i.e. the first floor) of the solution and lines after the horizontal
rule are the first level (i.e. the ground floor), respectively.

The common form of the solver commands is:

    solver-program [option...] BOARD-FILE PIECE...

or

    solver-program [option...] -f PROBLEM-FILE BOARD-FILE

PIECE is an upper letter ('A', 'B', 'C' ...) assigned to a piece.
PROBLEM-FILE is a file which describes combinations of pieces, one 
combination per a line.  An example of PROBLEM-FILE is shown below:

    * A C P
    * B C E
    * B C M
    * B C N
    * B C P
    * B C R

When PROBLEM-FILE is specified, the solver tries to solve all puzzles
described in the file.  Note that result data output by 'Analyzer' 
(described later) can also be used as PROBLEM-FILE.
You can specify either PROBLEM-FILE or PIECE, but not both.

The solver programs recognize the options described below:

* -a, --all

By default, the solver programs display only one solution.  Specifying
this option, solvers output all solution of the puzzle.

* -f FILE, --file FILE

Read a list of combinations of pieces from FILE.

* -h, --help

Print command line usage, then exits.

* -v, --version

Print a version number, then exits.

The solver programs exit with the exit code 0 (success) even when the
puzzle has no solution.


Analyzer
--------
The 'Analyzer' utility is similar to 'Solver', but it assists you in
creating puzzles.  Specifying a board file and how many pieces are
placed on it, 'Analyzer' outputs all solvable combinations of pieces.

Suppose that you'd like to create three piece puzzles of Ubongo Duel.
Since there are 21 kinds of pieces in Ubongo Duel, 'Analyzer' tries
solving

C(21, 3) = (21 * 20 * 19) / (3 * 2 * 1) = 1330

ways of combinations of pieces, and it outputs all solvable combinations
of pieces for the given board, like this:

    $ ubongo-analyze-duel board1.txt 3
    .###.
    #####
    ###.#
    ###.#
    ; squares=16

    * A C P ; solutions=1
    * B C E ; solutions=1
    * B C M ; solutions=1
    * B C N ; solutions=1
    * B C P ; solutions=1
    * B C R ; solutions=2
    * C D H ; solutions=1
    * C I T ; solutions=1
    * C L R ; solutions=1
    * C N U ; solutions=1
    * C O S ; solutions=1
    * C Q T ; solutions=1
    * C R T ; solutions=1
    ; puzzles=13

Same as 'Solver', ubongo-utils also provides an analyzer command for
each Ubongo variant.

* `ubongo-analyze-orig`   (for Ubongo)
* `ubongo-analyze-duel`   (for Ubongo Duel)
* `ubongo-analyze-minib`  (for Ubongo Mini - blue tiles)
* `ubongo-analyze-minig`  (for Ubongo Mini - green tiles)
* `ubongo-analyze-minir`  (for Ubongo Mini - red tiles)
* `ubongo-analyze-miniy`  (for Ubongo Mini - yellow tiles)
* `ubongo-analyze-3d`     (for Ubongo 3-D)

In output data, a character ';' means beginning of a comment.  Each
comment ends with a newline.  'Analyzer' also outputs solutions if
the '--show-solution' option is specified:

    $ ubongo-analyze-duel --show-solution board1.txt 3
    .###.
    #####
    ###.#
    ###.#
    ; squares=16

    * A C P ; solutions=1
    .PPC.
    PPACC
    PPA.C
    AAA.C

    * B C E ; solutions=1
    .EEC.
    EEECC
    BBE.C
    BBB.C

    * B C M ; solutions=1
    .MMC.
    (snip)

The common form of the analyzer commands is:

    analyzer-program [option...] BOARD-FILE NPIECES

The format of BOARD-FILE is the same as that of 'Solver'.
NPIECIES must be an integer greater than zero.
The analyzer programs recognize the following options:

* -a, --all-solutions

Show all solutions.  This option implies '--show-solution'.

* -h, --help

Print command line usage, then exits.

* -m N, --max-solutions=N

Output solvable combinations of pieces with N solutions or less only.

* -s, --show-solution

Also output a solution.

* -v, --version

Print a version number, then exits.

The analyzer programs exit with the exit code 0 (success) even when
it has reported no solvable combinations of pieces.


HTML Converter
--------------
'HTML converter' converts a text file to an HTML file and PNG image
files.  The text file may contains one of the following data:

* Shapes of boards
* Solutions output by 'Solver'
* A list of combinations of pieces output by 'Analyzer'

Same as 'Solver' and 'Analyzer', ubongo-utils provides a converter
command for each Ubongo variant.

* `ubongo-html-orig`   (for Ubongo)
* `ubongo-html-duel`   (for Ubongo Duel)
* `ubongo-html-minib`  (for Ubongo Mini - blue tiles)
* `ubongo-html-minig`  (for Ubongo Mini - green tiles)
* `ubongo-html-minir`  (for Ubongo Mini - red tiles)
* `ubongo-html-miniy`  (for Ubongo Mini - yellow tiles)

If you'd like to convert the board file 'board1.txt' for Ubongo Duel,
type:

    $ ubongo-html-duel board1.txt

It generates 'board1.html' and some PNG files at the current directory.
The created HTML page looks like:

<div class="example">
<img src="board1.png" alt="">
</div>

If you want to create an HTML page of a solution, do it like this way:

    $ ubongo-solve-duel board1.txt C L R > solution1.txt
    $ ubongo-html-duel solution1.txt

It generates 'solution1.html' and PNG files at the current directory.
The HTML page looks like:

<div class="example">
Board:<br>
<img src="board1.png" alt=""><br>
<hr>
No.1:&nbsp;
<img src="duel-piece-small-R.png" alt="R">
<img src="duel-piece-small-C.png" alt="C">
<img src="duel-piece-small-L.png" alt="L">
<br>
<img src="./solution1.png" alt="">
</div>

To convert a list of combinations of pieces, run the following commands:

    $ ubongo-analyze-duel board1.txt 3 > combinations1.txt
    $ ubongo-html-duel --problem combinations.txt

It makes 'combinations1.html' and PNG files.  The HTML page looks like:

<div class="example">
Board:<br>
<img src="board1.png" alt=""><br>
<hr>
No.1:&nbsp;
<img src="duel-piece-small-R.png" alt="R">
<img src="duel-piece-small-C.png" alt="C">
<img src="duel-piece-small-L.png" alt="L">
<br>
<hr>
No.2:&nbsp;
<img src="duel-piece-small-C.png" alt="C">
<img src="duel-piece-small-B.png" alt="B">
<img src="duel-piece-small-E.png" alt="E">
<br>
<hr>
No.3:&nbsp;
<img src="duel-piece-small-M.png" alt="M">
<img src="duel-piece-small-C.png" alt="C">
<img src="duel-piece-small-B.png" alt="B">
<br>
(snip)
</div>

'combinations1.html' may contains solutions.  'HTML Converter' also
converts solutions.

    $ ubongo-analyze-duel --solution board1.txt 3 > combinations1.txt
    $ ubongo-html-duel combinations.txt

The generated HTML page looks like:

<div class="example">
Board:<br>
<img src="board1.png" alt=""><br>
<hr>
No.1:&nbsp;
<img src="duel-piece-small-R.png" alt="R">
<img src="duel-piece-small-C.png" alt="C">
<img src="duel-piece-small-L.png" alt="L">
<br>
<img src="solution1.png" alt="">
<hr>
No.2:&nbsp;
<img src="duel-piece-small-C.png" alt="C">
<img src="duel-piece-small-B.png" alt="B">
<img src="duel-piece-small-E.png" alt="E">
<br>
<img src="solution2.png" alt="">
<hr>
No.3:&nbsp;
<img src="duel-piece-small-N.png" alt="N">
<img src="duel-piece-small-C.png" alt="C">
<img src="duel-piece-small-B.png" alt="B">
<br>
<img src="solution3.png" alt="">
<br>
(snip)
</div>

The common form of the analyzer commands is:

    html-converter-program [option...] TEXT-FILE

The 'HTML Converter' programs recognize the following options:

* -b BASENAME, --basename=BASENAME

Create an HTML file with the filename 'BASENAME.html' and create PNG
files for representing board and solutions with the filenames starting
with 'BASENAME-'.  The default value is basename of TEXT-FILE.

This option changes basenames of output files.  To change an output
directory, use '--output-prefix' instead.

* -h, --help

Print command line usage, then exits.

* -p, --problem

Do not output solutions.  Output problems (combinations of pieces)
only.

* -o PREFIX, --output-prefix=PREFIX

Generate an HTML file at the directory PREFIX.  This options also
changes locations of PNG files generated by 'HTML Converter'.
The default value is '.'.  Also see description of '--basename',
'--board-directory', '--solution-directory' and '--piece-directory'
options.

* -v, --version

Print a version number, then exits.

* --problem-size=SIZE

Specify size of PNG files for representing pieces as problems.
In generated image files, pieces consist of squares with sides SIZE
pixels.  'HTML Converter' for Ubongo 3-D ignores this option.
The default value is 6. 

* --board-size=SIZE

Specify size of PNG files for representing boards.  In generated image
files, boards consist of squares with sides SIZE pixels.
The default value is 16 

* --solution-size=SIZE

Specify size of PNG files for representing solutions.  In generated
image files, solutions consist of squares with sides SIZE pixels.
The default value is 16. 

* --board-directory=DIR

Create PNG files for representing boards at the directory DIR.
relative to a directory where an HTML file resides.  For example,
specifying 'images/boards' as DIR, the generated HTML page contains
'img' tags like:

    <img src="images/boards/x-board.png" alt="">

The default value is '.'. 

* --solution-directory=DIR

Create PNG files for representing solutions at the directory DIR,
relative to a directory where an HTML file resides.  For example,
specifying 'images/solutions' as DIR, the generated HTML page contains
'img' tags like:

    <img src="images/solutions/x-solution-001-00002.png" alt="">

The default value is '.'. 

* --piece-directory=DIR

Creates PNG files for representing pieces at the directory DIR, 
relative to a directory where an HTML file resides.  For example,
specifying 'images/pieces' as DIR, the generated HTML page contains
'img' tags like:

    <img src="images/pieces/piece-a.png" alt="A">

The default value is '.'. 

* --title=TITLE

Specify title of an HTML page.
The default value is "<GAME TITLE> Problems" if '--problem' option
is specifed, or "<GAME TITLE> Solutions" otherwise.
<GAME TITLE> here is "Ubongo", "Ubongo Duel", "Ubongo Mini" or
"Ubongo 3-D".
