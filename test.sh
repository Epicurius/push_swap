echo "5 values:"
ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"` ;  ./push_swap/push_swap $ARG | ./checker/checker $ARG
echo "10 values:"
ARG=`ruby -e "puts (1..10).to_a.shuffle.join(' ')"` ;  ./push_swap/push_swap $ARG | ./checker/checker $ARG
echo "100 values:"
ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ; ./push_swap/push_swap $ARG | ./checker/checker $ARG
echo "200 values:"
ARG=`ruby -e "puts (1..200).to_a.shuffle.join(' ')"` ; ./push_swap/push_swap $ARG | ./checker/checker $ARG
echo "300 values:"
ARG=`ruby -e "puts (1..300).to_a.shuffle.join(' ')"` ; ./push_swap/push_swap $ARG | ./checker/checker $ARG
echo "400 values:"
ARG=`ruby -e "puts (1..400).to_a.shuffle.join(' ')"` ; ./push_swap/push_swap $ARG | ./checker/checker $ARG
echo "500 values:"
ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"` ; ./push_swap/push_swap $ARG | ./checker/checker $ARG
echo "600 values:"
ARG=`ruby -e "puts (1..600).to_a.shuffle.join(' ')"` ; ./push_swap/push_swap $ARG | ./checker/checker $ARG
echo "700 values:"
ARG=`ruby -e "puts (1..700).to_a.shuffle.join(' ')"` ; ./push_swap/push_swap $ARG | ./checker/checker $ARG
