#!/usr/bin/python3
import os
import time

params = [
    [1000],
]

solutions = [
    "sol"
]

ok_solution = "brut"

os.system("g++ -D LOCAL -std=c++20 -O2 gen.cpp -o gen")
os.system(f"g++ -D LOCAL -std=c++20 -O2 {ok_solution}.cpp -o {ok_solution}")
for solution in solutions:
    os.system(f"g++ -D LOCAL -std=c++20 -O2 {solution}.cpp -o {solution}")

def check_solution(name):
    print(f"RULEZ {name}")
    os.system(f"time ./{name} < tests/{curr_tag}.in > test.out")

    check = os.system(f"diff -qBbEa test.out tests/{curr_tag}.out > /dev/null")
    if(check != 0):
        print(f"{name} WRONG!")
        return 1
    else: 
        print(f"{name} PASSED!")
        return 0

i = 0
tag = "test"
delta = 0
while i < len(params):
    curr_tag = tag
    os.system(f"./gen {' '.join([str(x) for x in params[i]])} > tests/{curr_tag}.in")
    os.system(f"time ./{ok_solution} < tests/{curr_tag}.in > tests/{curr_tag}.out")

    print(f"TEST: {curr_tag}")

    add = 1
    for solution in solutions:
        add = add and check_solution(solution)
    
    print()
    i += add
    #break

    