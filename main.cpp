#include "widget.h"
#include <QtXml>
#include <QApplication>



void traverseNode(const QDomNode& node, QLabel &lbl){
    QDomNode domNode = node.firstChild();
    while(!domNode.isNull()) {
        if(domNode.isElement()) {
            QDomElement domElement = domNode.toElement();
            if(!domElement.isNull()) {
                if (domElement.tagName() != "personbook"){
                    lbl.setText(lbl.text() + ' ' + domElement.tagName() + ' ' + domElement.text() + '\n');
                }
            }
        }
        traverseNode(domNode, lbl);
        domNode = domNode.nextSibling();

    }

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file(":/my.xml");

    QDomDocument domDoc;
    QLabel lbl;

    domDoc.setContent(&file);
    QDomElement domElement = domDoc.documentElement();
    traverseNode(domElement, lbl);


    lbl.setFont(QFont("Times",12));
    lbl.setGeometry(50,50,500,400);
    lbl.show();
    file.close();
    return a.exec();


}



