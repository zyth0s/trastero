
OUTPUT=`./hello`

if [ $OUTPUT == "hello" ]; then
    exit 0
else
    exit 1
fi
