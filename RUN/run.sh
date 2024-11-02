#!/bin/bash

cd ../
cd build
./premake5 gmake2
cd ../
make
cd bin/Debug
./GachaWR


#!gcc -o main main.c characters.c game.c player.c gacha.c -I. Lets leave this just in case I need it later
#!./main
#!/bin/bash
