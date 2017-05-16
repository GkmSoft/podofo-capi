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

#include "boost/shared_ptr.hpp"
#include "boost/make_shared.hpp"

#include "PoDoFo/base/PdfDefines.h"
#include "PoDoFo/base/Pdf3rdPtyForwardDecl.h"
#include "PoDoFo/base/PdfArray.h"
#include "PoDoFo/base/PdfCanvas.h"
#include "PoDoFo/base/PdfColor.h"
#include "PoDoFo/base/PdfContentsTokenizer.h"
#include "PoDoFo/base/PdfData.h"
#include "PoDoFo/base/PdfDataType.h"
#include "PoDoFo/base/PdfDate.h"
#include "PoDoFo/base/PdfDictionary.h"
#include "PoDoFo/base/PdfEncodingFactory.h"
#include "PoDoFo/base/PdfEncoding.h"
#include "PoDoFo/base/PdfEncrypt.h"
#include "PoDoFo/base/PdfError.h"
#include "PoDoFo/base/PdfExtension.h"
#include "PoDoFo/base/PdfFileStream.h"
#include "PoDoFo/base/PdfFilter.h"
#include "PoDoFo/base/PdfImmediateWriter.h"
#include "PoDoFo/base/PdfInputDevice.h"
#include "PoDoFo/base/PdfInputStream.h"
#include "PoDoFo/base/PdfLocale.h"
#include "PoDoFo/base/PdfMemoryManagement.h"
#include "PoDoFo/base/PdfMemStream.h"
#include "PoDoFo/base/PdfName.h"
#include "PoDoFo/base/PdfObject.h"
#include "PoDoFo/base/PdfObjectStreamParserObject.h"
#include "PoDoFo/base/PdfOutputDevice.h"
#include "PoDoFo/base/PdfOutputStream.h"
#include "PoDoFo/base/PdfParser.h"
#include "PoDoFo/base/PdfParserObject.h"
#include "PoDoFo/base/PdfRect.h"
#include "PoDoFo/base/PdfRefCountedBuffer.h"
#include "PoDoFo/base/PdfRefCountedInputDevice.h"
#include "PoDoFo/base/PdfReference.h"
#include "PoDoFo/base/PdfStream.h"
#include "PoDoFo/base/PdfString.h"
#include "PoDoFo/base/PdfTokenizer.h"
#include "PoDoFo/base/PdfVariant.h"
#include "PoDoFo/base/PdfVecObjects.h"
#include "PoDoFo/base/PdfWriter.h"
#include "PoDoFo/base/PdfXRef.h"
#include "PoDoFo/base/PdfXRefStream.h"
#include "PoDoFo/base/PdfXRefStreamParserObject.h"

#include "PoDoFo/doc/PdfAcroForm.h"
#include "PoDoFo/doc/PdfAction.h"
#include "PoDoFo/doc/PdfAnnotation.h"
#include "PoDoFo/doc/PdfCMapEncoding.h"
#include "PoDoFo/doc/PdfContents.h"
#include "PoDoFo/doc/PdfDestination.h"
#include "PoDoFo/doc/PdfDifferenceEncoding.h"
#include "PoDoFo/doc/PdfDocument.h"
#include "PoDoFo/doc/PdfElement.h"
#include "PoDoFo/doc/PdfEncodingObjectFactory.h"
#include "PoDoFo/doc/PdfExtGState.h"
#include "PoDoFo/doc/PdfField.h"
#include "PoDoFo/doc/PdfFileSpec.h"
#include "PoDoFo/doc/PdfFontCache.h"
#include "PoDoFo/doc/PdfFontCID.h"
#include "PoDoFo/doc/PdfFontConfigWrapper.h"
#include "PoDoFo/doc/PdfFontFactoryBase14Data.h"
#include "PoDoFo/doc/PdfFontFactory.h"
#include "PoDoFo/doc/PdfFont.h"
#include "PoDoFo/doc/PdfFontMetricsBase14.h"
#include "PoDoFo/doc/PdfFontMetricsFreetype.h"
#include "PoDoFo/doc/PdfFontMetrics.h"
#include "PoDoFo/doc/PdfFontMetricsObject.h"
#include "PoDoFo/doc/PdfFontSimple.h"
#include "PoDoFo/doc/PdfFontTrueType.h"
#include "PoDoFo/doc/PdfFontTTFSubset.h"
#include "PoDoFo/doc/PdfFontType1Base14.h"
#include "PoDoFo/doc/PdfFontType1.h"
#include "PoDoFo/doc/PdfFontType3.h"
#include "PoDoFo/doc/PdfFunction.h"
#include "PoDoFo/doc/PdfHintStream.h"
#include "PoDoFo/doc/PdfIdentityEncoding.h"
#include "PoDoFo/doc/PdfImage.h"
#include "PoDoFo/doc/PdfInfo.h"
#include "PoDoFo/doc/PdfMemDocument.h"
#include "PoDoFo/doc/PdfNamesTree.h"
#include "PoDoFo/doc/PdfOutlines.h"
#include "PoDoFo/doc/PdfPage.h"
#include "PoDoFo/doc/PdfPagesTreeCache.h"
#include "PoDoFo/doc/PdfPagesTree.h"
#include "PoDoFo/doc/PdfPainter.h"
#include "PoDoFo/doc/PdfPainterMM.h"
#include "PoDoFo/doc/PdfShadingPattern.h"
#include "PoDoFo/doc/PdfSignatureField.h"
#include "PoDoFo/doc/PdfSignOutputDevice.h"
#include "PoDoFo/doc/PdfStreamedDocument.h"
#include "PoDoFo/doc/PdfTable.h"
#include "PoDoFo/doc/PdfTilingPattern.h"
#include "PoDoFo/doc/PdfXObject.h"

