Build from Source Code
======================
The following software packages are required for building ubongo-utils
from source code.  They must have been installed before you start
installation procedure of ubongo-utils.

* C++ compiler with STL (Standard Template Library)

'Solver' and 'Analyzer' of ubongo-utils are written in C++.

* Ruby

'HTML Converter' of ubongo-utils is written in Ruby.
ubongo-utils also uses Ruby for generating source codes.

* ImageMagick

'HTML Converter' of ubongo-utils uses 'convert' command of ImageMagick
to generate PNG files.

Change the directory where source files of ubongo-utils reside,

    $ cd /somewhere/on/your/computer

Execute the configure script.

    $ ./configure

By default, ubongo-utils will be installed under '/usr/local'.
If you would like change the directory, specify '--prefix' option:

    $ ./configure --prefix=/usr/local/ubongo-utils

`configure` recognizes many options.  Run

    $ ./configure --help

to see the list of options for more details.

Type 'make' to compile the software.

    $ make

Run 'make install' to install programs, data files and documents.
Usually, it requires root privilege.  With 'sudo' command, type:

    $ sudo make install

or try becoming root using 'su' and then run 'make install'.

    $ su
    Password:
    # make install
