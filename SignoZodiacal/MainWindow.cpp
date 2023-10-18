#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Signos zodiacales");

    SignoZodiacal aries = {"Aries","21 de marzo - 19 de abril","Lectura de Aries es pendejo :v"};
    SignoZodiacal tauro = {"Tauro","20 de abril - 20 de mayo","Lectura de Tauro..."};
    SignoZodiacal geminis = {"Geminis","21 de abril - 20 de junio","Lectura de Geminis..."};
    SignoZodiacal cancer = {"Cancer","21 de junio - 22 de julio","Lectura de Cancer..."};
    SignoZodiacal leo = {"Leo","23 de abril - 22 de agosto","Lectura de Leo..."};
    SignoZodiacal virgo = {"Virgo","23 de agosto - 22 de septiembre","Lectura de Virgo..."};
    SignoZodiacal libra = {"Libra","23 de septiembre - 22 de octubre","Rompa con los perjuicios del pasado y dé vuelta la página. "
                                        "Será el momento para focalizarse en su futuro, ya que contará con energía muy positiva. "
                                        "Amor: Esta tarde, postergue todos los compromisos profesionales y resérvese todo su tiempo "
                                        "para compartirlo junto a su alma gemela."};
    SignoZodiacal escorpio = {"Escorpio","23 de octubre - 21 de noviembre","Lectura de Escorpio..."};
    SignoZodiacal sagitario = {"Sagitario","22 de noviembre - 21 de diciembre","Lectura de Sagitario..."};
    SignoZodiacal capricornio = {"Capricornio","22 de diciembre - 19 de enero","Lectura de Capricornio..."};
    SignoZodiacal acuario = {"Acuario","20 de enero - 18 de febrero","Lectura de Acuario..."};
    SignoZodiacal piscis = {"Piscis","18 de febrero - 20 de marzo","Lectura de Piscis..."};

    signozodiacal << aries << tauro << geminis << cancer << leo << virgo << libra << escorpio << sagitario << capricornio << acuario << piscis;

    for (const SignoZodiacal& signo : signozodiacal){
        ui->zodiacListWidget->addItem(signo.signo);
    }
    connect(ui->zodiacListWidget, &QListWidget::itemClicked, this, &MainWindow::onSelectZodiac);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSelectZodiac(QListWidgetItem* item)
{
    for(const SignoZodiacal& signo: signozodiacal){
        if(item->text() == signo.signo){
            ui->zodiacInfoTextEdit->setText(QString("Meses: %1\nLectura: %2").arg(signo.meses, signo.texto));
            break;
        }
    }
}

