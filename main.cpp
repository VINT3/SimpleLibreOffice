#include "unowriter.h"


int main(int argc, char *argv[])
{
   
    UNOWriter uno;
    uno.createNewCompLO();

    //create first Heading
    uno.chooseStyle("Heading 2");
    uno.chooseAlign(com::sun::star::style::ParagraphAdjust::ParagraphAdjust_CENTER);
    uno.chooseFontName("Times New Roman");
    uno.chooseFontSize(28);
    uno.writeTextDoc("Толян Привет");

    //create table
    uno.createDocTable(4,4);
    uno.chooseFontSize(32);
    uno.setTableData("A1", "Title1");
    uno.setTableData("A2", 52);
    uno.setTableData("A3", 65.5);
    uno.setTableData("A4", 100.2);

    uno.breakPage();

    //create new heading
    uno.chooseStyle("Heading");
    uno.chooseAlign(com::sun::star::style::ParagraphAdjust::ParagraphAdjust_RIGHT);
    uno.chooseFontName("Ani");
    uno.chooseFontSize(64);
    uno.chooseFontWeight(com::sun::star::awt::FontWeight::BOLD);
    uno.writeTextDoc("Hello world");


    return 0;
}
