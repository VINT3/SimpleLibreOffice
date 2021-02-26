#include "unowriter.h"
#include <stdio.h>

UNOWriter::UNOWriter()
{
    try{
        //Create context object
        Reference< XComponentContext > xContext( ::cppu::bootstrap() );
        Reference< XMultiComponentFactory > xServiceManager(
            xContext->getServiceManager() );

        xComponentLoader = Desktop::create(xContext);
    }
    catch ( ::cppu::BootstrapException & e ){

        fprintf(stderr, "caught BootstrapException: %s\n",
                OUStringToOString( e.getMessage(), RTL_TEXTENCODING_ASCII_US ).getStr());
    }
}

UNOWriter::~UNOWriter()
{
//    xComponent->dispose();
}

void UNOWriter::createNewCompLO()
{
    xComponent = xComponentLoader->loadComponentFromURL(
                OUString::createFromAscii("private:factory/swriter"),
                OUString::createFromAscii("_blank"),
                0,
                Sequence < ::com::sun::star::beans::PropertyValue >());

    Reference< XTextDocument> xTextDoc(xComponent, UNO_QUERY);
    xDocument = xTextDoc;
    xText = xDocument->getText();
    xCursor = xText->createTextCursor();
    Reference< XMultiServiceFactory > MSF(xTextDoc,UNO_QUERY);
    oDocMSF = MSF;

}

void UNOWriter::openExisCompLO(std::string pathToFile)
{
    OUString sDocUrl;
    osl::FileBase::getFileURLFromSystemPath(
                OUString::createFromAscii(pathToFile.c_str()),sDocUrl);

    xComponent = xComponentLoader->loadComponentFromURL(
                sDocUrl,
                OUString::createFromAscii("_blank"),
                0,
                Sequence < ::com::sun::star::beans::PropertyValue >());

    Reference< XTextDocument> xTextDoc(xComponent, UNO_QUERY);
    xDocument = xTextDoc;
    xText = xDocument->getText();
    xCursor = xText->createTextCursor();
    Reference< XMultiServiceFactory > MSF(xTextDoc,UNO_QUERY);
    oDocMSF = MSF;

}

void UNOWriter::writeTextDoc(std::string text, int pos)
{
    xText = xDocument->getText();
    xCursor = xText->createTextCursor();
    if(pos >= 0)
        xCursor->goRight(pos,0);
    xCursor->gotoEnd(0);
    xText->insertString(xCursor,OUString(text.c_str(),
                                         (sal_Int32)strlen(text.c_str()),
                                         RTL_TEXTENCODING_UTF8 ),false);
}

void UNOWriter::createDocTable(int row, int count)
{
    Reference< XTextTable > xTable(oDocMSF->createInstance(
                                       OUString::createFromAscii("com.sun.star.text.TextTable")), UNO_QUERY);
    xDocTable = xTable;
    xDocTable->initialize(row, count);
    xTextRange = xText->getEnd();

    Reference< XTextContent > xTextContent(xDocTable, UNO_QUERY);
    xText->insertTextContent(xTextRange, xTextContent,(unsigned char) 0);
}

void UNOWriter::setTableData(std::string position, double data)
{
    Reference< XCell > xCell = xDocTable->getCellByName(OUString::createFromAscii(position.c_str()));
    xCell->setValue(data);

}

void UNOWriter::setTableData(std::string position, std::string data)
{
    Reference< XCell > xCell = xDocTable->getCellByName(OUString::createFromAscii(position.c_str()));
    xText = Reference< XText >(xCell,UNO_QUERY);
    xCursor = xText->createTextCursor();
    xCursor->setString(OUString::createFromAscii(data.c_str()));
}
//style page
void UNOWriter::chooseStyle(std::string styleName)
{
    xText = xDocument->getText();
    xCursor = xText->createTextCursor();
    xCursor->gotoEnd(0);
    Reference< XPropertySet> xCProps( xCursor,UNO_QUERY);
    xCProps->setPropertyValue("ParaStyleName", ::Any(OUString::createFromAscii( styleName.c_str())));

}

void UNOWriter::chooseAlign(int align)
{
    Reference< XPropertySet> xCProps( xCursor,UNO_QUERY);
    xCProps->setPropertyValue("ParaAdjust",::Any(align));
}
//style sheet
void UNOWriter::chooseStyle(std::string position, std::string styleName)
{    
    Reference< XCell > xCell = xDocTable->getCellByName(OUString::createFromAscii(position.c_str()));
    xText = Reference< XText >(xCell,UNO_QUERY);
    xCursor = xText->createTextCursor();
    Reference< XPropertySet> xCProps( xCursor,UNO_QUERY);
    xCProps->setPropertyValue("ParaStyleName", ::Any(OUString::createFromAscii( styleName.c_str())));    
}

void UNOWriter::chooseFontName(std::string fontName)
{
    Reference< XPropertySet > xCProps(xCursor,UNO_QUERY);
    xCProps->setPropertyValue("CharFontName",::Any(OUString::createFromAscii(fontName.c_str())));
}

void UNOWriter::chooseFontSize(float fontSize)
{
    Reference< XPropertySet > xCProps(xCursor,UNO_QUERY);
    xCProps->setPropertyValue("CharHeight",::Any(fontSize));

}

void UNOWriter::chooseFontWeight(float fontWeight)
{
    Reference< XPropertySet > xCProps(xCursor,UNO_QUERY);
    xCProps->setPropertyValue("CharWeight",::Any(fontWeight));
}

void UNOWriter::breakPage()
{
    xText = xDocument->getText();
    xCursor = xText->createTextCursor();
    xCursor->gotoEnd(0);
    Reference< XPropertySet > xCProps( xCursor,UNO_QUERY);
    xCProps->setPropertyValue("BreakType", ::Any(com::sun::star::style::BreakType::BreakType_PAGE_BEFORE));
}

