#include "unowriter.h"
#include <iostream>


int main(int argc, char *argv[])
{
    UNOWriter uno;
    uno.createNewDocument();
    uno.writeToTextDocument("TABLE");
    uno.createTableOnDocument(2,2);
    uno.setDataIntoCell("A1", "5.0");
    uno.setDataIntoCell("B1", "5");




//        std::string text = "EBAT";

//    Reference<XDesktop2> componentLoader;
//    Reference<XComponent> component;

//    Reference< XComponentContext > xContext( ::cppu::bootstrap() );
//    Reference< XMultiComponentFactory > xServiceManager(
//        xContext->getServiceManager() );
//    componentLoader = Desktop::create(xContext);

//    OUString sDocUrl;
//    osl::FileBase::getFileURLFromSystemPath(
//                OUString::createFromAscii("/home/tim/test1.odt"),sDocUrl);
//    component = componentLoader->loadComponentFromURL(
//                sDocUrl,
//                OUString::createFromAscii("_blank"),
//                0,
//                Sequence < ::com::sun::star::beans::PropertyValue >());
//    Reference< XTextDocument> textDocument(component, UNO_QUERY);

//    Reference <XText> xtext = textDocument->getText();
//    Reference <XTextCursor> cursor = xtext->createTextCursor();
//    xtext->insertString(cursor, OUString("bonjur"), false);
//    xtext->insertControlCharacter(cursor, com::sun::star::text::ControlCharacter::SOFT_HYPHEN, false);
//    xtext->insertString(cursor, OUString("hellou"), false);
//    xtext->insertControlCharacter(cursor, com::sun::star::text::ControlCharacter::PARAGRAPH_BREAK, false);







//    xtext->insertString(pageCursor,OUString(text.c_str(),
//                                        (sal_Int32)strlen(text.c_str()),
//                                        RTL_TEXTENCODING_UTF8 ),false);
////    cursor->goRight(4,0);
//    Reference <XPageCursor> page(cursor, UNO_QUERY);
//    page->jumpToEndOfPage();




//    UNOWriter uno;
//    uno.createNewCompLO();

    //create first Heading
//    uno.chooseStyle("Heading 2");
//    uno.chooseAlign(com::sun::star::style::ParagraphAdjust::ParagraphAdjust_CENTER);
//    uno.chooseFontName("Times New Roman");
//    uno.chooseFontSize(28);
//    uno.writeTextDoc("Толян Привет");

//    //create table
//    uno.createDocTable(4,4);
//    uno.setTableData("A1", "Title1");
//    uno.writeTextDoc("Толян Привет");





//    uno.setTableData("A2", 52);
//    uno.setTableData("A3", 65.5);
//    uno.setTableData("A4", 100.2);

//    uno.breakPage();

//    //create new heading
//    uno.chooseStyle("Heading");
//    uno.chooseAlign(com::sun::star::style::ParagraphAdjust::ParagraphAdjust_RIGHT);
//    uno.chooseFontName("Ani");
//    uno.chooseFontSize(64);
//    uno.chooseFontWeight(com::sun::star::awt::FontWeight::BOLD);
//    uno.writeTextDoc("Hello world");


//    uno.createDocTable(4,4);

////    uno.chooseStyle("A1","Heading 3");
//    uno.chooseStyle("B2","Heading 3");
////    uno.chooseStyle("C3","Heading 3");
////    uno.chooseStyle("D4","Heading 3");
////    uno.chooseFontName("Ani");

//    uno.setTableData("A1", "Title1");
//    uno.setTableData("B1", "Title2");
//    uno.setTableData("C1", "Title3");
//    uno.setTableData("D1", "Title4");
//    uno.setTableData("A2", 52);
//    uno.setTableData("A3", 65.5);
//    uno.setTableData("A4", 100.2);


    return 0;
}
