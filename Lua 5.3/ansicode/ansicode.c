/**
感谢 nivrrex's space
http://hi.baidu.com/nivrrex/item/24079590518cda1f924f41a0

build with VS2010:
cl.exe  /nologo /W1  /Ox /MD /D_WIN32 /DLUA_VERSION_NUM=502 /DLUA_COMPAT_ALL /DLUA_BUILD_AS_DLL /LD /DLUA_LIB  /c ansicode.c
link.exe /nologo  /NODEFAULTLIB:LIBCMT.LIB /DLL /out:ansicode.dll  lua52.lib  ansicode.obj

windows only
for linux-er , use iconv ,which is heavy for me!
*/
#include"lua.h"
#include "lualib.h"
#include "lauxlib.h"
#include <windows.h>

#define BUFF_SIZE 1024
#define CHAR_SCALE (sizeof(wchar_t)/sizeof(char))

#if LUA_VERSION_NUM > 501
//
// Lua 5.2
//
#define LUA_GLOBALSINDEX    LUA_RIDX_GLOBALS

#define luaL_reg           luaL_Reg
#define lua_open            luaL_newstate
#define luaL_putchar(B,c)   luaL_addchar(B,c)

#endif

wchar_t * AToU (const char * str)
{
  int textlen;
  wchar_t * result;

  textlen=MultiByteToWideChar (CP_ACP,0,str,-1,NULL,0);
  result= (wchar_t*) malloc ((textlen+1) *sizeof (wchar_t));
  memset (result,0, (textlen+1) *sizeof (wchar_t));
  MultiByteToWideChar (CP_ACP,0,str,-1, (LPWSTR) result,textlen);
  return result;
}

char * UToA (const wchar_t * str)
{
  char * result;
  int textlen;

// wide char to multi char
  textlen=WideCharToMultiByte (CP_ACP,0,str,-1,NULL,0,NULL,NULL);
  result= (char*) malloc ((textlen+1) *sizeof (char));
  memset (result,0,sizeof (char) * (textlen+1));
  WideCharToMultiByte (CP_ACP,0,str,-1,result,textlen,NULL,NULL);
  return result;
}

wchar_t * U8ToU (const char * str)
{
  int textlen;
  wchar_t * result;

  textlen=MultiByteToWideChar (CP_UTF8,0,str,-1,NULL,0);
  result= (wchar_t*) malloc ((textlen+1) *sizeof (wchar_t));
  memset (result,0, (textlen+1) *sizeof (wchar_t));
  MultiByteToWideChar (CP_UTF8,0,str,-1, (LPWSTR) result,textlen);
  return result;
}

char * UToU8 (const wchar_t * str)
{
  char * result;
  int textlen;

  // wide char to multi char
  textlen=WideCharToMultiByte (CP_UTF8,0,str,-1,NULL,0,NULL,NULL);
  result= (char*) malloc ((textlen+1) *sizeof (char));
  memset (result,0,sizeof (char) * (textlen+1));
  WideCharToMultiByte (CP_UTF8,0,str,-1,result,textlen,NULL,NULL);
  return result;
}

static int Unicode_a2u (lua_State * L)
{
  const char * str;
  wchar_t * result;

  /*传递第一个参数 */
  str=lua_tostring (L,-1);
  /*开始转换 */
  result=AToU (str);
  /*返回值， */
  lua_pushlstring (L, (char*) result,wcslen (result) *CHAR_SCALE);
  free(result);
  return 1;
}

static int Unicode_u2a (lua_State * L)
{
  const wchar_t * str;
  char * result;

  /*传递第一个参数 */
  str= (wchar_t*) lua_tostring (L,-1);
  /*开始转换 */
  result=UToA (str);
  /*返回值， */
  lua_pushstring (L,result);
  free(result);
  return 1;
}

static int Unicode_u2u8 (lua_State * L)
{
  const wchar_t * str;
  char * result;

  /*传递第一个参数 */
  str= (wchar_t*) lua_tostring (L,-1);
  /*开始转换 */
  result=UToU8 (str);
  /*返回值， */
  lua_pushstring (L,result);
  free(result);
  return 1;
}

static int Unicode_u82u (lua_State * L)
{
  const char * str;
  wchar_t * result;

  /*传递第一个参数 */
  str=lua_tostring (L,-1);
  /*开始转换 */
  result=U8ToU (str);
  /*返回值， */
  lua_pushlstring (L, (char*) result,wcslen (result) *CHAR_SCALE);
  free(result);
  return 1;
}

static int Unicode_a2u8 (lua_State * L)
{
  const char * str;
  wchar_t * temp;
  char * result;

  /*传递第一个参数 */
  str=lua_tostring (L,-1);
  /*开始转换 */
  temp=AToU (str);
  result=UToU8 (temp);
  /*返回值， */
  lua_pushstring (L,result);
  free(result);
  return 1;
}

static int Unicode_u82a (lua_State * L)
{
  const char * str;
  wchar_t * temp;
  char * result;

  /*传递第一个参数 */
  str=lua_tostring (L,-1);
  /*开始转换 */
  temp=U8ToU (str);
  result=UToA (temp);
  /*返回值， */
  lua_pushstring (L,result);
  free(result);
  return 1;
}



static const luaL_Reg UnicodeFunctions[]=
{
  {"a2u",Unicode_a2u},
  {"u2a",Unicode_u2a},
  {"u2u8",Unicode_u2u8},
  {"u82u",Unicode_u82u},
  {"a2u8",Unicode_a2u8},
  {"u82a",Unicode_u82a},

  {NULL,NULL}
};

LUALIB_API int luaopen_ansicode(lua_State *L)
{
#if LUA_VERSION_NUM >= 502
  luaL_newlib(L, UnicodeFunctions);
#else
  luaL_openlib(L,"ansicode",UnicodeFunctions,0);
#endif
  return 1;
}
