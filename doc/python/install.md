# Install Python 3.6

Refer to <http://docs.anaconda.com/anaconda/user-guide/faq/#how-do-i-get-the-latest-anaconda-with-python-3-5>.

Downalod `Anaconda3-5.2.0-MacOSX-x86_64.sh` from <https://repo.anaconda.com/archive/Anaconda3-5.2.0-MacOSX-x86_64.sh>
and install it to `$HOME/software/anaconda3-5-2-0`.

Set
```sh
export PATH=$HOME/software/anaconda3-5-2-0/bin:${PATH}
```
manually so that we can use the system python by default.

# Create a Virtual Environment

Refer to <https://conda.io/docs/user-guide/tasks/manage-environments.html> for details.

Environments are saved in `$HOME/software/anaconda3-5-2-0/envs`, which is empty
when anaconda is installed.

A quick guide is as follows.

```
# create an environemnt named hello_bazel
conda create -n hello_bazel python=3.6

# after the above command, a folder named hello_bazel
# is created in $HOME/software/anaconda3-5-2-0/envs

# to view a list of environments
conda env list

# to activate an environment
source activate hello_bazel

# to deactivate the current environment
source deactivate

# to delete an environment
conda env remove --name hello_bazel

# install pip (you have to deactivate the corresponding environment first)
conda install -n hello_bazel pip
source activate hello_bazel
```

# Work with YouCompleteMe

Use `/usr/bin/python install.py` instead of `./install.py`
to compile YouCompleteMe.

