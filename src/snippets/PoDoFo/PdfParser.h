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


virtual ~PdfParser() {}
virtual void ParseFile(const char* pszFileName, bool bLoadOnDemand) = 0;
virtual void ParseFile(const char* pszFileName, long lLen, bool bLoadOnDemand) = 0;
virtual void ParseFile(PoDoFo::PdfRefCountedInputDevice rDevice, bool bLoadOnDemand) = 0;
virtual bool QuickEncryptedCheck(const char* pszFilename) = 0;
virtual int GetNumberOfIncrementalUpdates() const = 0;
virtual PoDoFo::PdfVecObjects* GetObjects() const = 0;
virtual PoDoFo::EPdfVersion GetPdfVersion() const = 0;
virtual const char* GetPdfVersionString() const = 0;
virtual PoDoFo::PdfObject* GetTrailer() const = 0;
virtual bool GetLoadOnDemand() const = 0;
virtual bool IsLinearized() const = 0;
virtual size_t GetFileSize() const = 0;
virtual PoDoFo::PdfEncrypt* GetEncrypt() const = 0;
virtual PoDoFo::PdfEncrypt* TakeEncrypt() = 0;
virtual void SetPassword(const char* sPassword) = 0;
virtual bool IsStrictParsing() const = 0;
virtual void SetStrictParsing(bool bStrict) = 0;
virtual PoDoFo::pdf_long GetXRefOffset() = 0;
virtual bool HasXRefStream() = 0;
virtual bool GetIgnoreBrokenObjects() = 0;
virtual void SetIgnoreBrokenObjects(bool ignore_broken_objects) = 0;
virtual long GetMaxObjectCount() const = 0;
virtual void SetMaxObjectCount(long max_object_count) = 0;
