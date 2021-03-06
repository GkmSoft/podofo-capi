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


virtual ~PdfObjectRawPtr() {}
virtual PoDoFo::PdfObjectRawPtr* GetIndirectKey(PoDoFo::PdfName key) const = 0;
virtual PoDoFo::PdfObjectRawPtr* MustGetIndirectKey(PoDoFo::PdfName key) const = 0;
virtual void WriteObject(PoDoFo::PdfOutputDevice* pDevice, PoDoFo::EPdfWriteMode eWriteMode, PoDoFo::PdfEncrypt* pEncrypt, PoDoFo::PdfName keyStop) const = 0;
virtual PoDoFo::pdf_long GetObjectLength(PoDoFo::EPdfWriteMode eWriteMode) = 0;
virtual PoDoFo::PdfReference Reference() const = 0;
virtual PoDoFo::PdfStream* GetStream() = 0;
virtual bool HasStream() const = 0;
virtual void FlateCompressStream() = 0;
virtual PoDoFo::pdf_long GetByteOffset(const char* pszKey, PoDoFo::EPdfWriteMode eWriteMode) = 0;
virtual void DelayedStreamLoad() const = 0;
virtual PoDoFo::PdfVecObjects* GetOwner() const = 0;
virtual void SetOwner(PoDoFo::PdfVecObjects* owner) = 0;
