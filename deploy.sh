#! /bin/sh

node=`uname -n`
home_3rd=~/3rd/${node}
home_libs=~/libs/${node}


home_xtra=${home_libs}/xtra

./configure --prefix=${home_xtra}

if test -d ${home_xtra}; then
    rm -rf ${home_xtra}
fi

make install

make distclean
