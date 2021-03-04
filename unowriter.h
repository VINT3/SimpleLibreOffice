//https://wiki.openoffice.org/wiki/Writer/API/Overview

#ifndef UNOWRITER_H
#define UNOWRITER_H

#include "libreoffice.hxx"
using namespace std;

class UNOWriter
{
private:
    Reference<XDesktop2> xComponentLoader;
    Reference<XTextDocument> xDocument;
    Reference<XTextTable> xTable;

public:
    UNOWriter();
    ~UNOWriter();

    void createNewDocument();
    void openExistingDocument(string pathToFile);
    void writeToTextDocument(string text);
    void createTableOnDocument(int row, int count);
    void setDataIntoCell(string position, string data);
    void breakPage();
    Reference<XTextDocument> getDocument() const;
    Reference<XTextTable> getTable() const;

//    void chooseStyle(string styleName);
//    void chooseStyle(string position, string styleName);
//    void chooseFontName(std::string fontName);
//    void chooseFontSize(float fontSize);
//    void chooseFontWeight(float fontWeight);

//    void chooseAlign(int align);

};



#endif // UNOWRITER_H
