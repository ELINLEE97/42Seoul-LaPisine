#!/bin/sh
find . -maxdepth 2 -type f -name '*.sh' -exec basename {} \; | sed 's/\.sh$//'
