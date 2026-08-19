pkgname="scout"
pkgver="1.0.0"
pkgrel="1"
pkgdesc="A CTF analysis tool, written in C"
arch=("x86_64")
url="https://github.com/hyphen-hyphen-hyphen-hyphen/scout"
license=("GPLv3")
depends=("gcc" "cjson" "glibc" "coreutils")
sha256sums=("SKIP")
source=("scout-v${pkgver}.tar.gz::https://github.com/hyphen-hyphen-hyphen-hyphen/scout/archive/refs/tags/v1.0.0.tar.gz")
package() {
	cd "${srcdir}/scout-${pkgver}"
	gcc -g -Wall -Isrc -lcjson src/scout.c src/mathyy/mathyy.c src/entropy/entropy.c -o scout
	mkdir -p "${pkgdir}/usr/bin"
	install scout "${pkgdir}/usr/bin/scout" -m 755
}
