# For release builds, use "debug=1" in command line. For instance,
# to build DLLs in release mode: nmake dlls debug=1

CC=cl
LINK=link
RC=rc

INCPNGDIB=soft\pngdib
LPPNGDIB=soft\pngdib 
LPLIBPNG=soft\libpng-1.2.8-lib\lib
LPZLIB=soft\zlib123-dll\lib
LIBPNGDLL=soft\libpng-1.2.8-bin\libpng13.dll 
ZLIBDLL=soft\zlib123-dll\zlib1.dll
D3DX9=d3dx9.lib

!if "$(debug)"=="1"
EXTRA_CFLAGS=/DDEBUG
!else
EXTRA_CFLAGS=/DMYDLL_RELEASE_BUILD
!endif

# 4731: warning about ebp modification
CFLAGS=/nologo /Od /EHsc /wd4731 $(EXTRA_CFLAGS) /DDEFAULT_CODE_SHIFT=6
LFLAGS=/NOLOGO
LIBS=user32.lib gdi32.lib advapi32.lib comctl32.lib shell32.lib shlwapi.lib
LIBSDLL=pngdib.obj libpng.a zdll.lib $(LIBS)


all: dlls apps
	if exist output (rd /S /Q output)
	mkdir output
	copy *.dll output
#	copy $(LIBPNGDLL) output
	copy $(ZLIBDLL) output
	copy manager.exe output
	copy config.exe output
#	copy krun.exe output
	copy lang_*.txt output
	
all_dlls: dlls
	if exist output (rd /S /Q output)
	mkdir output
	copy *.dll output
#	copy $(LIBPNGDLL) output
	copy $(ZLIBDLL) output
	copy lang_*.txt output
	
all_apps: apps
	if exist output (rd /S /Q output)
	mkdir output
	copy manager.exe output
	copy config.exe output
	copy lang_*.txt output

pngdib:
	(cd soft\pngdib && nmake EXTRA_CFLAGS=$(EXTRA_CFLAGS))

#dlls: kload.dll kserv.dll lodmixer.dll kset.dll afsio.dll afs2fs.dll sched.dll fserv.dll rwdata.dll camera.dll time.dll speeder.dll stadium.dll bootserv.dll bserv.dll leagues.dll
#apps: manager.exe config.exe zlibtool.exe
#dlls: kload.dll kserv.dll afsio.dll afs2fs.dll speeder.dll sides.dll lodmixer.dll fserv.dll
#apps: manager.exe zlibtool.exe config.exe krun.exe
#dlls: kload.dll afsio.dll afs2fs.dll speeder.dll lodmixer.dll sides.dll kserv.dll fserv.dll
dlls: kload.dll afsio.dll afs2fs.dll speeder.dll lodmixer.dll
apps: manager.exe config.exe

imageutil.obj: imageutil.cpp imageutil.h
detect.obj: detect.cpp detect.h
lang.obj: lang.cpp lang.h
configs.obj: configs.cpp configs.h configs.hpp utf8.h
hooklib.obj: hooklib.cpp hooklib.h
log.obj: log.cpp log.h
crc32.obj: crc32.cpp crc32.h
hook.obj: hook.cpp hook.h hook_addr.h
apihijack.obj: apihijack.cpp apihijack.h
kload.lib: kload.obj hook.obj
kload.obj: kload.h kload_addr.h kload.cpp
regtools.obj: regtools.cpp regtools.h

krun.exe: krun.obj imageutil.obj regtools.obj configs.obj krun.res
	$(LINK) $(LFLAGS) /out:krun.exe krun.obj imageutil.obj regtools.obj configs.obj krun.res $(LIBS)
krun.res: 
	$(RC) -r -fo krun.res krun.rc

afs2fs.lib: afs2fs.obj names.obj configs.obj
afs2fs.dll: afs2fs.lib afsio.lib afs2fs.res kload.lib
	$(LINK) $(LFLAGS) /out:afs2fs.dll /DLL afs2fs.obj names.obj configs.obj afs2fs.res $(LIBS) kload.lib afsio.lib
afs2fs.obj: afs2fs.cpp afs2fs.h afs2fs_addr.h afs2fs.rc
names.obj: names.cpp names.h

afsio.lib: afsio.obj configs.obj apihijack.obj
afsio.dll: afsio.lib afsio.res kload.lib
	$(LINK) $(LFLAGS) /out:afsio.dll /DLL afsio.obj configs.obj afsio.res $(LIBS) kload.lib apihijack.obj
afsio.obj: afsio.cpp afsio.h afsio_addr.h afsio.rc

speeder.lib: speeder.obj configs.obj
speeder.dll: speeder.lib speeder.res
	$(LINK) $(LFLAGS) /out:speeder.dll /DLL speeder.obj configs.obj speeder.res $(LIBS) kload.lib
