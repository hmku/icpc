#!/bin/bash
find . -type f ! -name "*.cpp" ! -name "*.sh" ! -name "*.py" ! -name "*.pdf" ! -name "*.in" -exec rm {} \;