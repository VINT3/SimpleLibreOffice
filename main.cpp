#include "unowriter.h"


int main(int argc, char *argv[])
{
   
    UNOWriter uno;
    uno.createNewCompLO();
    uno.chooseStyle("Heading 1", ALIGN_LEFT);
    uno.writeTextDocument("Hello World\r", 0);

    uno.chooseStyle("Heading 2", ALIGN_RIGHT);
    uno.writeTextDocument("Hello World\r", 0);

    uno.chooseStyle("Heading 3", ALIGN_CENTER);
    uno.writeTextDocument("Hello World\r", 0);


    uno.createDocTable(4,4);
    uno.chooseStyle("A1","Heading 1", ALIGN_RIGHT);
    uno.setTableData("A1", "Title1");
    uno.setTableData("A2", 52);
    uno.setTableData("A3", 65.5);
    uno.setTableData("A4", 100.2);

    uno.chooseStyle("B1","Heading 1", ALIGN_RIGHT);
    uno.setTableData("B1", "Title2");
    uno.chooseStyle("B2","Heading 1", ALIGN_CENTER);
    uno.setTableData("B2", 52);
    uno.setTableData("B3", 65.5);
    uno.setTableData("B4", 100.2);

    uno.chooseStyle("C1","Heading 1", ALIGN_RIGHT);
    uno.setTableData("C1", "Title3");
    uno.setTableData("C2", 52);
    uno.setTableData("C3", 65.5);
    uno.setTableData("C4", 100.2);

    uno.chooseStyle("D1","Heading 1", ALIGN_RIGHT);
    uno.setTableData("D1", "Title4");
    uno.setTableData("D2", 52);
    uno.setTableData("D3", 65.5);
    uno.setTableData("D4", 100.2);


    uno.breakPage();

    uno.createDocTable(4,4);
    uno.setTableData("A1", "Title1");
    uno.setTableData("A2", 52);
    uno.setTableData("A3", 65.5);
    uno.setTableData("A4", 100.2);

    uno.setTableData("B1", "Title2");
    uno.setTableData("B2", 52);
    uno.setTableData("B3", 65.5);
    uno.setTableData("B4", 100.2);

    uno.setTableData("C1", "Title3");
    uno.setTableData("C2", 52);
    uno.setTableData("C3", 65.5);
    uno.setTableData("C4", 100.2);

    uno.setTableData("D1", "Title4");
    uno.setTableData("D2", 52);
    uno.setTableData("D3", 65.5);
    uno.setTableData("D4", 100.2);

    return 0;
}
