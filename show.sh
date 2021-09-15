ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"` ; ./push_swap/push_swap $ARG | ./visualizer/visualizer $ARG
