#! /bin/sh

aclocal \
&& libtoolize \
&& automake --gnu --add-missing \
&& autoconf

if [ -e ./configure ]; then
    echo
    echo "You can now run ./configure"
    echo
else
    echo
    echo "Failure building the configure script."
    echo "You may miss required tools (aclocal 1.9, libtoolize, automake 1.9, autoconf 2.5x) to build libduptools"
    echo "Please install the appropriated package and re-run autogen.sh"
    echo "This might also happen if you don't have the m4 provided as a subdirectory in this package in the directory"
    echo "where aclocal will find them. Just copy ./m4/* in, usually, /usr/share/aclocal."
    echo
fi
