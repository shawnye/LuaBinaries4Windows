# LuaBinaries4Windows
lua(5.2&amp;5.3) binaries for windows, lua 5.3 is preferred

Built with Microsoft Visual C++ 2010 Express


***Thanks*** for all the following projects contributors.

Lua
- [Lua](http://www.lua.org)
x [srlua](http://webserver2.tecgraf.puc-rio.br/~lhf/ftp/lua/#srlua)

WebServer
x [civetweb](https://github.com/bel2125/civetweb), lightweight http server with Lua&sqlite3 support inside, no more than 1MB.

GUI
x [iup](http://webserver2.tecgraf.puc-rio.br/iup/) with matrix(depend [cd](http://sourceforge.net/projects/canvasdraw))

database
- [lsqlite3](http://lua.sqlite.org/index.cgi/index) ,exclueded extension-functions.c
- [odbc](https://github.com/moteus/lua-odbc) ,if use CNN_DSN for win64, go to `C:\Windows\SysWOW64\odbcad32.exe` and add 

threading 
- [lanes](https://github.com/LuaLanes/lanes)
x [llthreads2](https://github.com/moteus/lua-llthreads2)

network 
x [luasocket](http://files.luaforge.net/releases/luasocket/luasocket) (removed to network version), depends on msvcr100.dll

xml 
- [lxp](http://www.keplerproject.org/luaexpat/) ,depends on [expat](http://www.libexpat.org/)

os
- [lfs](http://keplerproject.github.io/luafilesystem/)
x [winreg](https://github.com/moteus/lua-winreg)
x [date](https://github.com/Tieske/date) [DOC](http://tieske.github.io/date/)
- [utf8](http://github.com/starwing/luautf8) ,just for Lua before 5.3
- [luaiconv](https://github.com/ittner/lua-iconv/), depends on [libiconv](http://www.gnu.org/software/libiconv/) 
- [ansicode] modified version based on (http://hi.baidu.com/nivrrex/item/24079590518cda1f924f41a0)
  
zip 
- [ziparchive](https://github.com/jjensen/lua-ziparchive), depends on [zlib1](http://www.gzip.org/zlib/)
  used for xlsx parser

spreadsheet
x [csv](http://lua-users.org/lists/lua-l/2009-08/msg00012.html)  --removed, too much problems
- [xls](https://github.com/jjensen/lua-xls)
- [xlsx](https://github.com/jjensen/lua-xlsx) ,depends on [ziparchive](https://github.com/jjensen/lua-ziparchive)

others
x [markdown](http://www.frykholm.se)
x [CodeGen](http://fperrad.github.io/lua-CodeGen/index.html) ,conditionally depends on [lpeg](http://www.inf.puc-rio.br/~roberto/lpeg/lpeg.html)
- [lpeg](http://www.inf.puc-rio.br/~roberto/lpeg/lpeg.html)
x [microscope](http://siffiejoe.github.io/lua-microscope/)  just for visualize (not included)
- [winapi] (https://github.com/stevedonovan/winapi)