#!/bin/bash

#****************************************
# BUILD DIRECTORY CREATION [1]
#****************************************
if [ ! -d "build" ]
then
    mkdir build

    echo "=%= build directory created =%="
fi


#****************************************
# USR-DIRECTORY CONTROL [2] 
#****************************************
if [ -d "$HOME/.mkhtml" ] && [ -d "$HOME/.mkhtml/cssgenerators" ] && [ -f "/usr/bin/mkhtml" ]
then
    # delete the files if they are exist in the system
    sudo rm -r "$HOME/.mkhtml"
    sudo rm /usr/bin/mkhtml

    echo "=%= file structure controlling =%="
    sleep 1
fi

#******************************************
# USR/SHARE/MAN DIRECTORY CONTROL [3]
#******************************************
if [ -f "/usr/share/man/man1/mkhtml.1.gz" ]
then
    sudo rm /usr/share/man/man1/mkhtml.1.gz

    echo "=%= man file controlling =%="
    sleep 1
fi

#****************************************
# COMPILING AND LINKING [4]
#****************************************
if [ -d "build" ]
then
    # run cmake and go to build directory then run makefiles
    cmake -S . -B build
    cd build && make

    # man page generation
    cp ../man/mkhtml.1 mkhtml.1

    # cssgenerator generation
    cp -r ../cssgenerators cssgenerators

    echo "=%= compiling and linking the project =%="
    sleep 1
fi

#****************************************
# MOVING THE EXECUTABLE TO USR/BIN [5]
#****************************************
if [ ! -f "/usr/bin/mkhtml" ]
then
    # move the mkhtml executable to usr/bin (exexcutable place)
    sudo mv src/app/mkhtml /usr/bin
    sudo mv mkhtml.1 /usr/share/man/man1
    sudo gzip /usr/share/man/man1/mkhtml.1

    echo "=%= moving the executable to usr/bin =%="
    sleep 1
fi

#****************************************
# CREATING MKHTML FOLDER TO HOME [6]
#****************************************
if [ ! -d "$HOME/.mkhtml" ]
then
    mkdir "$HOME/.mkhtml"
    sudo chmod 775 "$HOME/.mkhtml"
    
    sudo mv cssgenerators "$HOME/.mkhtml"
    
    touch "$HOME/.mkhtml/settings.txt"
    sudo chmod 775 "$HOME/.mkhtml/settings.txt"
    echo "noapikey:empty" > "$HOME/.mkhtml/settings.txt"

    echo "=%= creating the mkhtml folder to home =%="
    sleep 1
fi

#****************************************
# DELETING THE SOURCE BUILD DIRECTORY [7]
#****************************************
#cd .. && rm -r build

echo "=%= removing the build directory =%="
sleep 1

if [ -d "$HOME/.mkhtml" ] && [ -d "$HOME/.mkhtml/cssgenerators" ] && [ -f "/usr/bin/mkhtml" ] && [ -f "$HOME/.mkhtml/settings.txt" ] && [  -f "/usr/share/man/man1/mkhtml.1.gz" ]
then 
    sudo echo "=%= mkhtml installation succesful =%="
else
    sudo echo "=%= mkhtml installation unsuccesful =%="
fi