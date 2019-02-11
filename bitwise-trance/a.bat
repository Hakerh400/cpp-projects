@echo off
cls

echo.>1.obj
del *.obj
echo.>1.exe
del *.exe

if not "%initialized%" == "1" (
  call "D:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvars64.bat"
  set initialized=1
)

call cl /nologo /EHsc /Fe"main.exe" *.cc