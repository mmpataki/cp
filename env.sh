alias cdcf="cd ~/cp/cf"
alias cdcc="cd ~/cp/cc"

windows=0
read os </proc/sys/kernel/osrelease || :
if [[ "$os" == *Microsoft ]]; then
          windows=1
fi

#editors
GEANY="geany"
VIM="vim"
VSCODE="code"

if [ "$windows" == "1" ]
then
        GEANY="geany.exe"
fi

# ED="$GEANY"
# ED="$VIM"
ED="$VSCODE"

function opcp {     # pass a problem name (extension not reqd)
	if ! [ -d "$1" ]
	then
		mkdir -p "$1"
		cp -f ~/cp/template.cpp "$1/sol.cpp"
		touch "$1/in"
		touch "$1/out"
	fi
	$ED "$1/in"
	$ED "$1/out"
	$ED "$1/sol.cpp"
}
