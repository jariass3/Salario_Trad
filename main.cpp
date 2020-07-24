#include "principal.h"

#include <QApplication>

#include <QTranslator>
#include <QInputDialog>
#include <QLocale>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

         QTranslator traducir;
      // Solicito al usuario que seleccione un idioma del programa
         QStringList idiomas;
         idiomas << "Italiano" << "Portuguese" << "Turco";
         QString idiomaSelec = QInputDialog::getItem(NULL,
                                    "Idioma",
                                    "Seleccione un idioma",
                                    idiomas);

       // Dependiendo del idioma que elija se cargara el archivo de traducción (.qm)
         if(idiomaSelec == "Italiano"){
             traducir.load(":/Salario_Trad_it_IT.qm");
         }else if( idiomaSelec == "Portuguese"){
             traducir.load(":/Salario_Trad_pt_BR.qm");
         }else if( idiomaSelec == "Turco"){
             traducir.load(":/Salario_Trad_tr_TR.qm");
         }
        // Si es diferente de español, se instala la traducción en la aplicación
             if (idiomaSelec != "Español"){
                 a.installTranslator(&traducir);
             }


    Principal w;
    w.show();
    return a.exec();
}
