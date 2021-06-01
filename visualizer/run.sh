ARG=`ruby -e "puts (1..500).to_a.shuffle.join(' ')"` ; ../push_swap/push_swap $ARG | ./visualizer $ARG
