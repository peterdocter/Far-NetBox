#pragma once

#include <vector>

#include <Classes.hpp>
#include "HierarchicalStorage.h"
#include "PluginSettings.hpp"

//---------------------------------------------------------------------------
class TFar3Storage : public THierarchicalStorage
{
public:
  explicit TFar3Storage(const UnicodeString & AStorage,
    const GUID & guid, FARAPISETTINGSCONTROL SettingsControl);
  virtual ~TFar3Storage();

  bool Copy(TFar3Storage * Storage);

  virtual void CloseSubKey();
  virtual bool DeleteSubKey(const UnicodeString & SubKey);
  virtual bool DeleteValue(const UnicodeString & Name);
  virtual void GetSubKeyNames(TStrings * Strings);
  virtual bool ValueExists(const UnicodeString & Value);

  virtual size_t BinaryDataSize(const UnicodeString & Name);

  virtual bool ReadBool(const UnicodeString & Name, bool Default);
  virtual int ReadInteger(const UnicodeString & Name, int Default);
  virtual __int64 ReadInt64(const UnicodeString & Name, __int64 Default);
  virtual TDateTime ReadDateTime(const UnicodeString & Name, TDateTime Default);
  virtual double ReadFloat(const UnicodeString & Name, double Default);
  virtual UnicodeString ReadStringRaw(const UnicodeString & Name, const UnicodeString & Default);
  virtual size_t ReadBinaryData(const UnicodeString & Name, void * Buffer, size_t Size);

  virtual void WriteBool(const UnicodeString & Name, bool Value);
  virtual void WriteStringRaw(const UnicodeString & Name, const UnicodeString & Value);
  virtual void WriteInteger(const UnicodeString & Name, int Value);
  virtual void WriteInt64(const UnicodeString & Name, __int64 Value);
  virtual void WriteDateTime(const UnicodeString & Name, TDateTime Value);
  virtual void WriteFloat(const UnicodeString & Name, double Value);
  virtual void WriteBinaryData(const UnicodeString & Name, const void * Buffer, size_t Size);

  virtual void GetValueNames(TStrings * Strings);
  virtual void SetAccessMode(TStorageAccessMode value);
  virtual bool DoKeyExists(const UnicodeString & SubKey, bool ForceAnsi);
  virtual bool DoOpenSubKey(const UnicodeString & MungedSubKey, bool CanCreate);
  virtual UnicodeString GetSource();

private:
  UnicodeString GetFullCurrentSubKey() { return /* GetStorage() + */ GetCurrentSubKey(); }
  intptr_t OpenSubKeyInternal(intptr_t Root, const UnicodeString & SubKey, bool CanCreate);

private:
  intptr_t FRoot;
  PluginSettings FPluginSettings;
  std::vector<intptr_t> FSubKeyIds;

  void Init();
};
//---------------------------------------------------------------------------
