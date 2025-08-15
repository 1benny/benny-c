#!/bin/sh
wget "https://curl.se/download/curl-8.15.0.tar.gz"

tar -xzf curl-8.15.0.tar.gz
cd curl-8.15.0
./configure --with-openssl --prefix=../8.15.0

make
make install