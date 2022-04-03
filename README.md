# ROB305: Multi-tasking design and Real Time Operating System

*Author : Yu WANG*

## For environment with *cmake*

### TD_1
```
cd TD_1
cmake .
```

#### TD_1_a
```
make main_td1a
./main_td1a
```

#### TD_1_b
```
make main_td1b
./main_td1b
```

#### TD_1_c
```
make main_td1c
./main_td1c <nLoops>
```

#### TD_1_d
```
make main_td1d
./main_td1d
```

#### TD_1_e
```
make main_td1e
./main_td1e 
```


### TD_2
```
cd TD_2
cmake .
```

#### TD_2_a
```
make main_td2a
./main_td2a <nLoops> <nTasks>
```

#### TD_2_b
```
make main_td2b
./main_td2b <nLoops> <nTasks> <schedPolicy>
```
The choices of parameter *schedPolicy* are: SCHED_RR, SCHED_FIFO and OTHER

#### TD_2_c
```
make main_td2c
./main_td2c <nLoops> <nTasks> <schedPolicy> <protect>
```
The choices of parameter *schedPolicy* are: SCHED_RR, SCHED_FIFO and OTHER  
Parameter *protect* is not mandatory (1 is true, 0 is false)


### TD_3
```
cd TD_3
cmake .
```

#### TD_3_a
```
make main_td3a
./main_td3a
```

#### TD_3_b
```
make main_td3b
./main_td3b
```

#### TD_3_c
```
make main_td3c
./main_td3c
```


### TD_4
```
cd TD_4
cmake .
```

#### TD4_a
```
make main_td4a
./main_td4a <nLoops> <nTasks> <schedPolicy>
```
The choices of parameter *schedPolicy* are: SCHED_RR, SCHED_FIFO and OTHER  

#### TD4_b
```
make main_td4b
./main_td4b <nLoops> <nTasks> <schedPolicy>
```
The choices of parameter *schedPolicy* are: SCHED_RR, SCHED_FIFO and OTHER  

#### TD4_c
```
make main_td4c
./main_td4c <nProd> <nCons> <nTokenPerTask>
```

#### TD4_d
```
make main_td4d
./main_td4d <nProd> <nCons> <nTokenPerTask>
```

### TD_5
```
cd TD_5
cmake .
make main_td5
./main_td5
```



## For environment without *cmake*

### TD_1
```
cd TD_1
sh compile_instruction.sh
```

#### TD_1_a
```
./main_td1a
```

#### TD_1_b
```
./main_td1b
```

#### TD_1_c
```
./main_td1c <nLoops>
```

#### TD_1_d
```
./main_td1d
```

#### TD_1_e
```
./main_td1e 
```


### TD_2
```
cd TD_2
sh compile_instruction.sh
```

#### TD_2_a
```
./main_td2a <nLoops> <nTasks>
```

#### TD_2_b
```
./main_td2b <nLoops> <nTasks> <schedPolicy>
```
The choices of parameter *schedPolicy* are: SCHED_RR, SCHED_FIFO and OTHER

#### TD_2_c
```
./main_td2c <nLoops> <nTasks> <schedPolicy> <protect>
```
The choices of parameter *schedPolicy* are: SCHED_RR, SCHED_FIFO and OTHER  
Parameter *protect* is not mandatory (1 is true, 0 is false)


### TD_3
```
cd TD_3
sh compile_instruction.sh
```

#### TD_3_a
```
./main_td3a
```

#### TD_3_b
```
./main_td3b
```

#### TD_3_c
```
./main_td3c
```


### TD_4
```
cmake .
```

#### TD4_a
```
./main_td4a <nLoops> <nTasks> <schedPolicy>
```
The choices of parameter *schedPolicy* are: SCHED_RR, SCHED_FIFO and OTHER  

#### TD4_b
```
./main_td4b <nLoops> <nTasks> <schedPolicy>
```
The choices of parameter *schedPolicy* are: SCHED_RR, SCHED_FIFO and OTHER  

#### TD4_c
```
./main_td4c <nProd> <nCons> <nTokenPerTask>
```

#### TD4_d
```
./main_td4d <nProd> <nCons> <nTokenPerTask>
```

### TD_5
```
cd TD_5
sh compile_instruction.sh
./main_td5
```

## Copy the executable program on the rpi2 target
```
scp program root@192.168.50.56:
```
