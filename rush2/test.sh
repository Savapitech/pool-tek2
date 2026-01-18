INVALID_CMD="invalid"

run_test() {
    TEST_NAME="$1"
    CMD="$2"
    REF="$3"
    
    echo "[TEST] $TEST_NAME"
    OUTPUT_CUSTOM=$(sh -c "$CMD")

    if [ "$REF" == "$OUTPUT_CUSTOM" ]; then
        echo "✅ Success"
    else
        echo "❌ Failure"
        echo "  🔹 Reference  : $REF"
        echo "  🔹 My checker : $OUTPUT_CUSTOM"
    fi
    echo "--------------------------------------------"
}

wget https://cdn.vyme.net/push_swap 2> /dev/null && chmod +x ./push_swap
run_test "Subject ref" "echo 'sa pb pb pb sa pa pa pa' | ./pushswap_checker 2 1 3 6 5 8" "OK" 0
run_test "Subject ref KO" "echo 'sa pb pb pb sa pa pa' | ./pushswap_checker 2 1 3 6 5 8" "KO: ([2,3,5,6,8],[1])" 84
run_test "Other KO" "echo 'sa pb pb pb' | ./pushswap_checker 2 1 3 6 5 8" "KO: ([6,5,8],[3,2,1])" 84
run_test "Unknown op" "echo 'aaaaaaa' | ./pushswap_checker 2 1 3 6 5 8" "KO: ([],[])" 84
run_test "Already sorted" "echo '' | ./pushswap_checker 1 2 3" "OK" 0
run_test "Not enough args" "./pushswap_checker" "" 0
bash generator.sh 10 > gen
run_test "Big 10" './push_swap $(cat gen) | ./pushswap_checker $(cat gen)' "OK" 0
bash generator.sh 100 > gen
run_test "Big 100" './push_swap $(cat gen) | ./pushswap_checker $(cat gen)' "OK" 0
bash generator.sh 1000 > gen
run_test "Big 1000" './push_swap $(cat gen) | ./pushswap_checker $(cat gen)' "OK" 0
bash generator.sh 10000 > gen
run_test "Big 10000" './push_swap $(cat gen) | ./pushswap_checker $(cat gen)' "OK" 0
