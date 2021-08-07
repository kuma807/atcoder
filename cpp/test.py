import glob
import subprocess
import re
import os
import time

input_path = glob.glob('testcase/input*.txt')
output_path = glob.glob('testcase/output*.txt')
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
