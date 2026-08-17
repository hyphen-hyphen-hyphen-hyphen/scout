orig=$(pwd)
dir=$(mktmp -d)
cd "${dir}"
git clone https://github.com/hyphen-hyphen-hyphen-hyphen/scout.git
cd scout
make
sudo make install
cd "${orig}"
rm "${dir}"
