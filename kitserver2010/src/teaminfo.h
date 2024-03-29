// teaminfo.h

#ifndef _TEAMINFO_H_
#define _TEAMINFO_H_

#pragma pack(4)

typedef WORD KCOLOR;

typedef struct _KIT_INFO {
    WORD unknown1[3];
    KCOLOR mainColor;
    KCOLOR editShirtColors[4];
    KCOLOR shortsFirstColor;
    KCOLOR editKitColors[9];
    BYTE unknown2[0x10];
    BYTE collar;
    BYTE editKitStyles[9];
    BYTE nameStyle;
    BYTE nameShow;
    BYTE unknown3;
    BYTE nameShape;
    BYTE unknown4;
    BYTE frontNumberShow;
    BYTE shortsNumberPosition;
    BYTE unknown5;
    BYTE sleevePatch;
    BYTE sleevePatchPosLong;
    BYTE sleevePatchPosShort;
    BYTE numberY;
    BYTE numberSize;
    BYTE frontNumberY;
    BYTE frontNumberX;
    BYTE frontNumberSize;
    BYTE shortsNumberY;
    BYTE shortsNumberX;
    BYTE shortsNumberSize;
    BYTE nameY;
    BYTE nameSize;
    BYTE flagPosition;
    BYTE unknown7[4];
    WORD unknown8;
    WORD model;
    WORD slot;
    BYTE techfit;
    BYTE unknown10;
} KIT_INFO; // size = 0x60

typedef struct _TEAM_KIT_INFO
{
    DWORD id;
    KIT_INFO ga;
    KIT_INFO pa;
    KIT_INFO gb;
    KIT_INFO pb;
} TEAM_KIT_INFO; // size = 0x60*4+4

typedef struct _TEAM_MATCH_DATA_INFO
{
    WORD teamIdSpecial;
    WORD teamId;
    //BYTE unknown2[0x2d30];
    //BYTE kitSelection;
    //BYTE unknown3[11];
    //TEAM_KIT_INFO tki;
} TEAM_MATCH_DATA_INFO;

typedef struct _NEXT_MATCH_DATA_INFO
{
    TEAM_MATCH_DATA_INFO* home;
    TEAM_MATCH_DATA_INFO* away;
} NEXT_MATCH_DATA_INFO;

#endif
