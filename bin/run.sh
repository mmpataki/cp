echo --------------------------------------

cd $1

function test_out() {
    if [ "$1" == "0" ]
    then
        echo -e "\033[32mSUCCESS"
    else
        echo -e "\033[31mFAILED"
    fi
    echo -e "\033[0m"
}

echo Compiling [$2]
if [ -f $3 ]
then
    rm -f $3
fi
g++ -g -fsanitize=address -Wall "$4" -o $3 $2
test_out $?

echo Running [$3]
if [ "$#" -gt "4" ]
then
    ./$3 < in | tee actout
    test_out $?
else
    echo "Will wait for input"
    ./$3 | tee actout
    test_out $?
fi

echo Testing [$3]
diff actout out
ecode=$?
test_out $ecode
