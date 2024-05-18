import sys
import subprocess
import os
import time

from typing import List

import random
import string

def generate_random_word(length):
    return ''.join(random.choices(string.ascii_lowercase, k=length))

def generate_random_line(word_count):
    return ' '.join(generate_random_word(random.randint(1, 10)) for _ in range(word_count))

# 生成随机行数，每行包含随机数量的token
def generate_Inputs(max_lines=100, max_words_per_line=100)->List[str]:
    line_count = random.randint(1, max_lines)
    lines = []
    for _ in range(line_count):
        word_count = random.randint(1, max_words_per_line)
        lines.append(generate_random_line(word_count))
    return lines

def tryCreateDir(inputs: List[str],model=1)->str:
    directory = time.strftime("%Y-%m-%d-%H-%M-%S-model") + str(model)
    file_in = "puts.in"
    file_out = "puts.out"
    T = 20
    while os.path.exists(directory) and T > 0:
        directory = time.strftime("%Y-%m-%d-%H-%M-%S-model") + str(model)
        T -= 1
    if os.path.exists(directory):
        return None
    os.makedirs(directory)
    print(f"目录 '{directory}' 已创建")

    # create puts.in
    in_path = os.path.join(directory, file_in)
    with open(in_path, 'w') as f:
        f.write("\n".join(inputs))

    # create puts.out
    out_path = os.path.join(directory, file_out)
    with open(out_path, 'w') as f: pass
    
    return directory

# return dir r_path
def generateDirAndInputs(model)->str:
    inputs = generate_Inputs()
    dir = tryCreateDir(inputs,model)    
    return dir

def test(model_id):
    dir_r_path = generateDirAndInputs(model_id)
    if dir_r_path is None:
        print("fail to create file")
        return
    command = f"../model{model_id}/build/main"
    input_file = f"{dir_r_path}/puts.in"
    output_file = f"{dir_r_path}/puts.out"
    # 打开输入和输出文件
    with open(input_file, 'r') as infile, open(output_file, 'w') as outfile:
        subprocess.run(command, stdin=infile, stdout=outfile)



if __name__ == "__main__":
    argv = sys.argv
    model = "1"
    try:
        model = int(argv[1 + argv.index("-m")])
        if model not in {1,2}:
            model = 1
    except:
        pass
    test(model)