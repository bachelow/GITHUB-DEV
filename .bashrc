# ~/.bashrc: executed by bash(1) for non-login shells.
# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
# for examples

# If not running interactively, don't do anything
case $- in
    *i*) ;;
      *) return;;
esac

# don't put duplicate lines or lines starting with space in the history.
# See bash(1) for more options
HISTCONTROL=ignoreboth

# append to the history file, don't overwrite it
shopt -s histappend

# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
HISTSIZE=1000
HISTFILESIZE=2000

# check the window size after each command and, if necessary,
# update the values of LINES and COLUMNS.
shopt -s checkwinsize

# If set, the pattern "**" used in a pathname expansion context will
# match all files and zero or more directories and subdirectories.
#shopt -s globstar

# make less more friendly for non-text input files, see lesspipe(1)
[ -x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"

# set variable identifying the chroot you work in (used in the prompt below)
if [ -z "${debian_chroot:-}" ] && [ -r /etc/debian_chroot ]; then
    debian_chroot=$(cat /etc/debian_chroot)
fi

# set a fancy prompt (non-color, unless we know we "want" color)
case "$TERM" in
    xterm-color|*-256color) color_prompt=yes;;
esac

# uncomment for a colored prompt, if the terminal has the capability; turned
# off by default to not distract the user: the focus in a terminal window
# should be on the output of commands, not on the prompt
#force_color_prompt=yes

if [ -n "$force_color_prompt" ]; then
    if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then
	# We have color support; assume it's compliant with Ecma-48
	# (ISO/IEC-6429). (Lack of such support is extremely rare, and such
	# a case would tend to support setf rather than setaf.)
	color_prompt=yes
    else
	color_prompt=
    fi
fi

if [ "$color_prompt" = yes ]; then
    PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '
else
    PS1='${debian_chroot:+($debian_chroot)}\u@\h:\w\$ '
fi
unset color_prompt force_color_prompt

# If this is an xterm set the title to user@host:dir
case "$TERM" in
xterm*|rxvt*)
    PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]$PS1"
    ;;
*)
    ;;
esac

# enable color support of ls and also add handy aliases
if [ -x /usr/bin/dircolors ]; then
    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
    alias ls='ls --color=auto'
    #alias dir='dir --color=auto'
    #alias vdir='vdir --color=auto'

    alias grep='grep --color=auto'
    alias fgrep='fgrep --color=auto'
    alias egrep='egrep --color=auto'
fi

# colored GCC warnings and errors
#export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'

# some more ls aliases
alias ll='ls -alF'
alias la='ls -A'
alias l='ls -CF'

