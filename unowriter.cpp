#include "unowriter.h"


UNOWriter::UNOWriter()
{
    try{
        Reference<XComponentContext> xContext( ::cppu::bootstrap() );
        Reference<XMultiComponentFactory> xServiceManager(
            xContext->getServiceManager() );
        xComponentLoader = Desktop::create(xContext);
    }
    catch ( ::cppu::BootstrapException & e ){

        fprintf(stderr, "caught BootstrapException: %s\n",
                OUStringToOString( e.getMessage(), RTL_TEXTENCODING_UTF8 ).getStr());
    }
}

UNOWriter::~UNOWriter()
{

}

void UNOWriter::createNewDocument()
{
    Reference<XComponent> xComponent = xComponentLoader->loadComponentFromURL(
                OUString::createFromAscii("private:factory/swriter"),
                OUString::createFromAscii("_blank"),
                0,
                Sequence < ::com::sun::star::beans::PropertyValue >());

    Reference<XTextDocument> xTextDoc(xComponent, UNO_QUERY);
    xDocument = xTextDoc;
}

void UNOWriter::openExistingDocument(std::string pathToFile)
{
    OUString sDocUrl;
    osl::FileBase::getFileURLFromSystemPath(
                OUString::createFromAscii(pathToFile.c_str()),sDocUrl);

    Reference<XComponent> xComponent =xComponentLoader->loadComponentFromURL(
                sDocUrl,
                OUString::createFromAscii("_blank"),
                0,
                Sequence < ::com::sun::star::beans::PropertyValue >());

    Reference<XTextDocument> xTextDoc(xComponent, UNO_QUERY);
    xDocument = xTextDoc;
//    Reference< XMultiServiceFactory > MSF(xTextDoc,UNO_QUERY);
//    oDocMSF = MSF;

}

void UNOWriter::writeToTextDocument(std::string text)
{
    Reference<XText> xText = getDocument()->getText();
    Reference<XTextCursor> xCursor = xText->createTextCursor();
    xCursor->gotoEnd(0);
    xText->insertString(xCursor,OUString(text.c_str(),
                                         (sal_Int32)strlen(text.c_str()),
                                         RTL_TEXTENCODING_UTF8 ),false);
}

void UNOWriter::createTableOnDocument(int row, int count)
{
    Reference< XMultiServiceFactory > oDocMSF(getDocument(),UNO_QUERY);
    Reference<XTextTable> Table(oDocMSF->createInstance(
                                       OUString::createFromAscii("com.sun.star.text.TextTable")), UNO_QUERY);
    xTable = Table;
    xTable->initialize(row, count);
    Reference<XText> Text = getDocument()->getText();
    Reference<XTextRange> TextRange = Text->getEnd();
    Reference<XTextContent> TextContent(xTable, UNO_QUERY);
    Text->insertTextContent(TextRange, TextContent,(unsigned char) 0);
}

void UNOWriter::setDataIntoCell(std::string position, std::string data)
{
    Reference<XCell> Cell = getTable()->getCellByName(OUString::createFromAscii(position.c_str()));
    Reference<XText> Text(Cell, UNO_QUERY);
    Reference<XTextCursor> Cursor = Text->createTextCursor();
    Cursor->setString(OUString::createFromAscii(data.c_str()));
}

void UNOWriter::breakPage()
{
    Reference<XText> Text = getDocument()->getText();
    Reference<XTextCursor> Cursor = Text->createTextCursor();
    Cursor->gotoEnd(0);
    Reference< XPropertySet > xCProps(Cursor, UNO_QUERY);
    xCProps->setPropertyValue("BreakType", ::Any(com::sun::star::style::BreakType::BreakType_PAGE_BEFORE));
}

Reference<XTextDocument> UNOWriter::getDocument() const
{
    return xDocument;
}

Reference<XTextTable> UNOWriter::getTable() const
{
    return xTable;
}


//style page
//void UNOWriter::chooseStyle(std::string styleName)
//{
//    xText = xDocument->getText();
//    xCursor = xText->createTextCursor();
//    xCursor->gotoEnd(0);
//    Reference< XPropertySet> xCProps( xCursor,UNO_QUERY);
//    xCProps->setPropertyValue("ParaStyleName", ::Any(OUString::createFromAscii( styleName.c_str())));

//}

//void UNOWriter::chooseAlign(int align)
//{
//    Reference< XPropertySet> xCProps( xCursor,UNO_QUERY);
//    xCProps->setPropertyValue("ParaAdjust",::Any(align));
//}
////style sheet
//void UNOWriter::chooseStyle(std::string position, std::string styleName)
//{
//    Reference< XCell > xCell = xDocTable->getCellByName(OUString::createFromAscii(position.c_str()));
//    xText = Reference< XText >(xCell,UNO_QUERY);
//    xCursor = xText->createTextCursor();
//    Reference< XPropertySet> xCProps( xCursor,UNO_QUERY);
//    xCProps->setPropertyValue("ParaStyleName", ::Any(OUString::createFromAscii( styleName.c_str())));
//}

//void UNOWriter::chooseFontName(std::string fontName)
//{
//    Reference< XPropertySet > xCProps(xCursor,UNO_QUERY);
//    xCProps->setPropertyValue("CharFontName",::Any(OUString::createFromAscii(fontName.c_str())));
//}

//void UNOWriter::chooseFontSize(float fontSize)
//{
//    Reference< XPropertySet > xCProps(xCursor,UNO_QUERY);
//    xCProps->setPropertyValue("CharHeight",::Any(fontSize));

//}

//void UNOWriter::chooseFontWeight(float fontWeight)
//{
//    Reference< XPropertySet > xCProps(xCursor,UNO_QUERY);
//    xCProps->setPropertyValue("CharWeight",::Any(fontWeight));
//}




