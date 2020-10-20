alias cdcf="cd ~/cp/cf"
alias cdcc="cd ~/cp/cc"

function opcp {     # pass a problem name (extension not reqd)
	if ! [ -d "$1" ]
	then
		mkdir "$1"
		cp -f ~/cp/template.cpp "$1/sol.cpp"
	fi
	geany "$1/sol.cpp"
}