namespace PoDoFo{

    typedef boost::shared_ptr<PoDoFo::PdfDataType> PdfDataTypeImpl;
    typedef boost::shared_ptr<PoDoFo::PdfObject> PdfObjectImpl;
    typedef boost::shared_ptr<PoDoFo::PdfCanvas> PdfCanvasImpl;
    typedef boost::shared_ptr<PoDoFo::PdfEncoding> PdfEncodingImpl;
    typedef boost::shared_ptr<PoDoFo::PdfSimpleEncoding> PdfSimpleEncodingImpl;
    typedef boost::shared_ptr<PoDoFo::PdfDocEncoding> PdfDocEncodingImpl;
    typedef boost::shared_ptr<PoDoFo::PdfWinAnsiEncoding> PdfWinAnsiEncodingImpl;
    typedef boost::shared_ptr<PoDoFo::PdfMacRomanEncoding> PdfMacRomanEncodingImpl;
    typedef boost::shared_ptr<PoDoFo::PdfMacExpertEncoding> PdfMacExpertEncodingImpl;
    typedef boost::shared_ptr<PoDoFo::PdfStandardEncoding> PdfStandardEncodingImpl;
    typedef boost::shared_ptr<PoDoFo::PdfSymbolEncoding> PdfSymbolEncodingImpl;
    typedef boost::shared_ptr<PoDoFo::PdfZapfDingbatsEncoding> PdfZapfDingbatsEncodingImpl;
    typedef boost::shared_ptr<PoDoFo::PdfWin1250Encoding> PdfWin1250EncodingImpl;
    typedef boost::shared_ptr<PoDoFo::PdfIso88592Encoding> PdfIso88592EncodingImpl;    
    typedef boost::shared_ptr<PoDoFo::PdfFileStream> PdfFileStreamImpl;
    typedef boost::shared_ptr<PoDoFo::PdfFilter> PdfFilterImpl;
    typedef boost::shared_ptr<PoDoFo::PdfInputDevice> PdfInputDeviceImpl;
    typedef boost::shared_ptr<PoDoFo::PdfInputStream> PdfInputStreamImpl;
    typedef boost::shared_ptr<PoDoFo::PdfFileInputStream> PdfFileInputStreamImpl;
    typedef boost::shared_ptr<PoDoFo::PdfMemoryInputStream> PdfMemoryInputStreamImpl;
    typedef boost::shared_ptr<PoDoFo::PdfDeviceInputStream> PdfDeviceInputStreamImpl;
    typedef boost::shared_ptr<PoDoFo::PdfMemStream> PdfMemStreamImpl;
    typedef boost::shared_ptr<PoDoFo::PdfOutputDevice> PdfOutputDeviceImpl;
    typedef boost::shared_ptr<PoDoFo::PdfOutputStream> PdfOutputStreamImpl;
    typedef boost::shared_ptr<PoDoFo::PdfFileOutputStream> PdfFileOutputStreamImpl;
    typedef boost::shared_ptr<PoDoFo::PdfMemoryOutputStream> PdfMemoryOutputStreamImpl;
    typedef boost::shared_ptr<PoDoFo::PdfDeviceOutputStream> PdfDeviceOutputStreamImpl;
    typedef boost::shared_ptr<PoDoFo::PdfBufferOutputStream> PdfBufferOutputStreamImpl;
    typedef boost::shared_ptr<PoDoFo::PdfParser> PdfParserImpl;
    typedef boost::shared_ptr<PoDoFo::PdfParserObject> PdfParserObjectImpl;
    typedef boost::shared_ptr<PoDoFo::PdfStream> PdfStreamImpl;
    typedef boost::shared_ptr<PoDoFo::PdfTokenizer> PdfTokenizerImpl;
    typedef boost::shared_ptr<PoDoFo::PdfVecObjects::Observer> ObserverImpl;
    typedef boost::shared_ptr<PoDoFo::PdfVecObjects::StreamFactory> StreamFactoryImpl;
    typedef boost::shared_ptr<PoDoFo::PdfAction> PdfActionImpl;
    typedef boost::shared_ptr<PoDoFo::PdfCMapEncoding> PdfCMapEncodingImpl;
    typedef boost::shared_ptr<PoDoFo::PdfDocument> PdfDocumentImpl;
    typedef boost::shared_ptr<PoDoFo::PdfFont> PdfFontImpl;
    typedef boost::shared_ptr<PoDoFo::PdfFontCID> PdfFontCIDImpl;
    typedef boost::shared_ptr<PoDoFo::PdfFontMetrics> PdfFontMetricsImpl;
    typedef boost::shared_ptr<PoDoFo::PdfFontMetricsFreetype> PdfFontMetricsFreetypeImpl;
    typedef boost::shared_ptr<PoDoFo::PdfFontMetricsObject> PdfFontMetricsObjectImpl;
    typedef boost::shared_ptr<PoDoFo::PdfFontSimple> PdfFontSimpleImpl;
    typedef boost::shared_ptr<PoDoFo::PdfFontType1> PdfFontType1Impl;
    typedef boost::shared_ptr<PoDoFo::PdfFontType1Base14> PdfFontType1Base14Impl;
    typedef boost::shared_ptr<PoDoFo::PdfMemDocument> PdfMemDocumentImpl;
    typedef boost::shared_ptr<PoDoFo::PdfPage> PdfPageImpl;
    typedef boost::shared_ptr<PoDoFo::PdfPagesTree> PdfPagesTreeImpl;
    typedef boost::shared_ptr<PoDoFo::PdfPagesTreeCache> PdfPagesTreeCacheImpl;
    typedef boost::shared_ptr<PoDoFo::PdfStreamedDocument> PdfStreamedDocumentImpl;
    typedef boost::shared_ptr<PoDoFo::PdfTableModel> PdfTableModelImpl;
    typedef boost::shared_ptr<PoDoFo::PdfTable> PdfTableImpl;
    typedef boost::shared_ptr<PoDoFo::PdfXObject> PdfXObjectImpl;
    