# Add an "alert" alias for long running commands.  Use like so:
#   sleep 10; alert
alias alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echo error)" "$(history|tail -n1|sed -e '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"'

# Alias definitions.
# You may want to put all your additions into a separate file like
# ~/.bash_aliases, instead of adding them here directly.
# See /usr/share/doc/bash-doc/examples in the bash-doc package.

if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
fi

# enable programmable completion features (you don't need to enable
# this, if it's already enabled in /etc/bash.bashrc and /etc/profile
# sources /etc/bash.bashrc).
if ! shopt -oq posix; then
  if [ -f /usr/share/bash-completion/bash_completion ]; then
    . /usr/share/bash-completion/bash_completion
  elif [ -f /etc/bash_completion ]; then
    . /etc/bash_completion
  fi
fi

export RESPYTHONPATH=~/ownCloud/Shared/network/r328


function creermakefilebasic(){
    if [ $# == 2 ]
    then
        touch Makefile;
 
        echo "$2: main.o $1.o">> Makefile
        echo -e "\tg++ -o $2 main.o $1.o\n" >> Makefile
        echo "main.o: main.cpp $1.h" >> Makefile
        echo -e "\tg++ -o main.o -c main.cpp\n" >> Makefile
        echo "$1.o: $1.cpp" >> Makefile
        echo -e "\tg++ -o $1.o -c $1.cpp\n" >> Makefile
        echo "clean:" >> Makefile
        echo -e "\trm -f *.o *~" >> Makefile
        echo "mrproper: clean" >> Makefile
        echo -e '\trm ./'$2'' >> Makefile
 
        echo 'création du Makefile done.';
 
    else
        echo 'il faut 2 argu, ici : '$#;
        echo '$1 = nom des fichiers .h et .cpp sans son extension (1 argu)';
        echo '$2'" = nom de l'executable";
 
    fi
}
 
function creermakefilebeau(){
    if [ $# == 2 ]
    then
        touch Makefile;
 
        echo "CXX=g++" >> Makefile
        echo "GNU=-std=gnu++11" >> Makefile
        echo "headers=headers/" >> Makefile
        echo "src=sources/" >> Makefile
        echo "obj=obj/" >> Makefile
        echo "projet=$2" >> Makefile
        echo "" >> Makefile
        echo '${projet} : ${obj}main.o ${obj}'$1'.o'>> Makefile
        echo -e '\t${CXX} ${GNU} -o ${projet} -g ${obj}main.o ${obj}'$1'.o\n' >> Makefile
        echo '${obj}main.o : ${src}main.cpp' >> Makefile
        echo -e '\t${CXX} ${GNU} -o ${obj}main.o -c ${src}main.cpp\n' >> Makefile
        echo '${obj}'$1'.o : ${src}'$1'.cpp ${headers}'$1'.h' >> Makefile
        echo -e '\t${CXX} ${GNU} -o ${obj}'$1'.o -c ${src}'$1'.cpp\n' >> Makefile
        echo "clean:" >> Makefile
        echo -e '\trm -f ${obj}*' >> Makefile
        echo "mrproper: clean" >> Makefile
        echo -e '\trm ./${projet}' >> Makefile
 
        echo 'création Makefile du projet done.';
 
    else
        echo 'il faut 2 argu, ici : '$#;
        echo '$1 = nom des fichiers .h et .cpp sans son extension (1 argu/1ere class)';
        echo '$2'" = nom de l'executable";
 
    fi
}
 
function creermaincpp(){
    if [ $# == 0 ]
    then
        touch main.cpp;
   
        echo "#include <iostream>">> main.cpp
        echo "">> main.cpp
        echo "using namespace std;">> main.cpp
        echo "">> main.cpp
        echo "int main(){">> main.cpp
        echo "">> main.cpp
        echo -e '\tcout << "FAIGNANT" << endl;'>> main.cpp
        echo "">> main.cpp
        echo -e "\treturn 0;">> main.cpp
        echo "}">> main.cpp
 
        echo 'création du main done.';
    fi
   
    if [ $# == 1 ]
    then
        touch main.cpp;
   
        echo "#include <iostream>">> main.cpp
        echo '#include "'$1'.h"'>> main.cpp
        echo "">> main.cpp
        echo "using namespace std;">> main.cpp
        echo "">> main.cpp
        echo "int main(){">> main.cpp
        echo "">> main.cpp
        echo -e '\tcout << "FAIGNANT" << endl;'>> main.cpp
        echo "">> main.cpp
        echo -e "\treturn 0;">> main.cpp
        echo "}">> main.cpp
 
        echo 'création du main done.';
    fi
   
    if [ $# != 0 ] && [ $# != 1 ]
    then
        echo 'il faut 0 ou 1 argu, ici : '$#;
        echo '$1 = nom du fichier .h sans extension';
    fi
}
 
function creermainprojetcpp(){
    if [ $# == 0 ]
    then
        touch main.cpp;
   
        echo "#include <iostream>">> main.cpp
        echo "">> main.cpp
        echo "using namespace std;">> main.cpp
        echo "">> main.cpp
        echo "int main(){">> main.cpp
        echo "">> main.cpp
        echo -e '\tcout << "FAIGNANT" << endl;'>> main.cpp
        echo "">> main.cpp
        echo -e "\treturn 0;">> main.cpp
        echo "}">> main.cpp
 
        echo 'création main du projet done.';
    fi
   
    if [ $# == 1 ]
    then
        touch main.cpp;
   
        echo "#include <iostream>">> main.cpp
        echo '#include "../headers/'$1'.h"'>> main.cpp
        echo "">> main.cpp
        echo "using namespace std;">> main.cpp
        echo "">> main.cpp
        echo "int main(){">> main.cpp
        echo "">> main.cpp
        echo -e '\tcout << "FAIGNANT" << endl;'>> main.cpp
        echo "">> main.cpp
        echo -e "\treturn 0;">> main.cpp
        echo "}">> main.cpp
 
        echo 'création main du projet done.';
    fi
   
    if [ $# != 0 ] && [ $# != 1 ]
    then
        echo 'il faut 0 ou 1 argu, ici : '$#;
        echo '$1 = nom du fichier .h sans extension';
    fi
}
 
function creerclasscpp(){
    if [ $# == 1 ]
    then
   
        touch $1.cpp;
   
        echo "#include <iostream>" >> $1.cpp
        echo '#include "'$1'.h"' >> $1.cpp
        echo "" >> $1.cpp
        echo "using namespace std;" >> $1.cpp
        echo "" >> $1.cpp
        echo "$1::$1(){" >> $1.cpp
        echo "" >> $1.cpp
        echo "}" >> $1.cpp
        echo "" >> $1.cpp
        echo "$1::~$1(){" >> $1.cpp
        echo "" >> $1.cpp
        echo "}" >> $1.cpp
   
        touch $1.h;
   
        echo "#pragma once" >> $1.h
        echo "#include <iostream>" >> $1.h
        echo "" >> $1.h
        echo "class $1" >> $1.h
        echo "{" >> $1.h
        echo -e "\tprivate: //variables" >> $1.h
        echo -e "\t" >> $1.h
        echo -e "\tpublic:  //methodes" >> $1.h
        echo -e "\t" >> $1.h
        echo -e "\t$1();" >> $1.h
        echo -e "\t~$1();" >> $1.h
        echo -e "\t" >> $1.h
        echo "};" >> $1.h
 
        echo 'création de la class '$1' done.';
   
    else
        echo 'il faut 1 argu, ici : '$#;
        echo '$1 = nom de la class';
   
    fi
}
 
function creerclassprojetcpp(){
    if [ $# == 1 ]
    then
   
        cd sources;
        touch $1.cpp;
   
        echo "#include <iostream>" >> $1.cpp
        echo '#include "../headers/'$1'.h"' >> $1.cpp
        echo "" >> $1.cpp
        echo "using namespace std;" >> $1.cpp
        echo "" >> $1.cpp
        echo "$1::$1(){" >> $1.cpp
        echo "" >> $1.cpp
        echo "}" >> $1.cpp
        echo "" >> $1.cpp
        echo "$1::~$1(){" >> $1.cpp
        echo "" >> $1.cpp
        echo "}" >> $1.cpp
   
        cd ../headers;
   
        touch $1.h;
   
        echo "#pragma once" >> $1.h
        echo "#include <iostream>" >> $1.h
        echo "" >> $1.h
        echo "class $1" >> $1.h
        echo "{" >> $1.h
        echo -e "\tprivate: //variables" >> $1.h
        echo -e "\t" >> $1.h
        echo -e "\tpublic:  //methodes" >> $1.h
        echo -e "\t" >> $1.h
        echo -e "\t$1();" >> $1.h
        echo -e "\t~$1();" >> $1.h
        echo -e "\t" >> $1.h
        echo "};" >> $1.h
   
        cd ..;
 
        echo 'création class '$1' du projet done.';
   
    else
        echo 'il faut 1 argu, ici : '$#;
        echo '$1 = nom de la class';
        echo 'Il faut être dans le dossier du projet ! (où il y a headers, sources etc...)';
   
    fi
}
 
function creerprojetrapidecpp(){
    if [ $# == 3 ]
    then
   
        mkdir $1;
        cd $1;
 
        creermakefilebasic $2 $3;
 
        creermaincpp $2;
 
        creerclasscpp $2;
 
        echo 'création du projet done.';
 
    else
        echo 'il faut 3 argu, ici : '$#;
        echo '$1 = nom du projet';
        echo '$2 = nom de la 1ere class';
        echo '$3'" = nom de l'executable";
   
    fi
}
 
function creerprojetbeaucpp(){
    if [ $# == 3 ]
    then
   
        mkdir $1;
        cd $1;
 
        creermakefilebeau $2 $3;
        mkdir headers;
        mkdir obj;
        mkdir sources;
   
        cd sources;
        creermainprojetcpp $2;
        cd ..;
 
        creerclassprojetcpp $2;
 
        echo 'création du projet done.';
 
    else
        echo 'il faut 3 argu, ici : '$#;
        echo '$1 = nom du projet';
        echo '$2 = nom de la 1ere class';
        echo '$3'" = nom de l'executable";
   
    fi
}
 
##############################################################  PARTIE JAVA ###################################################################
 
function creerclassjava(){
    if [ $# == 1 ]
    then
 
        touch $1.java;
 
        echo "public class $1{" >> $1.java
        echo -e "\t//variables" >> $1.java
        echo "" >> $1.java
        echo -e "\t//methodes" >> $1.java
        echo -e "\tpublic $1(){" >> $1.java
        echo "" >> $1.java
        echo -e "\t}" >> $1.java
        echo "" >> $1.java
        echo "}" >> $1.java
 
        echo "création de la class $1 done.";
 
    else
        echo 'il faut 1 argu, ici : '$#;
        echo '$1 = nom de la class';
 
    fi
}
 
function creermainjava(){
    if [ $# == 1 ]
    then
 
        touch $1.java;
 
        echo "public class $1{" >> $1.java
        echo -e "\tpublic static void main(String[] args) {" >> $1.java
        echo "" >> $1.java
        echo -e "\t}" >> $1.java
        echo "}" >> $1.java
 
        echo "création du main $1 done.";
 
    else
        echo 'il faut 1 argu, ici : '$#;
        echo '$1 = nom du main';
 
    fi
}
