
mkdir $HOME/software
cd $HOME/software

wget https://releases.linaro.org/components/toolchain/binaries/7.3-2018.05/aarch64-linux-gnu/gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu.tar.xz
tar xf gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu.tar.xz
mv gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu linaro
sudo cp linaro/aarch64-linux-gnu/libc/lib/ld-linux-aarch64.so.1 /lib/

# install qemu from source
sudo apt-get install -y libglib2.0-dev libfdt-dev libpixman-1-dev zlib1g-dev
git clone --depth 1 git://git.qemu-project.org/qemu.git
cd qemu
./configure --prefix=$HOME/software/qemu --target-list=aarch64-linux-user
make -s -j4 > /dev/null
make install > /dev/null

qemu-aarch64 --version
