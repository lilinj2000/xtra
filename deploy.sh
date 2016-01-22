#! /bin/sh

home_libs=~/libs

if test -d /llj/libs ; then
   home_libs=/llj/libs
fi

home_xtra=${home_libs}/xtra

./configure --prefix=${home_xtra}

if test -d ${home_xtra}; then
    rm -rf ${home_xtra}
fi

make install

make distclean
