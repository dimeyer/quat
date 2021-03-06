#!/usr/bin/env bash

OS=mac
PROJECT=fltk
VERSION="1.3.3"
DL_URL="http://fltk.org/pub/fltk/$VERSION/fltk-$VERSION-source.tar.gz"

SCRIPT_DIR=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
MAIN_DIR="$SCRIPT_DIR/.."
TARGET_DIR="$MAIN_DIR/libs/$PROJECT"
PROJECT_DIR="$MAIN_DIR/tmp/$PROJECT"
DOWNLOAD="$PROJECT_DIR/$PROJECT-$VERSION.tar.gz"
SRC_DIR="$PROJECT_DIR/src"
BUILD_DIR="$SRC_DIR/$PROJECT-$VERSION"

function indent {
    sed  's/^/     /'
}

function doPrepare {
    if [ -d "$SRC_DIR" ]; then
        rm -rf "$SRC_DIR"
    fi
    if [ -d "$TARGET_DIR" ]; then
        rm -rf "$TARGET_DIR"
    fi
    mkdir -p "$PROJECT_DIR"
    mkdir -p "$TARGET_DIR"
    mkdir -p "$SRC_DIR"
}

function doDownload {
    if [ ! -f "$DOWNLOAD" ]; then
        curl "$DL_URL" -o "$DOWNLOAD"
    fi
}

function doUnzip {
    tar xzf "$DOWNLOAD" -C "$SRC_DIR"
}

function doConfigure {
    ./configure --help > "$PROJECT_DIR/options.txt"
    ./configure \
            --quiet \
            --prefix="$BUILD_DIR"\
            --disable-localzlib \
            --disable-localjpeg \
            --disable-localpng
}

function doBuild {
    cd "$SRC_DIR/$PROJECT-$VERSION"

    export CC="clang"
    export CXX="clang++"
    export LDFLAGS="-L/opt/local/lib -lc++"
    export CPPFLAGS="-I/opt/local/include"
    export CXXFLAGS="-std=c++03 -stdlib=libc++ -mmacosx-version-min=10.7"
    export CFLAGS="-I/opt/local/include -mmacosx-version-min=10.7"

    # debug
    (export CXXFLAGS="$CXXFLAGS -g -O0"; \
    export CFLAGS="$CFLAGS -g -O0"; \
    doConfigure)
    make -j8 install prefix="$BUILD_DIR/debug"

    # release
    (export CXXFLAGS="$CXXFLAGS -msse2 -Ofast -finline -ffast-math -funsafe-math-optimizations"; \
    export CFLAGS="$CFLAGS -msse2 -Ofast -finline -ffast-math -funsafe-math-optimizations"; \
    doConfigure)
    make -j8 install prefix="$BUILD_DIR/release"
}

function doCopy {
    mkdir -p "$TARGET_DIR/bin/$OS/debug"
    mkdir -p "$TARGET_DIR/bin/$OS/release"
    mkdir -p "$TARGET_DIR/include"
    cp -r "$BUILD_DIR/debug/lib"/* "$TARGET_DIR/bin/$OS/debug"
    cp -r "$BUILD_DIR/release/lib"/* "$TARGET_DIR/bin/$OS/release"
    cp -r "$BUILD_DIR/release/include/"* "$TARGET_DIR/include"
}


echo "Prepare"
doPrepare | indent

echo "Download"
doDownload | indent

echo "Unzip"
doUnzip | indent

echo "Build"
doBuild 2>&1 | indent

echo "Copy"
doCopy | indent
