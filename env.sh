alias cdcf="cd ~/cp/cf"
alias cdcc="cd ~/cp/cc"

windows=0
read os </proc/sys/kernel/osrelease || :
if [[ "$os" == *Microsoft ]]; then
          windows=1
fi

#editors
GEANY="geany"

if [ "$windows" == "1" ]
then
        GEANY="geany.exe"
fi

ED="$GEANY"
# ED="vim"

function opcp {     # pass a problem name (extension not reqd)
	if ! [ -d "$1" ]
	then
		mkdir "$1"
		cp -f /mnt/c/work/cp/template.cpp "$1/sol.cpp"
		touch "$1/in"
	fi
	$ED "$1/in"
	$ED "$1/sol.cpp"
}

function build {
	cd `echo "$1" | sed 's/[\\:]/\//g' | sed 's/C\//\/mnt\/c/g'`
	g++ -Wall -O2 -o $3 $2
}
