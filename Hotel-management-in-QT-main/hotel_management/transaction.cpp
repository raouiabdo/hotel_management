#include "transaction.h"
#include "ui_transaction.h"

transaction::transaction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::transaction)
{
    ui->setupUi(this);
    this->setFixedSize(320,180);

}
void transaction::readData()
{
    QSqlDatabase Database = QSqlDatabase::addDatabase("QSQLITE", "Data");
    Database.setDatabaseName("c:/cppbuzz_hotelmanagement.db");
    if(QFile::exists("c:/cppbuzz_hotelmanagement.db"))
        qDebug() << "DB file exist";
    else
        qDebug() << "DB file doesn't exists";

    if (!Database.open())
        qDebug() << Database.lastError().text();
    else
        qDebug() << "Database loaded successfull!";

    QSqlQuery query(Database);
    query.prepare("select * from transaction");

    if(!query.exec())
        qDebug() << query.lastError().text() << query.lastQuery();
    else
        qDebug() << "Update was successful "<< query.lastQuery();


    while(query.next())
    {

        this->ui->lstWidget->addItem(query.value(0).toString() +"************************"+ query.value(1).toString() +"****************"+ query.value(2).toString());
        qDebug() << query.value(0).toString() << " " << query.value(1).toString() << query.value(2).toString();
    }

    Database.close();
}
transaction::~transaction()
{
    delete ui;
}
