#ifndef LIBREOFFICE_H
#define LIBREOFFICE_H

#include <sal/main.h>
#include <osl/file.hxx>
#include <cppuhelper/bootstrap.hxx>
#include <com/sun/star/bridge/XUnoUrlResolver.hpp>
#include <com/sun/star/frame/Desktop.hpp>
#include <com/sun/star/frame/XComponentLoader.hpp>
#include <com/sun/star/lang/XMultiComponentFactory.hpp>
#include <com/sun/star/text/XTextDocument.hpp>
#include <com/sun/star/text/XText.hpp>
#include <com/sun/star/text/XTextTable.hpp>
#include <com/sun/star/lang/XMultiServiceFactory.hpp>
#include <com/sun/star/beans/XPropertySet.hpp>
#include <com/sun/star/style/XStyle.hpp>
#include <com/sun/star/style/BreakType.hpp>
#include <com/sun/star/style/ParagraphAdjust.hpp>
#include <com/sun/star/awt/FontWeight.hpp>
#include <com/sun/star/text/XPageCursor.hpp>
#include <com/sun/star/text/ControlCharacter.hpp>

#include <com/sun/star/text/XTextField.hpp>
#include <com/sun/star/text/XWordCursor.hpp>

using namespace com::sun::star::uno;
using namespace com::sun::star::lang;
using namespace com::sun::star::frame;
using namespace com::sun::star::text;
using namespace com::sun::star::table;
using namespace com::sun::star::beans;
using namespace com::sun::star::style;
using namespace com::sun::star::awt;

using ::rtl::OUString;
using ::rtl::OUStringToOString;

#endif // LIBREOFFICE_H