speeder.obj: speeder.cpp speeder.h speeder_addr.h speeder.rc

sides.lib: sides.obj configs.obj
sides.dll: sides.lib sides.res
	$(LINK) $(LFLAGS) /out:sides.dll /DLL sides.obj configs.obj sides.res $(LIBS) kload.lib
sides.obj: sides.cpp sides.h sides_addr.h sides.rc

lodmixer.lib: lodmixer.obj configs.obj
lodmixer.dll: lodmixer.lib lodmixer.res
	$(LINK) $(LFLAGS) /out:lodmixer.dll /DLL lodmixer.obj configs.obj lodmixer.res $(LIBS) kload.lib
lodmixer.obj: lodmixer.cpp lodmixer.h lodmixer_addr.h lodmixer.rc

lodcfg.obj: lodcfg.cpp lodcfg.h lodcfgui.h lodmixer.h
lodcfgui.obj: lodcfgui.cpp lodcfgui.h
config.exe: lodcfg.obj detect.obj lodcfgui.obj configs.obj config.res
	$(LINK) $(LFLAGS) /out:config.exe lodcfg.obj detect.obj lodcfgui.obj configs.obj config.res $(LIBS)
config.res: 
	$(RC) -r -fo config.res config.rc

kload.lib: hook.obj kload.obj detect.obj imageutil.obj lang.obj log.obj configs.obj hooklib.obj hook.obj crc32.obj
kload.dll: kload.lib kload.res
	$(LINK) $(LFLAGS) /out:kload.dll /DLL kload.obj detect.obj imageutil.obj lang.obj log.obj configs.obj hooklib.obj hook.obj crc32.obj kload.res $(LIBS) winmm.lib
kload.obj: kload.cpp kload.h

kload.res: 
	$(RC) -r -fo kload.res kload.rc

fserv.lib: fserv.obj configs.obj afsio.lib
fserv.dll: fserv.lib fserv.res
	$(LINK) $(LFLAGS) /out:fserv.dll /DLL fserv.obj configs.obj fserv.res $(LIBS) kload.lib afsio.lib
fserv.obj: fserv.cpp fserv.h fserv_addr.h fserv.rc replay.h player.h bal.h
fserv.res: 
	$(RC) -r -fo fserv.res fserv.rc
	
kserv.lib: kserv.obj gdb.obj configs.obj crc32.obj afsio.dll kload.dll pngdib
kserv.dll: kserv.lib kserv.res
	$(LINK) $(LFLAGS) /out:kserv.dll /LIBPATH:$(LPPNGDIB) /LIBPATH:$(LPLIBPNG) /LIBPATH:$(LPZLIB) /DLL kserv.obj gdb.obj configs.obj crc32.obj kserv.res $(LIBS) $(D3DX9) kload.lib afsio.lib $(LIBSDLL)
kserv.obj: kserv.cpp kserv.h kserv_addr.h kserv.rc dllinit.h afsio.h teaminfo.h
gdb.obj: gdb.cpp gdb.h configs.hpp

tab1.exe: tab1.obj
	$(LINK) $(LFLAGS) /out:tab1.exe tab1.obj $(LIBS)

setupgui.obj: setupgui.cpp setupgui.h
manager.obj: manager.cpp manager.h setupgui.h
manager.exe: manager.obj detect.obj setupgui.obj imageutil.obj lang.obj configs.obj manager.res
	$(LINK) $(LFLAGS) /out:manager.exe manager.obj detect.obj setupgui.obj imageutil.obj lang.obj configs.obj manager.res $(LIBS) shell32.lib
manager.res: 
	$(RC) -r -fo manager.res manager.rc
	
zlibtool.obj: zlibtool.cpp
zlibtool.exe: zlibtool.obj 
	$(LINK) $(LFLAGS) /out:zlibtool.exe zlibtool.obj /LIBPATH:$(LPZLIB) $(LIBS) zdll.lib

afsexport.obj: afsexport.cpp afsreader.h
afsexport.exe: afsexport.obj afsreader.obj 
	$(LINK) $(LFLAGS) /out:afsexport.exe afsexport.obj afsreader.obj $(LIBS)

notebook.obj: notebook.cpp notebook.h
notebook.exe: notebook.obj 
	$(LINK) $(LFLAGS) /out:notebook.exe notebook.obj $(LIBS)

.cpp.obj:
	$(CC) $(CFLAGS) -c $(INC) /I $(INCPNGDIB) $<

clean:
	del /Q /F *.exp *.lib *.obj *.res *.dll *.exe
	if exist soft\pngdib (cd soft\pngdib && $(MAKE) clean)
	if exist output (rd /S /Q output)

clean-all:
	del /Q /F *.exp *.lib *.obj *.res *.dll *.exe *.log *~ *.orig
	if exist soft\pngdib (cd soft\pngdib && $(MAKE) clean-all)
	if exist output (rd /S /Q output)
	
