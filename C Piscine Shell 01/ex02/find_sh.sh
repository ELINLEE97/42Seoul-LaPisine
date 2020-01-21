#!/bin/sh
find . -maxdepth 2 -name '*.sh' -exec basename {} \; | sed 's/\.sh//'
