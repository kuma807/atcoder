import glob
import subprocess
import re
import os
import time

input_path = []
output_path = []
N = 1
for i in range(1, N + 1):
    input_path.append(f'testcase/input{i}.txt')
    output_path.append(f'testcase/output{i}.txt')
for i in range(len(input_path)):
    start = time.time()
    output = subprocess.check_output(f"cat {input_path[i]} | ./compile.sh", shell=True).decode('utf-8')
    print("time: ", time.time() - start)
    with open(output_path[i]) as f:
        ans = f.read()
        if ans != output:
            print(f"WA on testcase {input_path[i]} {output_path[i]}")
            print("ans")
            print(ans)
            print("output")
            print(output)
