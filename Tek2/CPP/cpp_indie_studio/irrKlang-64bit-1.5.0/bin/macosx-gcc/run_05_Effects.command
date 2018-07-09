#!/bin/sh

# this file starts the irrKlang example file, by making
# it possible to double click on it in the Finder. It only
# changes the finders current directory to the working directory
# and starts the app.

cd "$(dirname "$0")"
./05.Effects
