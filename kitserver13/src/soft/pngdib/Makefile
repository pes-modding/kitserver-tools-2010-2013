INC=$(INC) /I "..\libpng-1.2.8-lib\include"

CFLAGS=/nologo /EHsc $(EXTRA_CFLAGS)
LFLAGS=/NOLOGO
ZLIBINC=/I "..\zlib123-dll\include"

all: pngdib.obj

pngdib.obj: pngdib.c pngdib.h

.c.obj:
	$(CC) $(CFLAGS) -c $(INC) $(ZLIBINC) $<

clean:
	del /Q /F *.exp *.lib *.obj *.res

clean-all:
	del /Q /F *.exp *.lib *.obj *.res *.log *~
