set -e    # if error, stop the build
cc -g -std=c99 -c -I /opt/raylib/src linux_platform.c -o ./obj/linux_platform.o
cc -g -std=c99 -c -I /opt/raylib/src splash.c -o ./obj/splash.o
cc -g -std=c99 -c -I /opt/raylib/src menu.c -o ./obj/menu.o
cc -g -std=c99 -c -I /opt/raylib/src gameplay.c -o ./obj/gameplay.o
cc -o linux_platform  obj/linux_platform.o obj/splash.o obj/menu.o obj/gameplay.o -s -Wall -std=c99 -I/opt/raylib/src -L/opt/raylib/release/libs/linux -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./linux_platform
