orig=$(pwd)
dir=$(mktemp -d)
cd "${dir}"
git clone https://github.com/hyphen-hyphen-hyphen-hyphen/scout.git
cd scout
make
sudo make install
cd "${orig}"
rm -rf "${dir}"
