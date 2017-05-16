/***************************************************************************
 *   Copyright (C) 2006 by Dominik Seichter                                *
 *   domseichter@web.de                                                    *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Library General Public License as       *
 *   published by the Free Software Foundation; either version 2 of the    *
 *   License, or (at your option) any later version.                       *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this program; if not, write to the                 *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                         *
 *   In addition, as a special exception, the copyright holders give       *
 *   permission to link the code of portions of this program with the      *
 *   OpenSSL library under certain conditions as described in each         *
 *   individual source file, and distribute linked combinations            *
 *   including the two.                                                    *
 *   You must obey the GNU General Public License in all respects          *
 *   for all of the code used other than OpenSSL.  If you modify           *
 *   file(s) with this exception, you may extend this exception to your    *
 *   version of the file(s), but you are not obligated to do so.  If you   *
 *   do not wish to do so, delete this exception statement from your       *
 *   version.  If you delete this exception statement from all source      *
 *   files in the program, then also delete it here.                       *
 ***************************************************************************/

/*
 * WARNING: This file was automatically generated by Beautiful Capi!
 * Do not edit this file! Please edit the source API description.
 *
 * Beautiful Capi project:
 * https://github.com/PetrPPetrov/beautiful-capi
 *
 * PoDoFo API description project:
 * https://github.com/GkmSoft/podofo-capi
 */

enum EPdfKeyLength
{
    EPdfKeyLength_40 = 40,
    EPdfKeyLength_56 = 56,
    EPdfKeyLength_80 = 80,
    EPdfKeyLength_96 = 96,
    EPdfKeyLength_128 = 128,
    EPdfKeyLength256 = 256
};
enum EPdfPermissions
{
    ePdfPermissions_Print = 0x00000004,
    ePdfPermissions_Edit = 0x00000008,
    ePdfPermissions_Copy = 0x00000010,
    ePdfPermissions_EditNotes = 0x00000020,
    ePdfPermissions_FillAndSign = 0x00000100,
    ePdfPermissions_Accesible = 0x00000200,
    ePdfPermissions_DocAssembly = 0x00000400,
    ePdfPermissions_HighPrint = 0x00000800
};
enum EPdfEncryptAlgorithm
{
    ePdfEncryptAlgorithm_RC4V1 = 1,
    ePdfEncryptAlgorithm_RC4V2 = 2,
    ePdfEncryptAlgorithm_AESV2 = 4,
    ePdfEncryptAlgorithm_AESV3 = 8
};

virtual ~PdfEncryptImpl() {}
virtual bool IsEncryptionEnabled(PoDoFo::PdfEncryptImpl::EPdfEncryptAlgorithm eAlgorithm) = 0;
virtual void GenerateEncryptionKey(PoDoFo::PdfString documentID) = 0;
virtual void CreateEncryptionDictionary(PoDoFo::PdfDictionary rDictionary) const = 0;
virtual PoDoFo::PdfOutputStreamImpl* CreateEncryptionOutputStream(PoDoFo::PdfOutputStreamImpl* pOutputStream) = 0;
virtual PoDoFo::PdfInputStreamImpl* CreateEncryptionInputStream(PoDoFo::PdfInputStreamImpl* pInputStream) = 0;
virtual bool Authenticate(const char* password, PoDoFo::PdfString documentID) = 0;
virtual PoDoFo::PdfEncryptImpl::EPdfEncryptAlgorithm GetEncryptAlgorithm() const = 0;
virtual bool IsPrintAllowed() const = 0;
virtual bool IsEditAllowed() const = 0;
virtual bool IsCopyAllowed() const = 0;
virtual bool IsEditNotesAllowed() const = 0;
virtual bool IsFillAndSignAllowed() const = 0;
virtual bool IsAccessibilityAllowed() const = 0;
virtual bool IsDocAssemblyAllowed() const = 0;
virtual bool IsHighPrintAllowed() const = 0;
virtual const unsigned char* GetUValue() const = 0;
virtual const unsigned char* GetOValue() const = 0;
virtual const unsigned char* GetEncryptionKey() const = 0;
virtual PoDoFo::pdf_int32 GetPValue() const = 0;
virtual int GetRevision() const = 0;
virtual int GetKeyLength() const = 0;
virtual bool IsMetadataEncrypted() const = 0;
virtual void Encrypt(const unsigned char* inStr, PoDoFo::pdf_long inLen, unsigned char* outStr, PoDoFo::pdf_long outLen) const = 0;
virtual void Decrypt(const unsigned char* inStr, PoDoFo::pdf_long inLen, unsigned char* outStr, Bcapi::PdfLongImpl outLen) const = 0;
virtual PoDoFo::pdf_long CalculateStreamLength(PoDoFo::pdf_long length) const = 0;
virtual void SetCurrentReference(PoDoFo::PdfReference rRef) = 0;
virtual int GetEnabledEncryptionAlgorithms() const = 0;
virtual void SetEnabledEncryptionAlgorithms(int enabled_encryption_algorithms) = 0;
