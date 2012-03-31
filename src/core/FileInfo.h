#ifndef FileInfoH
#define FileInfoH

#include "stdafx.h"

struct TTranslation
{
    unsigned int Language, CharSet;
};

// Return pointer to file version info block
void * __fastcall CreateFileInfo(const std::wstring FileName);

// Free file version info block memory
void __fastcall FreeFileInfo(void *FileInfo);

// Return pointer to fixed file version info
VS_FIXEDFILEINFO __fastcall GetFixedFileInfo(void *FileInfo);

// Return number of available file version info translations
unsigned __fastcall GetTranslationCount(void *FileInfo);

// Return i-th translation in the file version info translation list
TTranslation __fastcall GetTranslation(void *FileInfo, unsigned i);

// Return the name of the specified language
std::wstring __fastcall GetLanguage(unsigned int Language);

// Return the value of the specified file version info string using the
// specified translation
std::wstring __fastcall GetFileInfoString(void *FileInfo,
                               TTranslation Translation, std::wstring StringName);

int __fastcall CalculateCompoundVersion(int MajorVer,
                             int MinorVer, int Release, int Build);

#endif // FileInfoH
