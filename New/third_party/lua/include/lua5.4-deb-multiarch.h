/*
** lua5.4-deb-multiarch.h
**
** Debian/Ubuntu ship a patched luaconf.h that includes this generated header
** to pick up the multiarch tuple (used to build LUA_CDIR2 / LUA_CPATH_DEFAULT).
** Upstream `make install` generates it; when the headers are vendored by hand
** it has to be provided explicitly. Without it `#include <lua.hpp>` fails with
** "lua5.4-deb-multiarch.h: No such file or directory".
*/

#ifndef LUA5_4_DEB_MULTIARCH_H
#define LUA5_4_DEB_MULTIARCH_H

#if defined(__x86_64__)
#define DEB_HOST_MULTIARCH "x86_64-linux-gnu"
#elif defined(__aarch64__)
#define DEB_HOST_MULTIARCH "aarch64-linux-gnu"
#elif defined(__i386__)
#define DEB_HOST_MULTIARCH "i386-linux-gnu"
#elif defined(__arm__)
#define DEB_HOST_MULTIARCH "arm-linux-gnueabihf"
#else
/* Fall back to the value the build toolchain reports. */
#define DEB_HOST_MULTIARCH "unknown-linux-gnu"
#endif

#endif /* LUA5_4_DEB_MULTIARCH_H */
