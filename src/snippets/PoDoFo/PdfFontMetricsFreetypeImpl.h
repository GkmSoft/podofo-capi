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


virtual ~PdfFontMetricsFreetypeImpl() {}
virtual PoDoFo::PdfFontMetricsFreetypeImpl* CreateForSubsetting(FT_Library* pLibrary, const char* pszFilename, bool pIsSymbol, const char* pszSubsetPrefix) = 0;
virtual void GetWidthArray(PoDoFo::PdfVariant var, unsigned nFirst, unsigned nLast, PoDoFo::PdfEncodingImpl* pEncoding) const = 0;
virtual double GetGlyphWidth(int nGlyphId) const = 0;
virtual double GetGlyphWidth(const char* pszGlyphname) const = 0;
virtual void GetBoundingBox(PoDoFo::PdfArray array) const = 0;
virtual double CharWidth(unsigned char c) const = 0;
virtual double UnicodeCharWidth(unsigned char c) const = 0;
virtual double GetLineSpacing() const = 0;
virtual double GetUnderlineThickness() const = 0;
virtual double GetUnderlinePosition() const = 0;
virtual double GetStrikeOutPosition() const = 0;
virtual double GetStrikeoutThickness() const = 0;
virtual const char* GetFontname() const = 0;
virtual unsigned GetWeight() const = 0;
virtual double GetAscent() const = 0;
virtual double GetPdfAscent() const = 0;
virtual double GetDescent() const = 0;
virtual double GetPdfDescent() const = 0;
virtual int GetItalicAngle() const = 0;
virtual long GetGlyphId(long lUnicode) const = 0;
virtual bool IsSymbol() const = 0;
virtual const char* GetFontData() const = 0;
virtual PoDoFo::pdf_long GetFontDataLen() const = 0;
virtual bool IsBold() const = 0;
virtual bool IsItalic() const = 0;
virtual FT_Face GetFace() = 0;
