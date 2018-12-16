#!/usr/bin/env python
# ==============================================================================
#  Copyright (c) 2018 Fangjun Kuang
#  Email: fangjun.kuang at gmail.com
#
#  Licensed under the MIT License.
#  Please refer to <root-path>/LICENSE for details.
# ==============================================================================

import subprocess
import os.path

# only check dict keys
Status = {
  'A': 'Added',
  'M': 'Modified',
  'R': 'Renamed',
}

Extensions = [
 '.h',
 '.hpp',
 '.c',
 '.cc',
 '.cpp',
]

# return a list of added or modified files
def git_status_porcelain():
    process = subprocess.Popen(["git", "status", "--porcelain"], stdout=subprocess.PIPE)
    output, err = process.communicate()
    exit_code = process.wait()

    assert err == None
    assert exit_code == 0

    output = output.split('\n')

    res = []
    for f in output:
        status = f.split()
        if len(status) < 2: continue
        code = status[0]
        for s in Status:
            if s in code:
                if 'R' in code:
                    res.append(status[3])   # R foo.cc -> bar.cc
                else:
                    res.append(status[1])
                break
    return res

def filter_extensions(files):
    res = [f for f in files for ext in Extensions if f.endswith(ext)]
    return res


def get_git_root():
    process = subprocess.Popen(["git", "rev-parse", "--show-toplevel"], stdout=subprocess.PIPE)
    output, err = process.communicate()
    exit_code = process.wait()

    assert err == None
    assert exit_code == 0

    # remove the trailing \n
    return output[:-1]

def to_abs_files(dir, files):
    res = [os.path.join(dir, f) for f in files]
    return res

def check_style(files, cpplint):
    for f in files:
        process = subprocess.Popen(['python', cpplint, f], stdout=subprocess.PIPE)
        output, err = process.communicate()
        exit_code = process.wait()

if __name__ == "__main__":
    root_path = get_git_root()
    files = git_status_porcelain()
    files = filter_extensions(files)
    abs_files = to_abs_files(root_path, files)
    cpplint = os.path.join(root_path, 'scripts/cpplint.py')
    check_style(abs_files, cpplint)