    class PdfEncryptImpl: public boost::shared_ptr<PoDoFo::PdfEncrypt>
    {
        public:
            PdfEncryptImpl() : boost::shared_ptr<PoDoFo::PdfEncrypt>(boost::make_shared<PoDoFo::PdfEncrypt>())
            {}        
            PdfEncryptImpl(PoDoFo::PdfEncrypt* pdf_encrypt) : boost::shared_ptr<PoDoFo::PdfEncrypt>(pdf_encrypt)
            {}
            PdfEncryptImpl(PoDoFo::PdfEncrypt pdf_encrypt) : boost::shared_ptr<PoDoFo::PdfEncrypt>(boost::make_shared<PoDoFo::PdfEncrypt>(pdf_encrypt))
            {}
            PdfEncryptImpl(const PoDoFo::PdfEncrypt* pdf_encrypt) : boost::shared_ptr<PoDoFo::PdfEncrypt>(pdf_encrypt)
            {}
        
        typedef PoDoFo::PdfEncrypt::EPdfKeyLength EPdfKeyLength;
        typedef PoDoFo::PdfEncrypt::EPdfPermissions EPdfPermissions;
        typedef PoDoFo::PdfEncrypt::EPdfEncryptAlgorithm EPdfEncryptAlgorithm;
    };    
}
